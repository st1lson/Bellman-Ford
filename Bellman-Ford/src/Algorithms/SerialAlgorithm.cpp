#include "../../includes/Algorithms/SerialAlgorithm.h"
#include <vector>
#include "../../includes/Models/Edge.h"
#include <iostream>
#include "../../includes/Constants.h"

using namespace std;

Result SerialAlgorithm::solve(vector<vector<int>> adjacencyMatrix, int start, int vertices)
{
	startTimer();

	int* distances = initializeDistances(vertices);

	distances[0] = 0;
	for (int i = 0; i < vertices - 1; i++) {
		bool relaxed = false;

		for (int u = 0; u < vertices; u++) {
			for (int v = 0; v < vertices; v++) {
				int weight = adjacencyMatrix[u][v];
				if (weight >= INF) continue;

				int value = distances[u] + weight;
				if (distances[v] > value) {
					distances[v] = value;
					relaxed = true;
				}
			}
		}

		if (!relaxed) {
			break;
		}
	}


	bool negativeCycle = containsNegativeCycles(adjacencyMatrix, distances, vertices);

	long duration = stopTimer();

	return Result(distances, duration, vertices, negativeCycle);
}
