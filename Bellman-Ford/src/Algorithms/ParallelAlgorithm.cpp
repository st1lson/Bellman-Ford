#include "../../includes/Algorithms/ParallelAlgorithm.h"
#include <iostream>
#include <vector>

#include "omp.h"
#include "../../includes/Constants.h"

using namespace std;

Result ParallelAlgorithm::solve(vector<vector<int>> adjacencyMatrix, int start, int vertices)
{
	int* chunkStart = new int[threadsNumber];
	int* chunkEnd = new int[threadsNumber];

	startTimer();

	omp_set_num_threads(threadsNumber);

	int* distances = initializeDistances(vertices);

	int chunkSize = vertices / threadsNumber;

	#pragma omp parallel for
	for (int i = 0; i < threadsNumber; i++) {
		chunkStart[i] = chunkSize * i;

		if (i != threadsNumber - 1) {
			chunkEnd[i] = chunkSize * (i + 1);
		}
		else {
			chunkEnd[i] = vertices;
		}
	}

	bool relaxed;
	vector<bool> localRelaxed(threadsNumber);
	distances[0] = 0;
	#pragma omp parallel
	{
		int rank = omp_get_thread_num();
		for (int i = 0; i < vertices - 1; i++) {
			localRelaxed[rank] = false;

			for (int u = 0; u < vertices; u++) {
				for (int v = chunkStart[rank]; v < chunkEnd[rank]; v++) {
					int weight = adjacencyMatrix[u][v];
					if (weight >= INF) continue;

					int value = distances[u] + weight;
					if (distances[v] > value) {
						distances[v] = value;
						localRelaxed[rank] = true;
					}
				}
			}

			#pragma omp barrier
			#pragma omp single
			{
				relaxed = false;
				for (int rank = 0; rank < threadsNumber; rank++) {
					relaxed |= localRelaxed[rank];
				}
			}

			if (!relaxed) {
				break;
			}
		}
	}

	bool negativeCylcles = containsNegativeCycles(adjacencyMatrix, distances, vertices);

	long duration = stopTimer();

	return Result(distances, duration, vertices, negativeCylcles);
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

bool ParallelAlgorithm::containsNegativeCycles(const vector<vector<int>>& adjacencyMatrix, int* distances, int vertices)
{
	bool negativeCyclesExist = false;

	#pragma omp parallel for reduction(|:negativeCyclesExist)
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
