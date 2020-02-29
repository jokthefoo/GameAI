#pragma once

class DirectedWeightedEdge
{
public:
	DirectedWeightedEdge(float c, int o, int s)
	{
		cost = c;
		source = o;
		sink = s;
	}
	float cost;
	int source;
	int sink;
};