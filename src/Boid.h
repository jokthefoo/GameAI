#pragma once

#include "ofMain.h"
#include "RBody.h"

class Boid {

public:
	RigidBody rBody;
	ofColor c;

	Boid(float = 0, float = 0, ofColor = ofColor(255,255,255));
	void DrawBoid();
	void UpdatePos(float x, float y);
	void UpdateOrientation(float a);
	void UpdateKinematic(float dt, Steering steer, float maxVel = 1000.0, float maxRot = 1000.0);
};