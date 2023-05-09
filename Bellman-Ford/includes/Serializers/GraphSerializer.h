#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class GraphSerializer {
public:
	void serialize(string path, vector<vector<int>> value);

	vector<vector<int>> deserialize(string path);
};