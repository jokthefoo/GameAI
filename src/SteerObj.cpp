#include "SteerObj.h"

void SteerObj::UpdateObj(float dt)
{
	Steering steer;
	steer.linear = DynamicArrive(rBody, *target, 25, 100, 10, 300, 1).linear;
	steer.angular = DynamicLookDir(rBody, 3.0f, 1, .1f, .9f, 1).angular;
	//steer.angular = DynamicFace(rBody, *target, 1.0f, 1, .1f, 1.8f, 1).angular;
	UpdateKinematic(dt, steer, 100, 1);
}

SteerObj::SteerObj(RigidBody* targ)
{
	target = targ;
}
