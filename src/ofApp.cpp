#include "ofApp.h"
#include "SteerObj.h"

SteerObj* b;
Vector2 bred [100];
RigidBody target;
int bredNum;
float bredTime = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(51, 153, 255);
	target.pos.x = ofGetWindowWidth() / 2.0f;
	target.pos.y = ofGetWindowHeight() / 2.0f;
	b = new SteerObj(&target);
}

//--------------------------------------------------------------
void ofApp::update(){
	b->UpdateObj(ofGetLastFrameTime());

	bredTime += ofGetLastFrameTime();
	if (bredTime > .3)
	{
		bredNum++;
		if (bredNum > 19)
		{
			bredNum = 0;
		}
		bred[bredNum].x = b->rBody.pos.x;
		bred[bredNum].y = b->rBody.pos.y;
		bredTime = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
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
