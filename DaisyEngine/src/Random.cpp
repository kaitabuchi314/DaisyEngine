#include "Random.h"

namespace Daisy
{
	namespace Random
	{
		int RandomInt(int i, int j)
		{
			std::random_device random_device;
			std::mt19937 engine{random_device()};
			std::uniform_int_distribution<> dist((int)i, (int)j);
			auto X = dist(engine);
			return X;
		}

		float RandomFloat(float i, float j)
		{
			std::random_device random_device;
			std::mt19937 engine{random_device()};
			std::uniform_int_distribution<> dist((float)i, (float)j);
			auto X = dist(engine);
			return X;
		}
	}
}