#pragma once
#include <vector>
using namespace std;

class TestGenerator
{
public:
	TestGenerator(vector<vector<int>> adjacencyMatrix)
	{
		this->adjacencyMatrix = adjacencyMatrix;
	}

	void test();
private:
	vector<vector<int>> adjacencyMatrix;
};

