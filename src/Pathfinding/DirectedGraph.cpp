#include "DirectedGraph.h"

std::list<DirectedWeightedEdge> DirectedGraph::getOutgoingEdges(int node)
{
	return nodes.at(node);
}

void DirectedGraph::addEdge(DirectedWeightedEdge nEdge)
{
	nodes[nEdge.sink].push_back(nEdge);
}

void DirectedGraph::constructGraph(int numNodes)
{
	nodes.resize(numNodes);
}
