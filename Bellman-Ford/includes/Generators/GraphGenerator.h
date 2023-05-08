#pragma once
#include "../Models/Edge.h"
#include <vector>

class GraphGenerator {
public:
	std::vector<Edge> generateGraph(int verticesCount, int edgesCount);
};
