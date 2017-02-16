#pragma once

#include <string>
#include <vector>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		namespace IO
		{
			enum SearchOption
			{
				SearchOption_TopDirectoryOnly = 0,
				SearchOption_AllDirectories = 1
			};

			class Directory
			{
			public:
				static vector<string> GetFiles(string path, string searchPattern, SearchOption searchOption = SearchOption_TopDirectoryOnly);
				static void _CreateDirectory(string path);
				static void Delete(string path, bool recursive = false);
			};

		}
	}
}