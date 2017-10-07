#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		namespace Windows
		{
			namespace Forms
			{
				class Screen
				{
				public:
					cv::Rect Bounds;
					bool Primary;
				public:
					static vector<Screen> AllScreens();
					static Screen PrimaryScreen();
					static cv::Mat CopyFromScreen(int sourceX, int sourceY, cv::Size blockRegionSize);
				};
			}
		}
	}
}