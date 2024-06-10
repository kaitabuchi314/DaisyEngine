#include "Random.h"

namespace Daisy
{
	float Random::FloatRandom(float min, float max)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6((float)min, (float)max);

		return dist6(rng);
	}

	int Random::IntRandom(int min, int max)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6((int)min, (int)max);

		return dist6(rng);
	}
}