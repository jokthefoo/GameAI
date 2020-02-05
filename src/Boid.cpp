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
	BoidWrap();
	GhostBoid();

	ofPushMatrix();

	ofTranslate(rBody.pos.x, rBody.pos.y);

	ofSetColor(0, 0, 0);
	ofDrawCircle(0, 0, 26);
	ofRotateZRad(rBody.orien);
	ofDrawTriangle(0, -26, 41, 0, 0, 26);

	ofSetColor(c);
	ofDrawCircle(0, 0, 25);
	ofDrawTriangle(0, - 25, 40, 0, 0, 25);

	ofPopMatrix();
}

void Boid::BoidWrap()
{
	int x = 0;
	int y = 0;
	if (rBody.pos.x > ofGetWindowWidth())
	{
		x = 1;
	}
	else if (rBody.pos.x < 0)
	{
		x = -1;
	}

	if (rBody.pos.y > ofGetWindowHeight())
	{
		y = 1;
	}
	else if (rBody.pos.y < 0)
	{
		y = -1;
	}
	rBody.pos.x -= x * ofGetWindowWidth();
	rBody.pos.y -= y * ofGetWindowHeight();
}

void Boid::GhostBoid()
{
	int x = 0;
	int y = 0;
	if (rBody.pos.x > ofGetWindowWidth() - 50)
	{
		x = 1;
	}
	else if (rBody.pos.x < 50)
	{
		x = -1;
	}

	if (rBody.pos.y > ofGetWindowHeight() - 50)
	{
		y = 1;
	}
	else if (rBody.pos.y < 50)
	{
		y = -1;
	}


	ofPushMatrix();

	ofTranslate(rBody.pos.x - (x * ofGetWindowWidth()), rBody.pos.y - (y * ofGetWindowHeight()));

	ofSetColor(0, 0, 0);
	ofDrawCircle(0, 0, 26);
	ofRotateZRad(rBody.orien);
	ofDrawTriangle(0, -26, 41, 0, 0, 26);

	ofSetColor(c);
	ofDrawCircle(0, 0, 25);
	ofDrawTriangle(0, -25, 40, 0, 0, 25);

	ofPopMatrix();
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
