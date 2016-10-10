#include "Fonts.h"

namespace bmbf{
namespace nobel{

void Fonts::load(
	string bigFontPath,
	int bigFontSize,
	string smallFontPath,
	int smallFontSize){
	
	// Load fonts with path generation and antialiasing enabled
	bool loaded = _fontBig.load(bigFontPath, bigFontSize, true, true);
	if(!loaded){
		cout << "Could not load big font " << bigFontPath << endl;
		ofExit();
	}
	
	loaded = _fontSmall.load(smallFontPath, smallFontSize, true, true);
	if(!loaded){
		cout << "Could not load small font " << smallFontPath << endl;
		ofExit();
	}
}

vector<ofPath> Fonts::getBigAsPaths(string text){
	return _fontBig.getStringAsPoints(text);
}

vector<ofPath> Fonts::getSmallAsPaths(string text){
	return _fontSmall.getStringAsPoints(text);
}

ofRectangle Fonts::getBigAsBoundingBox(string text){
	return _fontBig.getStringBoundingBox(text, 0, 0);
}

ofRectangle Fonts::getSmallAsBoundingBox(string text){
	return _fontSmall.getStringBoundingBox(text, 0, 0);
}

} // namespace nobel
} // namespace bmbf
