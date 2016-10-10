#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

namespace bmbf{
namespace nobel{

class Letter{
	public:
		void setup(shared_ptr<ofxTrueTypeFontUC> & bf);
		void update();
		void draw();
	
	private:
		shared_ptr<ofxTrueTypeFontUC> _bigFont;
	
		string _testString;
	
		vector<ofPath> _stringPaths;
		ofRectangle _stringBoundingBox;

};

} // namespace nobel
} // namespace bmbf
