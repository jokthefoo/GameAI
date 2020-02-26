#pragma once
#include "Path.h"
#include "DirectedGraph.h"
#include "DirectedWeightedEdge.h"
#include "NodeRecord.h"
#include "Heuristic.h"

Path pathfindingAStar(DirectedGraph graph, int startNode, int goal, Heuristic heuristic)
{
	NodeRecord startRecord;
	startRecord.node = startNode;
	startRecord.incomingEdge = nullptr;
	startRecord.costSoFar = 0;
	startRecord.estimateToGoal = heuristic.getEstimate(startNode);

	open = new PathfindingList();
	open.Add(startRecord);

	closed = new PathfindingList();

	NodeRecord current;
	while (open.Length > 0)
	{
		current = open.Pop();

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

			if (closed.Contains(sinkID))
			{
				NodeRecord vistedNR = closed.Get(sinkID);
				if (vistedNR.costSoFar <= g)
				{
					continue;
				}

				closed.Remove(sinkID);
			}
			else if (open.Contains(sinkID))
			{
				NodeRecord vistedNR = open.Get(sinkID);
				if (vistedNR.costSoFar <= g)
				{
					continue;
				}
			}

			NodeRecord newNodeR;
			newNodeR.node = sinkID;
			newNodeR.incomingEdge = &curEdge;
			newNodeR.estimateToGoal = g + h;

			open.Add(newNodeR);
		}

		open.Remove(current);
		closed.Add(current);
	}

	Path p;
	if (current.node != goal)
	{
		return p;
	}

	while (current.node != startNode)
	{
		p.path.push_front(*current.incomingEdge);
		current = closed.Find(current.incomingEdge->source);
	}
	return p;
}
