#pragma once
#include "RBody.h"
#include "ofMain.h"

Steering DynamicSeek(RigidBody character, RigidBody target, float maxAccel);
Steering DynamicAlign(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);
Steering DynamicLookDir(RigidBody character, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);
Steering DynamicFace(RigidBody character, RigidBody target, float maxAngAccel, float maxRot, float targetA, float slowA, float timeToTarget);