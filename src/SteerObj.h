#pragma once
#include "Boid.h"
#include "BasicAI.h"

class SteerObj : public Boid {

public:
	RigidBody* target;
	void UpdateObj(float dt);
	SteerObj(RigidBody*);
};