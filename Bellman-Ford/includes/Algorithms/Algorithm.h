#pragma once
#include "../Models/Edge.h"
#include <vector>
#include <memory>
#include <chrono>
#include "../Models/Result.h"

using namespace std;

class Algorithm
{
public:
	typedef unique_ptr<Algorithm> Ptr;

	Algorithm(bool parallel) {
		this->parallel = parallel;
	}

	virtual Result solve(vector<vector<int>> adjacencyMatrix, int start, int vertices) = 0;
protected:
	bool parallel = false;
	chrono::steady_clock::time_point startTime;
	chrono::steady_clock::time_point endTime;

	void startTimer();
	long stopTimer();
	virtual int* initializeDistances(int vertices);
	void printResult(int* distances, int vertices);
	virtual bool containsNegativeCycles(const vector<Edge>& edges, int* distances, int vertices);
};
