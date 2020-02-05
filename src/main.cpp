#include "ofMain.h"
#include "basic-motion.h"
#include "SteerWander.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new basic::basicMotion());
	//ofRunApp(new SteerWander::SteerWander());
	ofRunApp(new ofApp());

}
