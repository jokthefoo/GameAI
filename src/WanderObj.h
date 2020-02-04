#pragma once
#include "Boid.h"
#include "BasicAI.h"

class WanderObj : public Boid {

public:
	float wanderOrien;
	void UpdateObj(float dt);
	WanderObj();
};