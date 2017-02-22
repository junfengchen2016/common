#include "system.random.h"

#include <stdlib.h>

namespace chenjunfeng
{
	namespace System
	{

void Random::SRandom(int Seed)
{
	srand(Seed);
}

int Random::Next(int minValue, int maxValue)
{
	return (int)(minValue + (maxValue - minValue) * rand() / (RAND_MAX + 1.0));
}

	}
}
