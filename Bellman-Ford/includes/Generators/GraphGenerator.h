#pragma once
#include "../Models/Edge.h"
#include <vector>

using namespace std;

class GraphGenerator {
public:
	vector<vector<int>> generateGraph(int verticesCount, int edgesCount);
};
