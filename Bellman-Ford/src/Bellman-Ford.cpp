#include <iostream>
#include "../includes/Models/Edge.h"
#include "../includes/Algorithms/Algorithm.h"
#include "../includes/Algorithms/SerialAlgorithm.h"
#include "../includes/Algorithms/ParallelAlgorithm.h"
#include "../includes/Generators/GraphGenerator.h"
#include "../includes/Serializers/GraphSerializer.h"
#include <vector>
#include "../includes/Constants.h"

using namespace std;

int main()
{
	auto generator = new GraphGenerator();
	auto adjacencyMatrix = generator->generateGraph(VERTICES, EDGES);
	if (SERIALIZE) {
		GraphSerializer().serialize(format("{}\\{}.txt", PATH, VERTICES), adjacencyMatrix);
	}

	Algorithm::Ptr solver(new SerialAlgorithm());
	auto result = solver->solve(adjacencyMatrix, 0, VERTICES);

	cout << result.duration << endl;

	Algorithm::Ptr parallelSolver(new ParallelAlgorithm(12));
	auto parallelResult = parallelSolver->solve(adjacencyMatrix, 0, VERTICES);

	cout << parallelResult.duration << endl;

	cout << (result.equals(parallelResult) ? "true" : "false") << endl;
}
