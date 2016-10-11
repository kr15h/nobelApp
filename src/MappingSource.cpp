#include "MappingSource.h"

void MappingSource::setup(){
	name = "Nobel Laureates";
	allocate(APP_WIDTH, APP_HEIGHT);
}

void MappingSource::update(){
	laureateDisplay->update();
}

void MappingSource::draw(){
	ofClear(0);
	laureateDisplay->draw();
	
	if(settings->debug){
		drawDebugGrid();
	}
}

void MappingSource::drawDebugGrid(){
	ofPushStyle();
	ofSetColor(255);
	
	// horizontally
	for(unsigned int x = 0; x < ofGetWidth(); x += 100){
		ofDrawLine(x, 0, x, ofGetHeight());
	}
	
	// vertically
	for(unsigned int y = 0; y < ofGetHeight(); y += 100){
		ofDrawLine(0, y, ofGetWidth(), y);
	}
	
	ofPopStyle();
}