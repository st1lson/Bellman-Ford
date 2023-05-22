#include "../../includes/Generators/TestGenerator.h"
#include "../../includes/Algorithms/Algorithm.h"
#include "../../includes/Algorithms/SerialAlgorithm.h"
#include "../../includes/Algorithms/ParallelAlgorithm.h"
#include "../../includes/Constants.h"

void TestGenerator::test()
{
	auto serialSolver = SerialAlgorithm();
	auto parallelSolver = ParallelAlgorithm(NUMBER_OF_PROCESSORS);

	double parallelDuration = 0;
	double serialDuration = 0;
	bool equal = true;
	for (int i = 1; i <= NUMBER_OF_TESTS; i++)
	{
		auto serialResult = serialSolver.solve(adjacencyMatrix, 0, VERTICES);
		if (VERBOSE == High) {
			cout << format("Iteration: {}\nSerial algorithm:\n{}\n", i, serialResult.toString());
		}

		serialDuration += serialResult.duration / 1000.;

		auto parallelResult = parallelSolver.solve(adjacencyMatrix, 0, VERTICES);
		if (VERBOSE == High) {
			cout << format("Iteration: {}\nParallel algorithm:\n{}\n", i, parallelResult.toString());
		}

		parallelDuration += parallelResult.duration / 1000.;

		equal &= serialResult.equals(parallelResult);
		cout << (serialResult.equals(parallelResult) ? "True" : "False") << endl;
	}

	cout << format("Average serial algorithm duration: {:.3f}s\n", serialDuration / NUMBER_OF_TESTS);
	cout << format("Average parallel algorithm duration: {:.3f}s\n", parallelDuration / NUMBER_OF_TESTS);

	cout << format("Results correct: {}", equal ? "True" : "False");
}
