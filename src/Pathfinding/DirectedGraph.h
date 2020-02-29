#pragma once
#include "DirectedWeightedEdge.h"
#include <list>
#include <vector>

class DirectedGraph
{
	std::vector<std::list<DirectedWeightedEdge>> nodes;
public:
	std::list<DirectedWeightedEdge> getOutgoingEdges(int node);
	void addEdge(DirectedWeightedEdge edges);
	void constructGraph(int numNodes);
};