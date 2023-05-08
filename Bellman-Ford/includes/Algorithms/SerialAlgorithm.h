#pragma once
#include "Algorithm.h"

class SerialAlgorithm : public Algorithm
{
public:
	void solve(std::vector<Edge> edges, Edge start) override;
};

