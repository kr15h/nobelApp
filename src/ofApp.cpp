#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(true);
	
	settings = make_shared<bmbf::nobel::Settings>();
	settings->load(string(XML_SETTINGS_FILENAME));
	
	fonts = make_shared<bmbf::nobel::Fonts>();
	fonts->load(
		string(REGULAR_FONT_PATH),
		int(BIG_FONT_SIZE),
		string(REGULAR_FONT_PATH),
		int(SMALL_FONT_SIZE));
	
	// Setup letters / words
	letter.setup(fonts);
}

void ofApp::update(){
	letter.update();
}

void ofApp::draw(){
	letter.draw();
}