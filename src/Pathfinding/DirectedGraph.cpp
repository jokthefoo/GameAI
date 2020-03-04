#include "DirectedGraph.h"

std::list<DirectedWeightedEdge> DirectedGraph::getOutgoingEdges(int node)
{
	return nodes.at(node);
}

void DirectedGraph::addEdge(DirectedWeightedEdge nEdge)
{
	nodes[nEdge.source].push_back(nEdge);
}

void DirectedGraph::constructGraph(int numNodes)
{
	nodes.resize(numNodes+1);
}


DirectedGraph DirectedGraph::BuildGridGraph(int n, int* graph)
{
	DirectedGraph dirGraph;
	dirGraph.constructGraph(n*n);

	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			int cur = *((graph + i * n) + j);
			int curN = i * n + j;
			if (cur)
			{
				continue;
			}
			int left = 1, right = 1, up = 1, down = 1;
			if(j - 1 > 0)
			 left = *((graph + i * n) + j - 1);
			if (j + 1 < n)
			 right = *((graph + i * n) + j + 1);
			if (i + 1 < n)
			 up = *((graph + (i + 1) * n) + j);
			if (i - 1 > 0)
			 down = *((graph + (i - 1) * n) + j);
			if (!left)
			{
				DirectedWeightedEdge edge;
				edge.cost = 1;
				edge.source = curN;
				edge.sink = (i * n) + j - 1;
				dirGraph.addEdge(edge);
			}
			if (!right)
			{
				DirectedWeightedEdge edge;
				edge.cost = 1;
				edge.source = curN;
				edge.sink = (i * n) + j + 1;
				dirGraph.addEdge(edge);
			}
			if (!up)
			{
				DirectedWeightedEdge edge;
				edge.cost = 1;
				edge.source = curN;
				edge.sink = (i + 1) * n + j;
				dirGraph.addEdge(edge);
			}
			if (!down)
			{
				DirectedWeightedEdge edge;
				edge.cost = 1;
				edge.source = curN;
				edge.sink = (i - 1) * n + j;
				dirGraph.addEdge(edge);
			}
		}
	}

	return dirGraph;
}