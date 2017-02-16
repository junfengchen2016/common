#include "system.io.file.h"

#include <io.h>
#include <assert.h>

#include <algorithm>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		namespace IO
		{

void File::Delete(string path)
{
	remove(path.data());
}

bool File::Exists(string path)
{
	return (_access(path.data(), 0) == 0) ? true : false;
}

void File::Copy(string sourceFileName, string destFileName, bool overwrite)
{
	bool exists_src = File::Exists(sourceFileName);
	if (!exists_src) return;

	bool exist_dst = File::Exists(destFileName);
	if (!overwrite && exist_dst) return;

	FILE *fp_src = fopen(sourceFileName.c_str(), "rb");
	FILE *fp_dst = fopen(destFileName.c_str(), "wb");

	vector<unsigned char> buf(32768);
	fseek(fp_src, 0, SEEK_END);
	int length = ftell(fp_src);
	fseek(fp_src, 0, SEEK_SET);
	int count = min(32768, length);

	while (count != 0)
	{
		fread(buf.data(), 0, count, fp_src);
		fwrite(buf.data(), 0, count, fp_dst);
		length -= count;
		count = min(32768, length);
	}

	fclose(fp_src);
	fclose(fp_dst);

}

vector<unsigned char> File::ReadAllBytes(string path)
{
	vector<unsigned char> ret;
	if (!File::Exists) return ret;

	FILE *fp = fopen(path.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	ret.resize(len);
	fread(ret.data(), 1, len, fp);
	fclose(fp);

	return ret;
}	

void File::WriteAllBytes(string path, vector<unsigned char>& bytes)
{
	FILE *fp = fopen(path.c_str(), "wb");
	fwrite(bytes.data(), 1, bytes.size(), fp);
	fclose(fp);
}

string File::ReadAllText(string pathname)
{
	std::string ret = "";
	FILE *fp = fopen(pathname.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	ret = std::string(length, 0);
	fread((void*)ret.data(), 1, length, fp);
	fclose(fp);

	return ret;
}

void File::WriteAllText(string pathname, string contents)
{
	FILE *fp = fopen(pathname.c_str(), "wb");
	fprintf(fp, contents.c_str());
	fclose(fp);
}
		}
	}
}