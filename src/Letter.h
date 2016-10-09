#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class Letter{
	public:
		void setup(shared_ptr<ofxTrueTypeFontUC> & bf);
		void update();
		void draw();
	
	private:
		shared_ptr<ofxTrueTypeFontUC> _bigFont;
};