#pragma once

#include "ofMain.h"

#include "ofxXmlSettings.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxPiMapper.h"

#include "Constants.h"
#include "Settings.h"
#include "Fonts.h"
#include "Laureate.h"
#include "LaureateDisplay.h"
#include "StrobeElements.h"

#include "MappingSource.h"
#include "BackgroundSource.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
	
		shared_ptr<bmbf::nobel::Settings> settings;
		shared_ptr<bmbf::nobel::Fonts> fonts;
		shared_ptr<bmbf::nobel::LaureateDisplay> laureateDisplay;
		shared_ptr<bmbf::nobel::StrobeElements> strobeElements;
	
		int debugGridStep;
	
		ofxPiMapper mapper;
	
		MappingSource mappingSource;
		bmbf::nobel::BackgroundSource backgroundSource;
};
