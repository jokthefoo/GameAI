#include "WanderObj.h"

void WanderObj::UpdateObj(float dt)
{
	Steering steer;
	float wanderOffset = 10;
	float wanderRadius = 90;
	float wanderRate = 30;
	float maxLinAccel = 10;
	float maxAngAccel = 10;
	float maxRot = 100;
	float targetA = .1;
	float slowA = .9;
	float timeTo = 1;
	steer = Wander(rBody, wanderOffset, wanderRadius, wanderRate, maxLinAccel, maxAngAccel, maxRot, targetA, slowA, timeTo, &wanderOrien);

	if (rBody.pos.x > ofGetWindowWidth() || rBody.pos.x < 0 || rBody.pos.y > ofGetWindowHeight() || rBody.pos.y < 0)
	{
		RigidBody target;
		target.pos.x = ofRandomWidth();
		target.pos.y = ofRandomHeight();
		steer.linear = DynamicArrive(rBody, target, 25, 100, 10, 300, 1).linear;
		steer.angular = DynamicLookDir(rBody, 3.0f, 1, .1f, .9f, 1).angular;
	}

	UpdateKinematic(dt, steer, 100, 1);
}

WanderObj::WanderObj()
{
	wanderOrien = 0;
	rBody.pos.x = 50;
	rBody.pos.y = 50;
}
