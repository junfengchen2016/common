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
			// ժҪ:
			//     ��ָ�����ַ������������������ݱ���Ϊ Base64 ���֣�ת��Ϊ��Ч�� 8 λ�޷����������顣
			//
			// ����:
			//   s:
			//     Ҫת�����ַ�����
			//
			// ���ؽ��:
			//     �� s ��Ч�� 8 λ�޷����������顣
			//
			// �쳣:
			//   T:System.ArgumentNullException:
			//     s Ϊ null��
			//
			//   T:System.FormatException:
			//     s �ĳ��ȣ����Կհ��ַ������� 0 �� 4 �ı�����- �� -s �ĸ�ʽ��Ч��s ����һ���� base 64 �ַ����������ϵ�����ַ�����������ַ��а����ǿհ��ַ���
			static vector<unsigned char> FromBase64String(string s);
			//
			// ժҪ:
			//     �� 8 λ�޷�������������ת��Ϊ���� Base64 ���ֱ���ĵ�Ч�ַ�����ʾ��ʽ��
			//
			// ����:
			//   inArray:
			//     һ�� 8 λ�޷����������顣
			//
			// ���ؽ��:
			//     inArray �����ݵ��ַ�����ʾ��ʽ���� Base64 ��ʾ��
			//
			// �쳣:
			//   T:System.ArgumentNullException:
			//     inArray Ϊ null��
			static string ToBase64String(vector<unsigned char>& inArray);
		};
	}
}