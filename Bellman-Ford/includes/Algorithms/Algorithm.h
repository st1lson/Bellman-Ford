#pragma once
#include "../Models/Edge.h"
#include <vector>

class Algorithm
{
public:
	virtual void solve(std::vector<Edge> edges, Edge start, int vertices) = 0;
protected:
	const int INF = INT_MAX;

	int* initializeDistances(int vertices);
	void printResult(int* distances, int vertices);
	bool containsNegativeCycles(std::vector<Edge> edges, int* distances, int vertices);
};
