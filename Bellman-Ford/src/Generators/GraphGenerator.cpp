#include "../../includes/Generators/GraphGenerator.h"
#include <iostream>
#include <vector>
#include <set>
#include "../../includes/Models/Edge.h"
#include "time.h"

using namespace std;

vector<Edge> GraphGenerator::generateGraph(int verticesCount, int edgesCount)
{
    srand(time(NULL));

    vector<Edge> edges;
    auto comp = [](Edge x, Edge y)
    { 
        if (x.from == y.from) {
            return x.to < y.to;
        }
        else {
            return x.from < y.from;
        }
    };
    auto unique_edges = set<Edge,decltype(comp)>(comp);

    for (int i = 0; i < edgesCount; i++) {
        int u = rand() % verticesCount, v = rand() % verticesCount;
        if (u > v) swap(u, v);

        int w = rand() % 10 + 1;
        auto edge = Edge(u, v, w);
        if (u == v || unique_edges.count(edge)) {
            continue;
        }

        edges.push_back(edge);
        unique_edges.insert(edge);
    }

    return edges;
}
