#pragma once

#include "ofMain.h"

#include "ofxXmlSettings.h"
#include "ofxTrueTypeFontUC.h"

#include "Constants.h"
#include "Settings.h"
#include "Letter.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		ofxXmlSettings xmlSettings;
	
		shared_ptr<ofxTrueTypeFontUC> bigFont;
	
		bmbf::nobel::Settings settings;
		bmbf::nobel::Letter letter;
};
