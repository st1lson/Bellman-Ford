#include "../../includes/Serializers/GraphSerializer.h"
#include "../../includes/Constants.h"

void GraphSerializer::serialize(string path, vector<vector<int>> value)
{
	ofstream file(path);

	if (!file.is_open()) return;

	int vertices = value.size();
	file << vertices << endl;
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			file << value[i][j] << " ";
		}

		file << endl;
	}

	file.close();
}

vector<vector<int>> GraphSerializer::deserialize(string path)
{
	ifstream file(path);

	if (!file.is_open()) {
		throw exception("failed to open a stream");
	}

	string line;
	getline(file, line);
	int vertices = stoi(line);

	vector<vector<int>> matrix(vertices, vector<int>(vertices, INF));
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			file >> matrix[i][j];
		}
	}

	return matrix;
}
