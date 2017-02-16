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

class File
{
public:
	static void Delete(string path);
	static bool Exists(string path);
	static void Copy(string sourceFileName, string destFileName, bool overwrite);
	static vector<unsigned char> ReadAllBytes(string path);
	static string ReadAllText(string path);
	static void WriteAllBytes(string path, vector<unsigned char>& bytes);
	static void WriteAllText(string path, string contents);
};

		}
	}
}