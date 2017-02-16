#include "system.text.encoding.h"

namespace chenjunfeng
{
	namespace System
	{
		namespace Text
		{

#ifdef WIN32
 	          
			//namespace Encoding
			//{

wstring Encoding::GetString(string bytes)
{
	setlocale(LC_ALL, "chs"); 
	const char* _Source = bytes.c_str();
	size_t _Dsize = bytes.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	int nret = mbstowcs(_Dest,_Source,_Dsize);
	wstring result = _Dest;
	delete[] _Dest;
	setlocale(LC_ALL, "C");

	return result;
}

string Encoding::GetBytes(wstring s)
{
	setlocale(LC_ALL, "chs"); 
	const wchar_t* _Source = s.c_str();
	size_t _Dsize = 2 * s.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest,0,_Dsize);
	wcstombs(_Dest,_Source, _Dsize);
	string result = _Dest;
	delete[] _Dest;
	setlocale(LC_ALL, "C");

	return result;
}

			//}
#endif

		}
	}
}