#pragma once

class DirectedWeightedEdge
{
public:
	DirectedWeightedEdge()
	{
		cost = 0;
		source = 0;
		sink = 0;
	}
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