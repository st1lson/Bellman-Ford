#pragma once
#include "Algorithm.h"

using namespace std;

class ParallelAlgorithm : public Algorithm
{
public:
	ParallelAlgorithm(int threads) : Algorithm(true) {
		threadsNumber = threads;
	}

	Result solve(vector<vector<int>> adjacencyMatrix, int start, int vertices) override;
protected:
	int* initializeDistances(int vertices) override;
private:
	int threadsNumber;
	bool containsNegativeCycles(const vector<Edge>& edges, int* distances, int vertices) override;
};

