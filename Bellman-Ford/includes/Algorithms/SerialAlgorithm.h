#pragma once
#include "Algorithm.h"

class SerialAlgorithm : public Algorithm
{
public:
	SerialAlgorithm() : Algorithm(false) {}

	Result solve(const std::vector<Edge>& edges, Edge start, int vertices) override;
};

