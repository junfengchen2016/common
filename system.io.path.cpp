#include "path.h"

namespace chenjunfeng
{
	namespace System
	{
		namespace IO
		{
string Path::GetDirectoryName(string path)
{
	char sep = '/';

#ifdef _WIN32
	sep = '\\';
#endif

	size_t i = path.rfind(sep, path.length());
	if (i != string::npos)
	{
		string fn = (path.substr(0, i + 1));
		return fn;
	}
	else
		return "";

}

string Path::GetExtension(string path)
{
	string fn = GetFileName(path);

	char sepExt = '.';

	size_t i = fn.rfind(sepExt, fn.length());
	if (i != string::npos) 
		return fn.substr(i, fn.length() - i);
	else
		return fn;
}

string Path::GetFileName(string path)
{
	char sep = '/';

#ifdef _WIN32
	sep = '\\';
#endif

	size_t i = path.rfind(sep, path.length());
	if (i != string::npos) 
	{
		string fn = (path.substr(i + 1, path.length() - i));
		return fn;
	}
	else
		return "";
}

string Path::GetFileNameWithoutExtension(string path)
{
	string fn = GetFileName(path);

	char sepExt = '.';

	size_t i = fn.rfind(sepExt, fn.length());
	if (i != string::npos) 
		return fn.substr(0, i);
	else
		return fn;
}

		}
	}
}