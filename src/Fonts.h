#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#include "Constants.h"

namespace bmbf{
namespace nobel{

class Fonts{
	public:
		void load(
			string bigFontPath,
			int bigFontSize,
			string smallFontPath,
			int smallFontSize);
	
		vector<ofPath> getBigAsPaths(string text = "A");
		vector<ofPath> getSmallAsPaths(string text = "B");
	
		ofRectangle getBigAsBoundingBox(string text = "A");
		ofRectangle getSmallAsBoundingBox(string text = "B");
	
	private:
		ofxTrueTypeFontUC _fontBig;
		ofxTrueTypeFontUC _fontSmall;
	
};

} // namespace nobel
} // namespace bmbf
