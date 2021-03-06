#include "LaureateDisplay.h"

namespace bmbf{
namespace nobel{

LaureateDisplay::LaureateDisplay(Data data, shared_ptr<Fonts> fonts){
	_data = data;
	_fonts = fonts;
	_titlePaths = _fonts->getSmallAsPaths(_data.title);
	_laureateIndex = 0;
	_lastTriggerTime = 0.0f;
	_strobeElements = 0;
	
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
	
	_strobeElements->update();
}

void LaureateDisplay::draw(){
	_data.laureates[_laureateIndex]->draw();
	
	ofPushMatrix();
	ofTranslate(APP_MARGIN, APP_HEIGHT - APP_MARGIN);
	for(unsigned int i = 0; i < _titlePaths.size(); ++i){
		_titlePaths[i].draw();
	}
	ofPopMatrix();
	
	_strobeElements->draw();
}

void LaureateDisplay::dissolve(){
	_data.laureates[_laureateIndex]->dissolve();
}

void LaureateDisplay::nextLaureate(){
	_laureateIndex++;
	if(_laureateIndex >= _data.laureates.size()){
		_laureateIndex = 0;
	}
	if(_strobeElements != 0){
		_strobeElements->triggerRandomStrobe();
	}
	
	setLaureateField();
}

void LaureateDisplay::setLaureateField(){
	if(_data.laureates[_laureateIndex]->getFieldId() == "physics"){
		_settings->currentField = Settings::Field::PHYSICS;
	}else if(_data.laureates[_laureateIndex]->getFieldId() == "economics"){
		_settings->currentField = Settings::Field::ECONOMICS;
	}else if(_data.laureates[_laureateIndex]->getFieldId() == "medicine"){
		_settings->currentField = Settings::Field::MEDICINE;
	}else if(_data.laureates[_laureateIndex]->getFieldId() == "literature"){
		_settings->currentField = Settings::Field::LITERATURE;
	}else if(_data.laureates[_laureateIndex]->getFieldId() == "chemistry"){
		_settings->currentField = Settings::Field::CHEMISTRY;
	}
}

void LaureateDisplay::setStrobeElements(shared_ptr<bmbf::nobel::StrobeElements> sr){
	_strobeElements = sr;
}

void LaureateDisplay::setSettings(shared_ptr<bmbf::nobel::Settings> s){
	_settings = s;
	if(_strobeElements != 0){
		_strobeElements->setSettings(s);
	}
	setLaureateField();
}

} // namespace nobel
} // namespace bmbf