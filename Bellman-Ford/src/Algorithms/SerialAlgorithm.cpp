#include "../../includes/Algorithms/SerialAlgorithm.h"
#include <vector>
#include "../../includes/Models/Edge.h"

using namespace std;

void SerialAlgorithm::solve(vector<Edge> edges, Edge start)
{
	const int size = edges.size();



	int *distances = new int[size];
	for (int i = 0; i < size; i++) {
		distances[i] = INF;
	}

	distances[0] = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			auto& edge = edges.at(j);
			if (distances[edge.from] == INF) continue;
			
			int value = distances[edge.from] + edge.weight;
			if (distances[edge.to] > value) {
				distances[edge.to] = value;
			}
		}
	}
}
