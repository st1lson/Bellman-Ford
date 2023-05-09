#include "../../includes/Algorithms/SerialAlgorithm.h"
#include <vector>
#include "../../includes/Models/Edge.h"
#include <iostream>

using namespace std;

Result SerialAlgorithm::solve(const vector<Edge>& edges, Edge start, int vertices)
{
	startTimer();

	int* distances = initializeDistances(vertices);

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
	}/*
	else {
		printResult(distances, vertices);
	}*/

	long duration = stopTimer();

	return Result(distances, duration);
}
