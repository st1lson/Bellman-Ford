#include "../../includes/Algorithms/ParallelAlgorithm.h"
#include <iostream>
#include <vector>

#include "omp.h"

using namespace std;

Result ParallelAlgorithm::solve(const std::vector<Edge>& edges, Edge start, int vertices)
{
	int* chunkStart = new int[threadsNumber];
	int* chunkEnd = new int[threadsNumber];

	startTimer();

	omp_set_num_threads(threadsNumber);

	int* distances = initializeDistances(vertices);

	int ave = vertices / threadsNumber;
#pragma omp parallel for
	for (int i = 0; i < threadsNumber; i++) {
		chunkStart[i] = ave * i;

		if (i != threadsNumber - 1) {
			chunkEnd[i] = ave * (i + 1);
		}
		else {
			chunkEnd[i] = vertices;
		}
	}

	distances[0] = 0;
	for (int i = 0; i < vertices - 1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			Edge edge = edges[j];
			if (distances[edge.from] == INF) continue;

			int value = distances[edge.from] + edge.weight;
			if (distances[edge.to] > value) {
				distances[edge.to] = value;
			}
		}
	}

	if (containsNegativeCycles(edges, distances, vertices)) {
		cout << "Negative cycle" << endl;
	}

	long duration = stopTimer();

	return Result(distances, duration);
}

int* ParallelAlgorithm::initializeDistances(int vertices)
{
	int* distances = new int[vertices];
#pragma omp parallel for
	for (int i = 0; i < vertices; i++) {
		distances[i] = INF;
	}

	return distances;
}
