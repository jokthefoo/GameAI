#include "BasicAI.h"

Steering DynamicSeek(RigidBody character, RigidBody target, float maxAccel)
{
	Steering steer;
	Vector2 dir = target.pos - character.pos;
	dir.Normalize();
	dir *= maxAccel;
	steer.linear = dir;
	steer.angular = 0;
	return steer;
}

Steering DynamicAlign(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget)
{
	Steering steer;

	float targetR;

	float diffOrien = target.orien - character.orien;
	if (diffOrien < -PI)
	{
		while (diffOrien < -PI)
		{
			diffOrien += 2 * PI;
		}
	}
	else
	{
		while (diffOrien > PI)
		{
			diffOrien -= 2 * PI;
		}
	}

	if (diffOrien > slowA || diffOrien < -slowA)
	{ 
		targetR = maxAngAccel;
	}
	else if (diffOrien < targetA && diffOrien > -targetA)
	{
		targetR = 0;
	}
	else
	{
		float fact = diffOrien / slowA;
		float magA = maxAngAccel * fact;
		targetR = magA;
	}
	targetR /= timeToTarget;

	if (targetR > maxAngAccel)
	{
		targetR = maxAngAccel;
	}
	else if (targetR < -maxAngAccel)
	{
		targetR = -maxAngAccel;
	}

	steer.angular = targetR;
	steer.linear = Vector2();
	return steer;
}

Steering DynamicLookDir(RigidBody character, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget)
{
	Steering steer;

	if (character.vel.Mag() == 0)
	{
		steer.angular = 0;
		steer.linear = Vector2();
	}
	else
	{
		RigidBody charDir;
		charDir.orien = atan2f(character.vel.y, character.vel.x);
		steer = DynamicAlign(character, charDir, maxAngAccel, maxRot, targetA, slowA, timeToTarget);
	}

	return steer;
}

Steering DynamicFace(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget)
{
	Steering steer;

	Vector2 dir = target.pos - character.pos;
	RigidBody targ;
	targ.orien = atan2f(dir.y, dir.x);
	steer = DynamicAlign(character, targ, maxAngAccel, maxRot, targetA, slowA, timeToTarget);

	return steer;
}
