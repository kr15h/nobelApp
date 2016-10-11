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
	
	string fieldAndYear = _field + ", " + ofToString(_year);
	
	// Setup default paths
	_defaultState.firstPaths = _fonts->getBigAsPaths(_first);
	_defaultState.lastPaths = _fonts->getBigAsPaths(_last);
	_defaultState.fieldAndYearPaths = _fonts->getSmallAsPaths(fieldAndYear);
	
	// Setup bounding boxes
	_firstBoundingBox = _fonts->getBigAsBoundingBox(_first);
	_lastBoundingBox = _fonts->getBigAsBoundingBox(_last);
	_fieldAndYearBoundingBox = _fonts->getSmallAsBoundingBox(fieldAndYear);
	
	// Polylines
	for(unsigned int i = 0; i < _defaultState.firstPaths.size(); ++i){
		vector<ofPolyline> p = _defaultState.firstPaths[i].getOutline();
		for(unsigned int j = 0; j < p.size(); ++j){
			_defaultState.firstPolylines.push_back(p[j]);
		}
	}
	
	_currentState = _defaultState;
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

	for(unsigned int i = 0; i < _defaultState.firstPaths.size(); ++i){
		ofPath newPath = randomizePath(
			_defaultState.firstPaths[i],
			-(float)APP_MARGIN,
			-(float)(APP_MARGIN + BIG_FONT_SIZE));
		newPath.draw();
	}
	
	ofPopMatrix();
}

void Laureate::drawLast(){
	ofPushMatrix();
	ofTranslate(
		APP_WIDTH - _lastBoundingBox.width - APP_MARGIN,
		APP_MARGIN + BIG_FONT_SIZE);
	
	for(unsigned int i = 0; i < _currentState.lastPaths.size(); ++i){
		_currentState.lastPaths[i].draw();
	}
	ofPopMatrix();
}

void Laureate::drawFieldAndYear(){
	ofPushMatrix();
	ofTranslate(
		APP_WIDTH - _fieldAndYearBoundingBox.width - APP_MARGIN,
		APP_HEIGHT - APP_MARGIN);
	
	for(unsigned int i = 0; i < _currentState.fieldAndYearPaths.size(); ++i){
		_currentState.fieldAndYearPaths[i].draw();
	}
	ofPopMatrix();
}

void Laureate::dissolve(){
	_targetState = _defaultState;

	//for(unsigned int i = 0; i < _targetState.firstPaths.size(); ++i){
	//	_targetState.firstPaths[i]
	//}
	
	_currentState = _targetState;
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

ofPath Laureate::randomizePath(ofPath p, float offsetX, float offsetY){
	vector<ofPath::Command> controls;
	controls = p.getCommands();
		
	ofPath newPath = p;
	newPath.clear();
		
	for (int i = 0; i < controls.size(); i++) {
		switch (controls[i].type) {
			case ofPath::Command::moveTo:
				newPath.moveTo(randomPoint(offsetX, offsetY));
				break;
			case ofPath::Command::lineTo:
				newPath.lineTo(randomPoint(offsetX, offsetY));
				break;
			case ofPath::Command::curveTo:
				newPath.curveTo(randomPoint(offsetX, offsetY));
				break;
			case ofPath::Command::bezierTo:
				newPath.bezierTo(
					randomPoint(offsetX, offsetY),
					randomPoint(offsetX, offsetY),
					randomPoint(offsetX, offsetY));
				break;
			case ofPath::Command::quadBezierTo:
				newPath.quadBezierTo(
					randomPoint(offsetX, offsetY),
					randomPoint(offsetX, offsetY),
					randomPoint(offsetX, offsetY));
				break;
			case ofPath::Command::arc:
				newPath.arc(
					randomPoint(offsetX, offsetY),
					controls[i].radiusX,
					controls[i].radiusY,
					controls[i].angleBegin,
					controls[i].angleEnd,
					controls[i].arc);
					break;
			case ofPath::Command::arcNegative:
				newPath.arc(
					randomPoint(offsetX, offsetY),
					controls[i].radiusX,
					controls[i].radiusY,
					controls[i].angleBegin,
					controls[i].angleEnd,
					controls[i].arcNegative);
					break;
			case ofPath::Command::close:
				newPath.close();
				break;
			default:
				break;
		}
	}
	
	return newPath;
}

ofPoint Laureate::randomPoint(float offsetX, float offsetY){
	return ofPoint(
		ofRandom((float)APP_WIDTH) + offsetX,
		ofRandom((float)APP_HEIGHT) + offsetY);
}

} // namespace nobel
} // namespace bmbf
