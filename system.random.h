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
};

	}
}