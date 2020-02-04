#pragma once
#include "Boid.h"
#include "BasicAI.h"

class FlockingObj : public Boid {

public:
	bool leader;
	float wanderOrien;
	RigidBody** targets;
	int numTargets;
	RigidBody target;
	float mass;
	int index;
	void UpdateObj(float dt);
	FlockingObj(float x, float y);
	FlockingObj();
};