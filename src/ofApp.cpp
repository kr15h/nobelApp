#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(true);
	
	fonts = make_shared<bmbf::nobel::Fonts>();
	fonts->load(
		string(REGULAR_FONT_PATH),
		int(BIG_FONT_SIZE),
		string(REGULAR_FONT_PATH),
		int(SMALL_FONT_SIZE));
	
	settings = make_shared<bmbf::nobel::Settings>();
	laureates = settings->load(string(XML_SETTINGS_FILENAME), fonts);
}

void ofApp::update(){

}

void ofApp::draw(){
	laureates[0]->draw();
}