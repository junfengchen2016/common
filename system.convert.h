#pragma once

#include <vector>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{
		class Convert
		{
		public:
			//
			// 摘要:
			//     将指定的字符串（它将二进制数据编码为 Base64 数字）转换为等效的 8 位无符号整数数组。
			//
			// 参数:
			//   s:
			//     要转换的字符串。
			//
			// 返回结果:
			//     与 s 等效的 8 位无符号整数数组。
			//
			// 异常:
			//   T:System.ArgumentNullException:
			//     s 为 null。
			//
			//   T:System.FormatException:
			//     s 的长度（忽略空白字符）不是 0 或 4 的倍数。- 或 -s 的格式无效。s 包含一个非 base 64 字符、两个以上的填充字符或者在填充字符中包含非空白字符。
			static vector<unsigned char> FromBase64String(string s);
			//
			// 摘要:
			//     将 8 位无符号整数的数组转换为其用 Base64 数字编码的等效字符串表示形式。
			//
			// 参数:
			//   inArray:
			//     一个 8 位无符号整数数组。
			//
			// 返回结果:
			//     inArray 的内容的字符串表示形式，以 Base64 表示。
			//
			// 异常:
			//   T:System.ArgumentNullException:
			//     inArray 为 null。
			static string ToBase64String(vector<unsigned char>& inArray);
		};
	}
}