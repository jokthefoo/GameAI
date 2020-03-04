#pragma once
#include "Path.h"
#include "DirectedGraph.h"
#include "DirectedWeightedEdge.h"
#include "NodeRecord.h"
#include "Heuristic.h"
#include "NRQueue.h"

Path pathfindingAStar(DirectedGraph graph, int startNode, int goal, Heuristic &heuristic)
{
	NodeRecord startRecord;
	startRecord.node = startNode;
	startRecord.costSoFar = 0;
	startRecord.estimateToGoal = heuristic.getEstimate(startNode, goal);

	MySet open;
	open.insert(startRecord);

	MySet closed;

	int visited = 0;

	NodeRecord current;
	while (open.size() > 0)
	{
		current = *open.begin();
		visited++;

		if (current.node == goal)
		{
			break;
		}

		std::list<DirectedWeightedEdge> outgoing = graph.getOutgoingEdges(current.node);
		size_t numEdge = outgoing.size();
		for (size_t i = 0; i < numEdge; i++)
		{
			DirectedWeightedEdge curEdge = outgoing.front();
			outgoing.pop_front();
			int sinkID = curEdge.sink;
			float g = curEdge.cost + current.costSoFar;
			float h = heuristic.getEstimate(sinkID, goal);

			if (closed.contains(sinkID))
			{
				NodeRecord vistedNR = closed.get(sinkID);
				if (vistedNR.costSoFar <= g)
				{
					continue;
				}

				closed.remove(sinkID);
			}
			else if (open.contains(sinkID))
			{
				NodeRecord vistedNR = open.get(sinkID);
				if (vistedNR.costSoFar <= g)
				{
					continue;
				}
			}

			NodeRecord newNodeR;
			newNodeR.node = sinkID;
			newNodeR.incomingEdge = curEdge;
			newNodeR.estimateToGoal = g + h;
			newNodeR.costSoFar = g;

			open.insert(newNodeR);
		}

		open.remove(current.node);
		closed.insert(current);
	}

	Path p;
	if (current.node != goal)
	{
		return p;
	}

	while (current.node != startNode)
	{
		p.path.push_front(current.incomingEdge);
		current = closed.get(current.incomingEdge.source);
	}

	printf("nodes visited: %d", visited);
	return p;
}
