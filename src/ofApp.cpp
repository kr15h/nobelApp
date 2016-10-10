#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(true);
	
	settings.load();
	
	// Load font
	shared_ptr<ofxTrueTypeFontUC> bigFont = make_shared<ofxTrueTypeFontUC>();
	bool loaded = bigFont->load(string(BIG_FONT_PATH), BIG_FONT_SIZE, true, true);
	if(!loaded){
		cout << "Could not load font" << endl;
		ofExit();
	}
	
	// Setup letters / words
	letter.setup(bigFont);
}

void ofApp::update(){
	letter.update();
}

void ofApp::draw(){
	letter.draw();
}