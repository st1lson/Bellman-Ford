#include <iostream>
#include <vector>

#include "../includes/Algorithms/Algorithm.h"
#include "../includes/Algorithms/SerialAlgorithm.h"
#include "../includes/Algorithms/ParallelAlgorithm.h"
#include "../includes/Generators/GraphGenerator.h"
#include "../includes/Serializers/GraphSerializer.h"
#include "../includes/Constants.h"
#include "../includes/Generators/TestGenerator.h"

using namespace std;

int main()
{
	const string filePath = format("{}\\{}.txt", PATH, VERTICES);

	auto adjacencyMatrix = GENERATE_MATRIX
		? GraphGenerator().generateGraph(VERTICES)
		: GraphSerializer().deserialize(filePath);
	if (SERIALIZE_MATRIX) {
		GraphSerializer().serialize(filePath, adjacencyMatrix);
	}

	auto tester = TestGenerator(adjacencyMatrix);
	tester.test();

	//vector<vector<int>> adjacencyMatrix {
	//	{ 0, 3, 8, INF, -4 },
	//	{ INF, 0, INF, 1, 7 },
	//	{ INF, 4, 0, INF, INF },
	//	{ 2, INF, 5, 0, INF },
	//	{ INF, INF, INF, 6, 0 }
	//};

	//cout << "Adjacency Matrix" << endl;
	//for (int i = 0; i < adjacencyMatrix.size(); i++)
	//{
	//	for (int j = 0; j < adjacencyMatrix.size(); j++)
	//	{
	//		cout << setw(8) << adjacencyMatrix[i][j] << "";
	//	}

	//	cout << endl;
	//}

	//Algorithm::Ptr parallelSolver(new ParallelAlgorithm(NUMBER_OF_PROCESSORS));
	//auto parallelResult = parallelSolver->solve(adjacencyMatrix, 0, VERTICES);

	//cout << format("Parallel alogirthm:\n{}\n", parallelResult.toString());

	//result.assert(parallelResult);
}
