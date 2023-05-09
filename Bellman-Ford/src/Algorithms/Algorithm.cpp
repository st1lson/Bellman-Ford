#include "../../includes/Algorithms/Algorithm.h"
#include <iostream>
#include <chrono>

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

bool Algorithm::containsNegativeCycles(const std::vector<Edge>& edges, int* distances, int vertices)
{
	bool negativeCyclesExist = false;
	for (int i = 0; i < edges.size(); i++) {
		Edge edge = edges[i];

		if (distances[edge.source] != INF
			&& distances[edge.source] + edge.weight < distances[edge.destination]) {
			negativeCyclesExist = true;
			break;
		}
	}

	return negativeCyclesExist;
}
