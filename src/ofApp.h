#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxTrueTypeFontUC.h"
#include "Letter.h"

#define BIG_FONT_PATH "Libre_Baskerville/LibreBaskerville-Regular.ttf"
#define BIG_FONT_SIZE 50

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		ofxXmlSettings xmlSettings;
	
		struct Laureate {
			string first;
			string last;
			string field;
			int year;
			int age;
		};
	
		vector <Laureate *> laureates;
	
		shared_ptr<ofxTrueTypeFontUC> bigFont;
	
		Letter letter;
};
