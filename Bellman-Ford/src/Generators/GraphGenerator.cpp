#include "../../includes/Generators/GraphGenerator.h"
#include <iostream>
#include <vector>
#include <set>
#include "../../includes/Models/Edge.h"
#include "time.h"
#include "../../includes/Constants.h"

using namespace std;

vector<vector<int>> GraphGenerator::generateGraph(int verticesCount, int edgesCount)
{
    srand(time(NULL));

    vector<vector<int>> adjacencyMatrix(verticesCount, vector<int>(verticesCount, INF));
    set<pair<int, int>> unique_edges;

    for (int i = 0; i < edgesCount; i++) {
        int u = rand() % verticesCount, v = rand() % verticesCount;
        if (u > v) swap(u, v);

        int w = rand() % 10 + 1;
        if (u == v || unique_edges.count({ u, v })) {
            continue;
        }

        adjacencyMatrix[u][v] = w;
        unique_edges.insert({ u, v });
    }

    return adjacencyMatrix;
}
