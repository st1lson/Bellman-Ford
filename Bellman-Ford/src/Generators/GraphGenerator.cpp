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
        if (x.source == y.source) {
            return x.destination < y.destination;
        }
        else {
            return x.source < y.source;
        }
    };
    auto unique_edges = set<Edge,decltype(comp)>(comp);

    for (int i = 0; i < edgesCount; i++) {
        int u = rand() % verticesCount, v = rand() % verticesCount;
        if (u > v) swap(u, v);

        int w = rand() % 13 - 2;
        auto edge = Edge(u, v, w);
        if (u == v || unique_edges.count(edge)) {
            continue;
        }

        edges.push_back(edge);
        unique_edges.insert(edge);
    }

    return edges;
}
