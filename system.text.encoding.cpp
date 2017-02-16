#include "system.text.encoding.h"

namespace chenjunfeng
{
	namespace System
	{
		namespace Text
		{


Encoding Encoding::Default;

wstring UTF8Encoding::GetString(string bytes)
{
	wstring ret;
	unsigned char*p = (unsigned char*)bytes.data();
	while(*p)
	{
		wchar_t t = 0;
		if(((*p) & 0xf0) == 0xe0)
		{
			t = (((*p) & 0xf) << 12) | (((*(p + 1)) & 0x3f) << 6) | ((*(p + 2)) & 0x3f); 
			ret += t;
			p += 3;
		}
		else if(((*p) & 0xe0) == 0xc0)
		{
			t = (((*p) & 0x1f) << 6) | ((*(p + 1)) & 0x3f); 
			ret += t;
			p += 2;
		}
		else
		{
			t = (*p) & 0x7f; 
			ret += t;
			p ++;
		}
	}

	return ret;
}

string UTF8Encoding::GetBytes(wstring s)
{
	string ret;

	for(int i = 0; i < (int)(s.length()); i++)
	{
		wchar_t c = s[i];
		if (c < 0x80)
		{
			ret += (char)c;
		}
		else if (c < 0x800)
		{
			ret += (char)(0xC0 | c >> 6);
			ret += (char)(0x80 | c & 0x3F);
		}
		else if (c < 0x10000)
		{
			ret += (char)(0xE0 | c >> 12);
			ret += (char)(0x80 | c >> 6 & 0x3F);
			ret += (char)(0x80 | c & 0x3F);
		}
		else if (c < 0x200000)
		{
			ret += (char)(0xF0 | c >> 18);
			ret += (char)(0x80 | c >> 12 & 0x3F);
			ret += (char)(0x80 | c >> 6 & 0x3F);
			ret += (char)(0x80 | c & 0x3F);
		}
	}

	return ret;
}
		}
	}
}