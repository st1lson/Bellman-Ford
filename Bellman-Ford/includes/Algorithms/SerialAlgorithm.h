#pragma once
#include "Algorithm.h"

using namespace std;

class SerialAlgorithm : public Algorithm
{
public:
	SerialAlgorithm() : Algorithm(false) {}

	Result solve(vector<vector<int>> adjacencyMatrix, int start, int vertices) override;
};

