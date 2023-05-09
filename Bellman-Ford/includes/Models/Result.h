#pragma once
#include <vector>
#include <iostream>
#include "Edge.h"
struct Result
{
	std::shared_ptr<int[]> distances;
	long duration;

	Result(int* distances, long duration, int length)
		: distances(distances), duration(duration) {
		this->length = length;
	}

	bool equals(Result result) {
		for (int i = 0; i < length; i++)
		{
			if (distances[i] != result.distances[i]) return false;
		}

		return true;
	}

private:
	int length;
};
