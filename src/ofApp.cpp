#include "ofApp.h"
#include "FlockingObj.h"

const int flockSize = 30;
FlockingObj flock[flockSize];
RigidBody* flockBodies[flockSize];
RigidBody target;
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(51, 153, 255);
	for (int i = 0; i < flockSize; i++)
	{
		flockBodies[i] = &flock[i].rBody;
	}
	for (int i = 0; i < flockSize; i++)
	{
		flock[i].index = i;
		flock[i].numTargets = flockSize;
		flock[i].targets = flockBodies;
		flock[i].UpdatePos(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	}
	flock[0].leader = true;
	flock[0].mass = 300;
	flock[0].c = ofColor(0, 255, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	RigidBody centerOfMass;
	float massTot = 0;
	for (int i = 0; i < flockSize; i++)
	{
		centerOfMass.pos += flock[i].rBody.pos * flock[i].mass;
		massTot += flock[i].mass;
	}
	centerOfMass.pos /= massTot;

	for (int i = 0; i < flockSize; i++)
	{
		flock[i].target = centerOfMass;
		if (i == 0)
		{
			flock[i].target = target;
		}
		flock[i].UpdateObj(ofGetLastFrameTime());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

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


	for (int i = 0; i < flockSize; i++)
	{
		flock[i].DrawBoid();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	target.pos.x = x;
	target.pos.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
