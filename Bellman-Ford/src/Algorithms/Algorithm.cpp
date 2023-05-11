#include <iostream>

#include "../../includes/Algorithms/Algorithm.h"
#include "../../includes/Constants.h"

using namespace std;

void Algorithm::startTimer()
{
	startTime = chrono::steady_clock::now();
}

long Algorithm::stopTimer()
{
	endTime = chrono::steady_clock::now();

	return chrono::duration<double, milli>(endTime - startTime).count();
}

int* Algorithm::initializeDistances(int vertices)
{
	int* distances = new int[vertices];
	for (int i = 0; i < vertices; i++) {
		distances[i] = INF;
	}

	return distances;
}

void Algorithm::printResult(int* distances, int vertices)
{
	for (int i = 0; i < vertices; i++) {
		cout << i << "=>" << distances[i] << endl;
	}
}

bool Algorithm::containsNegativeCycles(const std::vector<vector<int>>& adjacencyMatrix, int* distances, int vertices)
{
	bool negativeCyclesExist = false;
	for (int u = 0; u < vertices; u++) {
		for (int v = 0; v < vertices; v++) {
			int weight = adjacencyMatrix[u][v];
			if (weight >= INF) continue;

			int value = distances[u] + weight;
			if (distances[v] > value) {
				negativeCyclesExist = true;
				break;
			}
		}
	}

	return negativeCyclesExist;
}
