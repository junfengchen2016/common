#pragma once

namespace chenjunfeng
{
	namespace System
	{

class Random
{
public:
	static void SRandom(int Seed);
	static int Next(int minValue, int maxValue);
	//
	// ժҪ:
	//     ����һ������ 0.0 �� 1.0 ֮��������������
	//
	// ���ؽ��:
	//     ���ڵ��� 0.0 ����С�� 1.0 ��˫���ȸ�������
	static double NextDouble();
};

	}
}