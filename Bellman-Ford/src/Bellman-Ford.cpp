#include <iostream>
#include "../includes/Models/Edge.h"
#include "../includes/Algorithms/Algorithm.h"
#include "../includes/Algorithms/SerialAlgorithm.h"
#include "../includes/Algorithms/ParallelAlgorithm.h"
#include <vector>

using namespace std;

int main()
{
	vector<Edge> edges = {
		{ 0, 1, -1 },
		{ 0, 2, 4 },
		{ 1, 2, 3 },
		{ 1, 3, 2 },
		{ 1, 4, 2 },
		{ 3, 2, 5 },
		{ 3, 1, 1 },
		{ 4, 3, -3 }
	};

	Algorithm::Ptr solver(new SerialAlgorithm());
	auto result = solver->solve(edges, edges[0], 5);

	cout << result.duration << endl;
}
