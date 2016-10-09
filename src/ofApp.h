#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

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
};
