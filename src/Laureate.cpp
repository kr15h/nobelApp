#include "Laureate.h"

namespace bmbf{
namespace nobel{

Laureate::Laureate(
	string first,
	string last,
	string field,
	int year,
	shared_ptr<Fonts> fonts){

	_first = first;
	_last = last;
	_field = field;
	_year = year;
	_fonts = fonts;
	
	// Setup paths
	_firstPaths = _fonts->getBigAsPaths(_first);
	_lastPaths = _fonts->getBigAsPaths(_last);
	
	// Setup bounding boxes
	_firstBoundingBox = _fonts->getBigAsBoundingBox(_first);
	_lastBoundingBox = _fonts->getBigAsBoundingBox(_last);
	
	// Field and year is a special case
	string fieldAndYear = _field + ", " + ofToString(_year);
	_fieldAndYearPaths = _fonts->getSmallAsPaths(fieldAndYear);
	_fieldAndYearBoundingBox = _fonts->getSmallAsBoundingBox(fieldAndYear);
}

void Laureate::update(){
	//
}

void Laureate::draw(){
	drawFirst();
	drawLast();
	drawFieldAndYear();
}

void Laureate::drawFirst(){
	ofPushMatrix();
	ofTranslate(
		APP_MARGIN,
		APP_MARGIN + BIG_FONT_SIZE);
	
	for(unsigned int i = 0; i < _firstPaths.size(); ++i){
		_firstPaths[i].draw();
	}
	ofPopMatrix();
}

void Laureate::drawLast(){
	ofPushMatrix();
	ofTranslate(
		APP_WIDTH - _lastBoundingBox.width - APP_MARGIN,
		APP_MARGIN + BIG_FONT_SIZE);
	
	for(unsigned int i = 0; i < _lastPaths.size(); ++i){
		_lastPaths[i].draw();
	}
	ofPopMatrix();
}

void Laureate::drawFieldAndYear(){
	ofPushMatrix();
	ofTranslate(
		APP_WIDTH - _fieldAndYearBoundingBox.width - APP_MARGIN,
		APP_HEIGHT - APP_MARGIN);
	
	for(unsigned int i = 0; i < _fieldAndYearPaths.size(); ++i){
		_fieldAndYearPaths[i].draw();
	}
	ofPopMatrix();
}

std::string Laureate::getFirst(){
	return _first;
}

std::string Laureate::getLast(){
	return _last;
}

std::string Laureate::getField(){
	return _field;
}

int Laureate::getYear(){
	return _year;
}

} // namespace nobel
} // namespace bmbf
