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

	float diffOrienMag = abs(diffOrien);

	if (diffOrienMag > slowA )
	{ 
		targetR = maxRot;
	}
	else if (diffOrienMag < targetA)
	{
		steer.angular = 0;
		steer.linear = Vector2();
		return steer;
	}
	else
	{
		targetR = maxRot * diffOrienMag / slowA;
	}
	targetR *= diffOrien / diffOrienMag;
	targetR -= character.rot;
	targetR /= timeToTarget;

	if (abs(targetR) > maxAngAccel)
	{
		targetR /= abs(targetR);
		targetR *= maxAngAccel;
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

Steering DynamicArrive(RigidBody character, RigidBody target, float maxLinAccel, float maxSpd, float targetR, float slowR, float timeToTarget)
{
	Steering steer;

	float targetSpeed;
	Vector2 dir = target.pos - character.pos;
	float dist = dir.Mag();

	if (dist > slowR)
	{
		targetSpeed = maxSpd;
	}
	else if (dist < targetR)
	{
		steer.linear = Vector2();
		steer.angular = 0;
		return steer;
	}
	else
	{
		targetSpeed = maxSpd * dist / slowR;
	}

	dir.Normalize();
	Vector2 targetVel = dir * targetSpeed;
	targetVel -= character.vel;
	targetVel /= timeToTarget;

	if (targetVel.Mag() > maxLinAccel)
	{
		targetVel.Normalize();
		targetVel *= maxLinAccel;
	}

	steer.linear = targetVel;
	steer.angular = 0;
	return steer;
}
