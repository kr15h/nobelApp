#include "BackgroundSource.h"

namespace bmbf{
namespace nobel{

BackgroundSource::BackgroundSource(){
	name = "Background";
	_settings = 0;
}

void BackgroundSource::setup(){
	allocate(APP_WIDTH, APP_HEIGHT);
}

void BackgroundSource::update(){
	//
}

void BackgroundSource::draw(){
	ofClear(0);
	ofPushStyle();
	ofSetColor(0, 255, 255);
	ofSetLineWidth(2);
	ofNoFill();
	ofDrawRectangle(1, 1, APP_WIDTH - 2, APP_HEIGHT - 2);
	ofDrawLine(0, 0, APP_WIDTH, APP_HEIGHT);
	ofDrawLine(APP_WIDTH, 0, 0, APP_HEIGHT);
	ofPopStyle();
}

void BackgroundSource::setSettings(shared_ptr<bmbf::nobel::Settings> s){
	_settings = s;
}

} // namespace nobel
} // namespace bmbf
