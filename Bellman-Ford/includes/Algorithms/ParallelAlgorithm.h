#pragma once
#include "Algorithm.h"

class ParallelAlgorithm : public Algorithm
{
public:
	ParallelAlgorithm(int threads) : Algorithm(true) {
		threadsNumber = threads;
	}

	Result solve(const std::vector<Edge>& edges, Edge start, int vertices) override;
protected:
	int* initializeDistances(int vertices) override;
private:
	int threadsNumber;
};

