#include "system.convert.h"

namespace chenjunfeng
{
	namespace System
	{
		static unsigned char encode(int value)
		{
			value = value & 0x3f;

			if (value < 26)
				return value + 'A';
			if (value < 52)
				return (value - 26) + 'a';
			if (value < 62)
				return (value - 52) + '0';
			if (value < 63)
				return '+';
			return '/';
		}

		static int decode(unsigned char ch)
		{
			if (ch >= 'A' && ch <= 'Z')
				return ch - 'A';
			if (ch >= 'a' && ch <= 'z')
				return (ch - 'a') + 26;
			if (ch >= '0' && ch <= '9')
				return (ch - '0') + 52;
			if (ch == '+')
				return 62;
			if (ch == '/')
				return 63;
			/* would never reach here! */
			return 0;
		}

		string Convert::ToBase64String(vector<unsigned char>& inArray)
		{
			string ret;

			size_t i, j, padding, value;

			for (i = j = 0; i < inArray.size();) {
				padding = 0;

				value = inArray[i++] << 16; /* fetch first byte */

				if (i < inArray.size()) /* fetch second byte */
					value |= inArray[i++] << 8;
				else
					++padding;

				if (i < inArray.size()) /* fetch third byte */
					value |= inArray[i++];
				else
					++padding;

				ret += encode(value >> 18);
				ret += encode(value >> 12);

				if (padding < 2)
					ret += encode(value >> 6);
				else
					ret += '=';

				if (padding < 1)
					ret += encode(value);
				else
					ret += '=';
			}

			return ret;
		}

		static bool checkbase64(std::string const &str)
		{
			size_t len = str.length();

			if (0 != len % 4)
				return false;

			bool find_equal = false;
			for (size_t i = 0; i != len; ++i) {
				if (find_equal && '=' != str[i])
					return false;
				if ('=' == str[i]) {
					find_equal = true;
				}
				else {
					if (str[i] >= 'A' && str[i] <= 'Z')
						continue;
					if (str[i] >= 'a' && str[i] <= 'z')
						continue;
					if (str[i] >= '0' && str[i] <= '9')
						continue;
					if (str[i] == '+' || str[i] == '/')
						continue;
					return false;
				}
			}

			return true;
		}

		vector<unsigned char> Convert::FromBase64String(string& s)
		{
			vector<unsigned char> ret;

			int value, padding = 0;
			size_t len = s.length();
			unsigned char *buffer = (unsigned char*)s.c_str();
			unsigned char *ptr;

			if (!checkbase64(s)) return ret;

			int to_length = (s.length() + 3) / 4 * 3;
			ret.reserve(to_length);

			for (size_t i = 0; i != len; i += 4) {
				ptr = buffer + i;

				value = decode(ptr[0]) << 18;
				value |= decode(ptr[1]) << 12;

				if ('=' == ptr[2])
					++padding;
				else
					value |= decode(ptr[2]) << 6;

				if ('=' == ptr[3])
					++padding;
				else
					value |= decode(ptr[3]);

				ret.push_back(value >> 16);

				if (padding < 2)
					ret.push_back(value >> 8);

				if (padding < 1)
					ret.push_back(value);
			}

			return ret;
		}
	}
}