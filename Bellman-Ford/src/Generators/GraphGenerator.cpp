#include <random>

#include "../../includes/Generators/GraphGenerator.h"
#include "../../includes/Constants.h"

using namespace std;

vector<vector<int>> GraphGenerator::generateGraph(int verticesCount)
{
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution dist(EDGE_CHANCE);
    bernoulli_distribution negDist(1. / verticesCount);
    uniform_int_distribution<int> possitiveWeightDist(MIN_POSITIVE_VALUE, MAX_POSITIVE_VALUE);
    uniform_int_distribution<int> negativeWeightDist(MIN_NEGATIVE_VALUE, MAX_NEGATIVE_VALUE);

    vector<vector<int>> adjacencyMatrix(verticesCount, vector<int>(verticesCount, INF));

    for (int i = 0; i < verticesCount; ++i) {
        for (int j = 0; j < verticesCount; ++j) {
            if (i == j) continue;

            if (dist(gen)) {
                adjacencyMatrix[i][j] = possitiveWeightDist(gen);
            }
            else if (negDist(gen)) {
                adjacencyMatrix[i][j] = negativeWeightDist(gen);
            }
        }
    }

    return adjacencyMatrix;
}
