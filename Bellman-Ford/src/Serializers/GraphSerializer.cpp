#include "../../includes/Serializers/GraphSerializer.h"

void GraphSerializer::serialize(string path, vector<vector<int>> value)
{
	ofstream file(path);

	if (!file.is_open()) return;

	file << value.size() << endl;
	for (int i = 0; i < value.size(); i++)
	{
		for (int j = 0; j < value[i].size(); j++)
		{
			file << value[i][j] << " ";
		}

		file << endl;
	}

	file.close();
}