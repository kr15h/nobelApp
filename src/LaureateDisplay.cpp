#include "LaureateDisplay.h"

namespace bmbf{
namespace nobel{

LaureateDisplay::LaureateDisplay(Data data, shared_ptr<Fonts> fonts){
	_data = data;
	_fonts = fonts;
	_titlePaths = _fonts->getSmallAsPaths(_data.title);
	_laureateIndex = 0;
	_lastTriggerTime = 0.0f;
	
	_state = DisplayState::SHOWING;
}

void LaureateDisplay::update(){
	_data.laureates[_laureateIndex]->update();
	
	float timeNow = ofGetElapsedTimef();
	
	if(_state == DisplayState::SHOWING){
		if(timeNow - _lastTriggerTime > LAUREATE_INTERVAL){
			_state = DisplayState::STROBING;
			_strobeTime = MIN_STROBE_TIME + ofRandom(STROBE_TIME_RANDOM_RANGE);
		}
	}else{ // if _state == DisplayState::STROBING
		nextLaureate();
		if(timeNow - _lastTriggerTime > LAUREATE_INTERVAL + _strobeTime){
			_state = DisplayState::SHOWING;
			_lastTriggerTime = timeNow;
		}
	}
}

void LaureateDisplay::draw(){
	_data.laureates[_laureateIndex]->draw();
	
	ofPushMatrix();
	ofTranslate(APP_MARGIN, APP_HEIGHT - APP_MARGIN);
	for(unsigned int i = 0; i < _titlePaths.size(); ++i){
		_titlePaths[i].draw();
	}
	ofPopMatrix();
}

void LaureateDisplay::dissolve(){
	_data.laureates[_laureateIndex]->dissolve();
}

void LaureateDisplay::nextLaureate(){
	_laureateIndex++;
	if(_laureateIndex >= _data.laureates.size()){
		_laureateIndex = 0;
	}
}

} // namespace nobel
} // namespace bmbf