#pragma once
#include <vector>
#include "Edge.h"
struct Result
{
	std::shared_ptr<int[]> distances;
	long duration;

	Result(int* distances, long duration)
		: distances(distances), duration(duration) {}
};
