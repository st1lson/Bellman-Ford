#pragma once
#include "Algorithm.h"

class SerialAlgorithm : public Algorithm
{
public:
	void solve(const std::vector<Edge>& edges, Edge start, int vertices) override;
};

