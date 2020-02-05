#include "FlockingObj.h"
#include "ofMain.h"

void FlockingObj::UpdateObj(float dt)
{
	Steering steer;
	steer.angular = 0;
	float maxLinAccel = 25;
	float maxSpd = 100;
	float targetR = 10;
	float slowR = 300;
	float timeTo = 1;
	steer.linear = DynamicArrive(rBody, target, maxLinAccel, maxSpd, targetR, slowR, timeTo).linear * .8f;

	float maxRot = 1;
	float targetA = .1f;
	float slowA = .9f;
	float maxAngAccel = 3.0f;
	steer.angular = DynamicLookDir(rBody, maxAngAccel, maxRot, targetA, slowA, timeTo).angular;

	float threshold = 500;
	float decayCoef = 5000;
	steer.linear += Seperation(rBody, targets, numTargets, threshold, decayCoef, maxLinAccel, index).linear * 3.0f;

	//target.vel = target.pos * dt;
	steer.linear += VelocityMatch(rBody, target, maxLinAccel, timeTo).linear * .6f;

	if (steer.linear.Mag() > maxLinAccel)
	{
		steer.linear.Normalize();
		steer.linear *= maxLinAccel;
	}

	if (abs(steer.angular) > maxAngAccel)
	{
		steer.angular /= abs(steer.angular);
		steer.angular *= maxAngAccel;
	}

	if (leader)
	{
		float wanderOffset = 45;
		float wanderRadius = 90;
		float wanderRate = 30;
		steer = Wander(rBody, wanderOffset, wanderRadius, wanderRate, 2, maxAngAccel, maxRot, targetA, slowA, timeTo, &wanderOrien);

		if (rBody.pos.x > ofGetWindowWidth() || rBody.pos.x < 0 || rBody.pos.y > ofGetWindowHeight() || rBody.pos.y < 0)
		{
			RigidBody target;
			target.pos.x = ofRandomWidth();
			target.pos.y = ofRandomHeight();
			steer.linear = DynamicArrive(rBody, target, maxLinAccel, maxSpd, targetR, slowR, timeTo).linear;
			steer.angular = DynamicLookDir(rBody, maxAngAccel, maxRot, targetA, slowA, timeTo).angular;
		}
	}

	UpdateKinematic(dt, steer, 100, 1);
}

FlockingObj::FlockingObj(float x, float y)
{
	rBody.pos.x = x;
	rBody.pos.y = y;
}

FlockingObj::FlockingObj()
{
	leader = false;
	mass = 1;
	rBody.pos.x = 0;
	rBody.pos.y = 0;
}
