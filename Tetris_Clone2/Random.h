#pragma once
#include <random>
class Random
{
public:
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_int_distribution<int> dist;
	
	//int random_index;

	Random(const int begin, const int end)
		:rng{dev()},
		dist{begin, end}
	{
		//random_index = dist(rng);
	}

	int GetRandomNum()
	{
		return dist(rng);
	}
};
