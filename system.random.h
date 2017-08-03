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
	// 摘要:
	//     返回一个介于 0.0 和 1.0 之间的随机浮点数。
	//
	// 返回结果:
	//     大于等于 0.0 并且小于 1.0 的双精度浮点数。
	static double NextDouble();
};

	}
}