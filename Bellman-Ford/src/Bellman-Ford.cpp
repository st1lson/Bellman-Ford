#include <iostream>
#include "../includes/Models/Edge.h"
#include "../includes/Algorithms/Algorithm.h"
#include "../includes/Algorithms/SerialAlgorithm.h"
#include "../includes/Algorithms/ParallelAlgorithm.h"
#include "../includes/Generators/GraphGenerator.h"
#include <vector>

using namespace std;

int main()
{
	auto generator = new GraphGenerator();
	auto adjacencyMatrix = generator->generateGraph(1000, 1000000);

	Algorithm::Ptr solver(new SerialAlgorithm());
	auto result = solver->solve(adjacencyMatrix, 0, 1000);

	cout << result.duration << endl;

	Algorithm::Ptr parallelSolver(new ParallelAlgorithm(12));
	auto parallelResult = parallelSolver->solve(adjacencyMatrix, 0, 1000);

	cout << parallelResult.duration << endl;

	cout << (result.equals(parallelResult) ? "true" : "false") << endl;
}
