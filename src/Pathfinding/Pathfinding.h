#pragma once
#include "Path.h"
#include "DirectedGraph.h"
#include "DirectedWeightedEdge.h"
#include "NodeRecord.h"
#include "Heuristic.h"
#include "NRQueue.h"

Path pathfindingAStar(DirectedGraph graph, int startNode, int goal, Heuristic heuristic)
{
	NodeRecord startRecord;
	startRecord.node = startNode;
	startRecord.incomingEdge = nullptr;
	startRecord.costSoFar = 0;
	startRecord.estimateToGoal = heuristic.getEstimate(startNode);

	MyQueue<NodeRecord> open;
	open.push(startRecord);

	MyQueue<NodeRecord> closed;

	NodeRecord current;
	while (open.size() > 0)
	{
		current = open.top();

		if (current.node == goal)
		{
			break;
		}

		std::list<DirectedWeightedEdge> outgoing = graph.getOutgoingEdges(current.node);

		for (int i = 0; i < outgoing.size(); i++)
		{
			DirectedWeightedEdge curEdge = outgoing.front();
			int sinkID = curEdge.sink;
			float g = curEdge.cost + current.costSoFar;
			float h = heuristic.getEstimate(sinkID);

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
			newNodeR.incomingEdge = &curEdge;
			newNodeR.estimateToGoal = g + h;

			open.push(newNodeR);
		}

		open.pop();
		closed.push(current);
	}

	Path p;
	if (current.node != goal)
	{
		return p;
	}

	while (current.node != startNode)
	{
		p.path.push_front(*current.incomingEdge);
		current = closed.get(current.incomingEdge->source);
	}
	return p;
}
