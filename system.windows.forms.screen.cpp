#include "system.windows.forms.screen.h"

#include <Windows.h>

namespace chenjunfeng
{
	namespace System
	{
		namespace Windows
		{
			namespace Forms
			{
				// http://charmvi.blog.163.com/blog/static/1288080392011102195649554/
				// ??? 返回值似乎无效
				static BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor,
					HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
				{
					vector<Screen>* pScreens = (vector<Screen>*)dwData;
					//static BOOL first = TRUE;   //标志

													//保存显示器信息
					MONITORINFO monitorinfo;
					monitorinfo.cbSize = sizeof(MONITORINFO);

					//获得显示器信息，将信息保存到monitorinfo中
					GetMonitorInfo(hMonitor, &monitorinfo);

					//若检测到主屏
					if (monitorinfo.dwFlags == MONITORINFOF_PRIMARY)
					{
						//if (first)  //第一次检测到主屏
						{
							//first = FALSE;
//							numScreen = 1;

							//将显示器的分辨率信息保存到rect
							Screen screen;
							screen.Bounds = cv::Rect(monitorinfo.rcMonitor.left, monitorinfo.rcMonitor.top, monitorinfo.rcMonitor.right - monitorinfo.rcMonitor.left, monitorinfo.rcMonitor.bottom - monitorinfo.rcMonitor.top);
							screen.Primary = true;
							pScreens->push_back(screen);
							return TRUE;

						}
						//else //第二次检测到主屏,说明所有的监视器都已经检测了一遍，故可以停止检测了
						//{
						//	first = TRUE;    //标志复位
						//	return FALSE;    //结束检测
						//}
					}
					else
					{
						//rect[numScreen] = monitorinfo.rcMonitor;
						//numScreen++;
						Screen screen;
						screen.Bounds = cv::Rect(monitorinfo.rcMonitor.left, monitorinfo.rcMonitor.top, monitorinfo.rcMonitor.right - monitorinfo.rcMonitor.left, monitorinfo.rcMonitor.bottom - monitorinfo.rcMonitor.top);
						screen.Primary = false;
						pScreens->push_back(screen);
						return TRUE;
					}

				}

				vector<Screen> Screen::AllScreens()
				{
					vector<Screen> ret;
					EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)(&ret));

					return ret;
				}

				Screen Screen::PrimaryScreen()
				{
					Screen ret;
					vector<Screen> allscreens = AllScreens();
					for (int i = 0; i < allscreens.size(); i++)
					{
						Screen& screen = allscreens[i];
						if (screen.Primary == true)
						{
							ret = screen;
						}
					}

					return ret;
				}

				cv::Mat Screen::CopyFromScreen(int sourceX, int sourceY, cv::Size blockRegionSize)
				{
					cv::Mat mat_desktop;

					HWND hwnd;
					hwnd = GetDesktopWindow();
					HDC hwindowDC, hwindowCompatibleDC;
					int height, width, srcheight, srcwidth;
					HBITMAP hbwindow;
					BITMAPINFOHEADER  bi;

					hwindowDC = GetDC(hwnd);
					hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
					SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

					mat_desktop.create(blockRegionSize, CV_8UC4);

					// create a bitmap
					hbwindow = CreateCompatibleBitmap(hwindowDC, blockRegionSize.width, blockRegionSize.height);
					bi.biSize = sizeof(BITMAPINFOHEADER);
					bi.biWidth = blockRegionSize.width;
					bi.biHeight = -blockRegionSize.height;  //this is the line that makes it draw upside down or not
					bi.biPlanes = 1;
					bi.biBitCount = 32;
					bi.biCompression = BI_RGB;
					bi.biSizeImage = 0;
					bi.biXPelsPerMeter = 0;
					bi.biYPelsPerMeter = 0;
					bi.biClrUsed = 0;
					bi.biClrImportant = 0;

					// use the previously created device context with the bitmap
					SelectObject(hwindowCompatibleDC, hbwindow);
					// copy from the window device context to the bitmap device context
					StretchBlt(hwindowCompatibleDC, 0, 0, blockRegionSize.width, blockRegionSize.height, hwindowDC, sourceX, sourceY, blockRegionSize.width, blockRegionSize.height, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
					GetDIBits(hwindowCompatibleDC, hbwindow, 0, blockRegionSize.height, mat_desktop.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

					DeleteObject(hbwindow); DeleteDC(hwindowCompatibleDC); ReleaseDC(hwnd, hwindowDC);

					return mat_desktop;
				}
			}
		}
	}
}