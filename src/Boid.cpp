#include "Boid.h"

Boid::Boid(float xCoor, float yCoor, ofColor col)
{
	rBody.pos.x = xCoor;
	rBody.pos.y = yCoor;
	rBody.orien = 0;
	c = col;
}

void Boid::DrawBoid()
{
	ofPushMatrix();

	ofTranslate(rBody.pos.x, rBody.pos.y);

	ofSetColor(0, 0, 0);
	ofDrawCircle(0, 0, 26);
	ofRotateZRad(rBody.orien);
	ofDrawTriangle(0, -26, 41, 0, 0, 26);

	ofSetColor(c);
	ofDrawCircle(0, 0, 25);
	//ofRotateZRad(rBody.orien);
	ofDrawTriangle(0, - 25, 40, 0, 0, 25);


	ofPopMatrix();

	ofDrawCircle(rBody.pos.x, rBody.pos.y, 5);
}

void Boid::UpdatePos(float x, float y)
{
	rBody.pos.x = x;
	rBody.pos.y = y;
}

void Boid::UpdateOrientation(float r)
{
	rBody.orien = r;
}

void Boid::UpdateKinematic(float dt, Steering steer, float maxVel, float maxRot)
{
	rBody.pos += rBody.vel * dt;
	rBody.orien += dt * rBody.rot;

	rBody.vel += steer.linear * dt;
	if (rBody.vel.Mag() > maxVel)
	{
		rBody.vel.Normalize();
		rBody.vel *= maxVel;
	}
	rBody.rot += dt * steer.angular;
	if (rBody.rot > maxRot)
	{
		rBody.rot = maxRot;
	}
	else if (rBody.rot < -maxRot)
	{
		rBody.rot = -maxRot;
	}
}
