#include "SteerObj.h"

void SteerObj::UpdateObj(float dt)
{
	Steering steer;
	steer.linear = DynamicSeek(rBody, *target, 25).linear;
	steer.angular = DynamicLookDir(rBody, 3.0f, 1, .1f, .9f, 1).angular;
	//steer.angular = DynamicFace(rBody, *target, 1.0f, 1, .1f, 1.8f, 1).angular;
	UpdateKinematic(dt, steer, 100, 1);
}

SteerObj::SteerObj(RigidBody* targ)
{
	target = targ;
}
