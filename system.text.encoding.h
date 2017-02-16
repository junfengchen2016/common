#pragma once

#include <string>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		namespace Text
		{

class Encoding
{
public:
	static Encoding Default;
public:
	wstring GetString(string bytes);
	string GetBytes(wstring s);
};


class UTF8Encoding : Encoding
{
public:
	wstring GetString(string bytes);
	string GetBytes(wstring s);
};



//			namespace Encoding
//			{
//class Default
//{
//public:
//	wstring GetString(string bytes);
//	string GetBytes(wstring s);
//};
//			}
		}
	}
}