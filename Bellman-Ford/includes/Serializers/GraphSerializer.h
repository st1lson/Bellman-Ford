#pragma once
#include <string>
#include <vector>

using namespace std;

class GraphSerializer {
public:
	void serialize(string path, vector<vector<int>> value);

	vector<vector<int>> deserialize(string path);
};