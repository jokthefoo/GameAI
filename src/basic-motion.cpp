#include "basic-motion.h"
#include "Boid.h"

namespace basic
{
	Boid* b;
	Steering steer;
	Vector2 bred[100];
	int bredNum;
	float bredTime = 0;
	int state = 0;

	//--------------------------------------------------------------
	void basicMotion::setup() {
		ofBackground(51, 153, 255);
		b = new Boid(50, ofGetWindowHeight() - 50);
	}

	//--------------------------------------------------------------
	void basicMotion::update() {
		b->UpdateKinematic(ofGetLastFrameTime(), steer);

		switch (state)
		{
		case 0:
			b->rBody.vel.x = 100;
			b->rBody.vel.y = 0;
			break;
		case 1:
			b->rBody.vel.x = 0;
			b->rBody.vel.y = -100;
			break;
		case 2:
			b->rBody.vel.x = -100;
			b->rBody.vel.y = 0;
			break;
		case 3:
			b->rBody.vel.x = 0;
			b->rBody.vel.y = 100;
			break;
		default:
			b->rBody.vel = Vector2();
		}

		if (state == 0 && b->rBody.pos.x > ofGetWindowWidth() - 50
			|| state == 1 && b->rBody.pos.y < 50
			|| state == 2 && b->rBody.pos.x < 50
			|| state == 3 && b->rBody.pos.y > ofGetWindowHeight() - 50)
		{
			state++;
		}
		if (state == 4)
		{
			state = 0;
		}

		bredTime += ofGetLastFrameTime();
		if (bredTime > .3)
		{
			bredNum++;
			if (bredNum > 99)
			{
				bredNum = 0;
			}
			bred[bredNum].x = b->rBody.pos.x;
			bred[bredNum].y = b->rBody.pos.y;
			bredTime = 0;
		}
	}

	//--------------------------------------------------------------
	void basicMotion::draw() {
		b->DrawBoid();
		for (int i = 0; i < 100; i++)
		{
			ofDrawCircle(bred[i].x, bred[i].y, 5);
		}
	}

	//--------------------------------------------------------------
	void basicMotion::keyPressed(int key) {
		/*
		if (key == 119)
		{
			b->rBody.vel.y = -100;
		}

		if (key == 115)
		{
			b->rBody.vel.y = 100;
		}

		if (key == 100)
		{
			b->rBody.vel.x = 100;
		}

		if (key == 97)
		{
			b->rBody.vel.x = -100;
		}*/
	}

	//--------------------------------------------------------------
	void basicMotion::keyReleased(int key) {
		/*
		if (key == 119)
		{
			b->rBody.vel.y = 0;
		}

		if (key == 115)
		{
			b->rBody.vel.y = 0;
		}

		if (key == 100)
		{
			b->rBody.vel.x = 0;
		}

		if (key == 97)
		{
			b->rBody.vel.x = 0;
		}*/
	}

	//--------------------------------------------------------------
	void basicMotion::mouseMoved(int x, int y) {

	}

	//--------------------------------------------------------------
	void basicMotion::mouseDragged(int x, int y, int button) {

	}

	//--------------------------------------------------------------
	void basicMotion::mousePressed(int x, int y, int button) {

	}

	//--------------------------------------------------------------
	void basicMotion::mouseReleased(int x, int y, int button) {

	}

	//--------------------------------------------------------------
	void basicMotion::mouseEntered(int x, int y) {

	}

	//--------------------------------------------------------------
	void basicMotion::mouseExited(int x, int y) {

	}

	//--------------------------------------------------------------
	void basicMotion::windowResized(int w, int h) {

	}

	//--------------------------------------------------------------
	void basicMotion::gotMessage(ofMessage msg) {

	}

	//--------------------------------------------------------------
	void basicMotion::dragEvent(ofDragInfo dragInfo) {

	}
}