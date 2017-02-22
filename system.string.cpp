#include "system.string.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

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
	}
}