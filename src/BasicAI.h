#pragma once
#include "RBody.h"
#include "ofMain.h"

Steering DynamicSeek(RigidBody character, RigidBody target, float maxAccel);
Steering DynamicAlign(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);
Steering DynamicLookDir(RigidBody character, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);
Steering DynamicFace(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);
Steering DynamicArrive(RigidBody character, RigidBody target, float maxLinAccel, float maxSpd, float targetR, float slowR, float timeToTarget);
Steering Wander(RigidBody character, float wanderOffset, float wanderRadius, float wanderRate, float maxLinAccel, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget, float* wanderOrien);
Steering Seperation(RigidBody character, RigidBody** targets, int numTargets, float threshold, float decayCoef, float maxLinAccel, int ignoreIndex);
Steering VelocityMatch(RigidBody character, RigidBody target, float maxLinAccel, float timeToTarget);
Vector2 OrientationToVec(float);