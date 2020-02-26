#pragma once
#include "DirectedWeightedEdge.h"
#include <list>
#include <vector>

class DirectedGraph
{
	std::vector<std::list<DirectedWeightedEdge>> edges;
public:
	std::list<DirectedWeightedEdge> getOutgoingEdges(int node);
};