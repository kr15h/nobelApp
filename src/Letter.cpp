#include "Letter.h"

namespace bmbf{
namespace nobel{

void Letter::setup(shared_ptr<ofxTrueTypeFontUC> & bf){
	_bigFont = bf;
	
	_testString = "A";
	
	_stringPaths = _bigFont->getStringAsPoints(_testString);
	_stringBoundingBox = _bigFont->getStringBoundingBox(_testString, 0, 0);
}

void Letter::update(){
	//
}

void Letter::draw(){
	_bigFont->drawString("Yes", 20, 20 + _bigFont->getLineHeight());
	
	for(unsigned int i = 0; i < _stringPaths.size(); ++i){
		_stringPaths[i].draw(20, 200);
	}
}

} // namespace nobel
} // namespace bmbf
