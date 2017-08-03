#include "system.string.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

#include <stdarg.h>

namespace chenjunfeng
{
	namespace System
	{
		vector<string> String::Split(string& str, vector<char>& separator, StringSplitOptions options)
		{
			string string_separator;
			for (int i = 0; i < separator.size(); i++) string_separator += separator[i];

			vector<string> result;
			split(result, str, is_any_of(string_separator));

			if (options == StringSplitOptions::StringSplitOptions_None) return result;
			else
			{
				vector<string> ret;
				for (int i = 0; i < result.size(); i++)
				{
					string& result_item = result[i];
					if (result_item != "") ret.push_back(result_item);
				}
				return ret;
			}
		}

		std::string String::format(const char *fmt, ...)
		{
			std::string strResult = "";
			if (NULL != fmt)
			{
				va_list marker = NULL;
				va_start(marker, fmt);                            //��ʼ���������� 
				size_t nLength = _vscprintf(fmt, marker) + 1;    //��ȡ��ʽ���ַ�������
				std::vector<char> vBuffer(nLength, '\0');        //�������ڴ洢��ʽ���ַ������ַ�����
				int nWritten = _vsnprintf_s(&vBuffer[0], vBuffer.size(), nLength, fmt, marker);
				if (nWritten>0)
				{
					strResult = &vBuffer[0];
				}
				va_end(marker);                                    //���ñ�������
			}
			return strResult;
		}

		//�ַ�����ʽ������
		std::wstring String::format(const wchar_t *fmt, ...)
		{
			std::wstring strResult = L"";
			if (NULL != fmt)
			{
				va_list marker = NULL;
				va_start(marker, fmt);                            //��ʼ����������
				size_t nLength = _vscwprintf(fmt, marker) + 1;    //��ȡ��ʽ���ַ�������
				std::vector<wchar_t> vBuffer(nLength, L'\0');    //�������ڴ洢��ʽ���ַ������ַ�����
				int nWritten = _vsnwprintf_s(&vBuffer[0], vBuffer.size(), nLength, fmt, marker);
				if (nWritten > 0)
				{
					strResult = &vBuffer[0];
				}
				va_end(marker);                                    //���ñ�������
			}
			return strResult;
		}
	}
}