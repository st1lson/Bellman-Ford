#pragma once
#include <vector>
#include "Edge.h"
struct Result
{
	std::shared_ptr<int[]> distances;
	long duration;

	Result(int* distances, long duration)
		: distances(distances), duration(duration) {}

	bool equals(Result result) {
		for (int i = 0; i < sizeof(distances); i++)
		{
			if (distances[i] != result.distances[i]) return false;
		}

		return true;
	}
};
