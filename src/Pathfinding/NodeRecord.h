#pragma once
#include "DirectedWeightedEdge.h"

struct NodeRecord
{
	int node;
	DirectedWeightedEdge* incomingEdge;
	float costSoFar;
	float estimateToGoal;
};