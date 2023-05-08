#pragma once
#include "../Models/Edge.h"
#include <vector>

class Algorithm
{
public:
	virtual void solve(std::vector<Edge> edges, Edge start) = 0;
protected:
	const int INF = 1e9 + 5;
};
