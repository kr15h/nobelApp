#include "StrobeElements.h"

namespace bmbf{
namespace nobel{

StrobeElements::StrobeElements(){
	x = 500.0f;
	y = 200.0f;
}

void StrobeElements::setup(){
	triggerRandomStrobe();
}

void StrobeElements::update(){
	for(unsigned int i = 0; i < _strobeRects.size(); ++i){
		_strobeRects[i].alpha -= _strobeRects[i].decay;
		
		if(_strobeRects[i].alpha <= 0.0f){
			_strobeRects.erase(_strobeRects.begin() + i);
			
			if(_strobeRects.size() <= 0){
				break;
			}else{
				--i;
				continue;
			}
		}
	}
}

void StrobeElements::draw(){
	ofPushMatrix();
	ofTranslate(x, y);

	for(unsigned int i = 0; i < _strobeRects.size(); ++i){
		ofPushStyle();
		StrobeRect * sr = &_strobeRects[i];
		ofSetColor(sr->color.r, sr->color.g, sr->color.b, sr->alpha);
		ofDrawRectangle(sr->rect);
		ofPopStyle();
	}
	
	if(_settings->debug){
		for(unsigned int i = 0; i < 8; ++i){
			ofPushStyle();
			ofSetColor(255);
			ofDrawLine(i * 50, 0, i * 50, 100);
			ofDrawBitmapString(ofToString(i), i*50 + 10, 20);
			ofPopStyle();
		}
		
		ofPushStyle();
		ofNoFill();
		ofDrawRectangle(0, 0, 8*50, 100);
		ofPopStyle();
	}
	
	ofPopMatrix();
}

void StrobeElements::triggerRandomStrobe(){
	int rand = (int)ofRandom(8);
	if(rand >= 8){
		rand = 7;
	}
	
	ofRectangle r;
	r.x = rand * 50;
	r.y = 0;
	r.width = 50;
	r.height = 100;
	
	StrobeRect sr;
	sr.rect = r;
	sr.color = ofColor(255);
	sr.alpha = 255.0f;
	sr.decay = 1.0f + ofRandom(15.0f);
	
	_strobeRects.push_back(sr);
}

void StrobeElements::setSettings(shared_ptr<bmbf::nobel::Settings> s){
	_settings = s;
}

} // namespace nobel
} // namespace bmbf