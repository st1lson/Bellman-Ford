#include "../../includes/Algorithms/Algorithm.h"
#include <iostream>

using namespace std;

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

bool Algorithm::containsNegativeCycles(std::vector<Edge> edges, int* distances, int vertices)
{
	bool negativeCyclesExist = false;
	for (int i = 0; i < edges.size(); i++) {
		Edge edge = edges.at(i);

		if (distances[edge.to] > distances[edge.from] + edge.weight) {
			negativeCyclesExist = true;
			break;
		}
	}

	return negativeCyclesExist;
}
