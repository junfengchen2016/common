#pragma once

#include <string>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		namespace IO
		{

class Path
{
public:
	static string GetDirectoryName(string path);
	static string GetExtension(string path);
	static string GetFileName(string path);
	static string GetFileNameWithoutExtension(string path);
	static string _GetTempFileName();
};

		}
	}
}