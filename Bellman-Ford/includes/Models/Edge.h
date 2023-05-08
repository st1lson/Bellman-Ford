#pragma once
struct Edge
{
	int from;
	int to;
	long weight;

	Edge(int from, int to, long weight): from(from), to(to), weight(weight) {}
};
