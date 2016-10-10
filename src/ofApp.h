#pragma once

#include "ofMain.h"

#include "ofxXmlSettings.h"
#include "ofxTrueTypeFontUC.h"

#include "Constants.h"
#include "Settings.h"
#include "Fonts.h"
#include "Laureate.h"
#include "LaureateDisplay.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		shared_ptr<bmbf::nobel::Settings> settings;
		shared_ptr<bmbf::nobel::Fonts> fonts;
		shared_ptr<bmbf::nobel::LaureateDisplay> laureateDisplay;
};
