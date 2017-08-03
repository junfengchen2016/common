#include <string>
#include <vector>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		enum StringSplitOptions
		{
			StringSplitOptions_None = 0,
			StringSplitOptions_RemoveEmptyEntries = 1
		};

		class String
		{
		public:
			static vector<string> Split(string& str, vector<char>& separator, StringSplitOptions options = StringSplitOptions_None);
			static std::string format(const char *fmt, ...);
			static std::wstring format(const wchar_t *fmt, ...);
		};
	}
}