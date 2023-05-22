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
}
