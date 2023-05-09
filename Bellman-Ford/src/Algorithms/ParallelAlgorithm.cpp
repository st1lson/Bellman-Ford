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

	int chunkSize = edges.size() / threadsNumber;
#pragma omp parallel for
	for (int i = 0; i < threadsNumber; i++) {
		chunkStart[i] = chunkSize * i;

		if (i != threadsNumber - 1) {
			chunkEnd[i] = chunkSize * (i + 1);
		}
		else {
			chunkEnd[i] = edges.size();
		}
	}

	distances[0] = 0;
#pragma omp parallel
	{
		int rank = omp_get_thread_num();
		for (int i = 0; i < vertices - 1; i++)
		{
			for (int j = chunkStart[rank]; j < chunkEnd[rank]; j++)
			{
				Edge edge = edges[j];
				if (distances[edge.source] == INF) continue;

				int value = distances[edge.source] + edge.weight;
				if (distances[edge.destination] > value) {
					distances[edge.destination] = value;
				}
			}
		}
	}

	if (containsNegativeCycles(edges, distances, vertices)) {
		cout << "Negative cycle" << endl;
	}

	long duration = stopTimer();

	return Result(distances, duration, vertices);
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

bool ParallelAlgorithm::containsNegativeCycles(const vector<Edge>& edges, int* distances, int vertices)
{
	bool negativeCyclesExist = false;
#pragma omp parallel for reduction(|:negativeCyclesExist)
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
