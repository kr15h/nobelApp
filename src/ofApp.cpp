#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(true);
	
	// Load fonts for sharing among components
	fonts = make_shared<bmbf::nobel::Fonts>();
	fonts->load(
		string(BOLD_FONT_PATH),
		int(BIG_FONT_SIZE),
		string(REGULAR_FONT_PATH),
		int(SMALL_FONT_SIZE));
	
	// Create shareable settings object and load laureate data
	settings = make_shared<bmbf::nobel::Settings>();
	bmbf::nobel::Data data = settings->load(string(XML_SETTINGS_FILENAME), fonts);
	
	// Create laureate display for displaying laureates one by one
	laureateDisplay = make_shared<bmbf::nobel::LaureateDisplay>(data, fonts);
}

void ofApp::update(){
	laureateDisplay->update();
}

void ofApp::draw(){
	laureateDisplay->draw();
}

void ofApp::keyPressed(int key){
	if(key == 'd'){
		laureateDisplay->dissolve();
	}
}