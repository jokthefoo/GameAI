#include "DirectedGraph.h"

std::list<DirectedWeightedEdge> DirectedGraph::getOutgoingEdges(int node)
{
	return edges.at(node);
}
