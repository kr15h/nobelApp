#include "Letter.h"

void Letter::setup(shared_ptr<ofxTrueTypeFontUC> & bf){
	_bigFont = bf;
}

void Letter::update(){
	//
}

void Letter::draw(){
	_bigFont->drawString("Yes", 20, 20 + _bigFont->getLineHeight());
}
