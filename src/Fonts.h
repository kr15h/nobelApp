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
	
		ofxTrueTypeFontUC & getBig();
		ofxTrueTypeFontUC & getSmall();
	
	private:
		ofxTrueTypeFontUC _fontBig;
		ofxTrueTypeFontUC _fontSmall;
	
};

} // namespace nobel
} // namespace bmbf
