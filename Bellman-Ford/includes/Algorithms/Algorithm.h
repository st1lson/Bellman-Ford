#pragma once
#include "../Models/Edge.h"
#include <vector>
#include <memory>

class Algorithm
{
public:
	typedef std::unique_ptr<Algorithm> Ptr;

	virtual void solve(const std::vector<Edge>& edges, Edge start, int vertices) = 0;
protected:
	const int INF = INT_MAX;

	int* initializeDistances(int vertices);
	void printResult(int* distances, int vertices);
	bool containsNegativeCycles(const std::vector<Edge>& edges, int* distances, int vertices);
};
