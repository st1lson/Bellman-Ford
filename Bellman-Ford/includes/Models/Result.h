#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Result
{
	shared_ptr<int[]> distances;
	bool containsNegativeCycle;
	long duration;

	Result(int* distances, long duration, int length, bool containsNegativeCycle)
		: distances(distances), duration(duration), length(length), containsNegativeCycle(containsNegativeCycle) {
	}

	bool equals(Result result) {
		for (int i = 0; i < length; i++) {
			if (distances[i] != result.distances[i]) return false;
		}

		return true;
	}

	string toString() {
		stringstream ss;

		ss << format("Duration: {}ms\n", duration);
		ss << format("Constains negative cycles: {}\n", containsNegativeCycle);

		return ss.str();
	}

	void assert(Result result) {
		if (!result.containsNegativeCycle) {
			cout << format("Distances equal: {}\n", (result.equals(result) ? "true" : "false"));
		}
		else {
			cout << "Negative cycle" << endl;
		}
	}

private:
	int length;
};
