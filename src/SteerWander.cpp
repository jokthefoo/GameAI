#include "SteerWander.h"
#include "SteerObj.h"
#include "WanderObj.h"

namespace SteerWander
{
	SteerObj* b;
	//WanderObj* b;
	Vector2 bred[100];
	RigidBody target;
	int bredNum;
	float bredTime = 0;

	//--------------------------------------------------------------
	void SteerWander::setup() {
		ofBackground(51, 153, 255);
		target.pos.x = ofGetWindowWidth() / 2.0f;
		target.pos.y = ofGetWindowHeight() / 2.0f;
		b = new SteerObj(&target);
		//b = new WanderObj();
	}

	//--------------------------------------------------------------
	void SteerWander::update() {
		b->UpdateObj(ofGetLastFrameTime());

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
	void SteerWander::draw() {
		// Draw dots
		for (int i = 0; i < 100; i++)
		{
			ofDrawCircle(bred[i].x, bred[i].y, 5);
		}

		// Draw target circle
		ofSetColor(ofColor(255, 0, 0));
		ofDrawCircle(target.pos.x, target.pos.y, 15);
		ofSetColor(ofColor(0, 0, 0));
		ofDrawCircle(target.pos.x, target.pos.y, 12);
		ofSetColor(ofColor(255, 0, 0));
		ofDrawCircle(target.pos.x, target.pos.y, 9);
		ofSetColor(ofColor(0, 0, 0));
		ofDrawCircle(target.pos.x, target.pos.y, 6);
		ofSetColor(ofColor(255, 0, 0));
		ofDrawCircle(target.pos.x, target.pos.y, 3);


		b->DrawBoid();
	}

	//--------------------------------------------------------------
	void SteerWander::keyPressed(int key) {

	}

	//--------------------------------------------------------------
	void SteerWander::keyReleased(int key) {

	}

	//--------------------------------------------------------------
	void SteerWander::mouseMoved(int x, int y) {

	}

	//--------------------------------------------------------------
	void SteerWander::mouseDragged(int x, int y, int button) {

	}

	//--------------------------------------------------------------
	void SteerWander::mousePressed(int x, int y, int button) {
		target.pos.x = x;
		target.pos.y = y;
	}

	//--------------------------------------------------------------
	void SteerWander::mouseReleased(int x, int y, int button) {

	}

	//--------------------------------------------------------------
	void SteerWander::mouseEntered(int x, int y) {

	}

	//--------------------------------------------------------------
	void SteerWander::mouseExited(int x, int y) {

	}

	//--------------------------------------------------------------
	void SteerWander::windowResized(int w, int h) {

	}

	//--------------------------------------------------------------
	void SteerWander::gotMessage(ofMessage msg) {

	}

	//--------------------------------------------------------------
	void SteerWander::dragEvent(ofDragInfo dragInfo) {

	}
}