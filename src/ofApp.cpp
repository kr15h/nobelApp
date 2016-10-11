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
	
	settings->debug = false;
	debugGridStep = 100;
}

void ofApp::update(){
	laureateDisplay->update();
}

void ofApp::draw(){
	laureateDisplay->draw();
	
	if(settings->debug){
		drawDebugGrid();
		
		stringstream ss;
		ss << "frame rate: "  << ofToString(ofGetFrameRate()) << "\n"
			<< "grid step: " << ofToString(debugGridStep);
		ofDrawBitmapStringHighlight(ss.str(), 10, 20);
	}
}

void ofApp::keyPressed(int key){
	if(key == 'd'){
		settings->debug = !settings->debug;
	}else if(key == '+'){
		debugGridStep += 10;
		if(debugGridStep >= 200){
			debugGridStep = 200;
		}
	}else if(key == '-'){
		debugGridStep -= 10;
		if(debugGridStep <= 10){
			debugGridStep = 10;
		}
	}
}

void ofApp::drawDebugGrid(){
	ofPushStyle();
	ofSetColor(255);
	
	// horizontally
	for(unsigned int x = 0; x < ofGetWidth(); x += debugGridStep){
		ofDrawLine(x, 0, x, ofGetHeight());
	}
	
	// vertically
	for(unsigned int y = 0; y < ofGetHeight(); y += debugGridStep ){
		ofDrawLine(0, y, ofGetWidth(), y);
	}
	
	ofPopStyle();
}
