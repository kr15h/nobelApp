#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

class Letter{
	public:
		void setup(shared_ptr<Fonts> fonts);
		void update();
		void draw();
	
	private:
		shared_ptr<Fonts> _fonts;
	
		string _testString;
	
		vector<ofPath> _stringPaths;
		ofRectangle _stringBoundingBox;

};

} // namespace nobel
} // namespace bmbf
