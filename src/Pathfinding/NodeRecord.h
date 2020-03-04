#pragma once
#include "DirectedWeightedEdge.h"

struct NodeRecord
{
	int node;
	DirectedWeightedEdge incomingEdge;
	float costSoFar;
	float estimateToGoal;
};

inline bool operator<(const NodeRecord& lhs, const NodeRecord& rhs)
{
	return lhs.estimateToGoal < rhs.estimateToGoal;
}