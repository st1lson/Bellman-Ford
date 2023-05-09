#pragma once
struct Edge
{
	int source;
	int destination;
	long weight;

	Edge(int from, int to, long weight): source(from), destination(to), weight(weight) {}
};
