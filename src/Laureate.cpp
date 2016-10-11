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
	_targetState = _defaultState;
}

void Laureate::update(){
	
	// Interpolate between current and target states.
	/*
	for(unsigned int i = 0; i < _currentState.firstPaths.size(); ++i){
		_currentState.firstPaths[i] = ipolatePath(
			_currentState.firstPaths[i],
			_targetState.firstPaths[i],
			ANIMATION_MULTIPLIER);
	}
	*/
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
	
	for(unsigned int i = 0; i < _currentState.firstPaths.size(); ++i){
		_currentState.firstPaths[i].draw();
	}
	
	/*
	for(unsigned int i = 0; i < _defaultState.firstPaths.size(); ++i){
		ofPath newPath = randomizePath(
			_defaultState.firstPaths[i],
			-(float)APP_MARGIN,
			-(float)(APP_MARGIN + BIG_FONT_SIZE));
		newPath.draw();
	}
	*/
	
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

	// Randomize first name path. Taking into account the offsets for it.
	for(unsigned int i = 0; i < _targetState.firstPaths.size(); ++i){
		ofPath newPath = randomizePath(
			_targetState.firstPaths[i],
			-(float)APP_MARGIN,
			-(float)(APP_MARGIN + BIG_FONT_SIZE));
		_targetState.firstPaths[i] = newPath;
	}
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

ofPath Laureate::ipolatePath(ofPath from, ofPath to, float m){
	vector<ofPath::Command> controlsFrom = from.getCommands();
	vector<ofPath::Command> controlsTo = to.getCommands();

	ofPath newPath = to;
    newPath.clear(); // clears path but keeps properties like color, stroke...
    
    // build new path according to actual path's control points properties
    for (int i = 0; i < controlsTo.size(); i++) {
        switch (controlsTo[i].type) {
            case ofPath::Command::moveTo:
			
				/*
				ofPoint distance = controlsTo[i].to - controlsFrom[i].to;
				distance *= m;
				controlsFrom[i].to = controlsTo[i].to - distance;
				*/
				
                newPath.moveTo( controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m );
                break;
            case ofPath::Command::lineTo:
                newPath.lineTo( controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m );
                break;
            case ofPath::Command::curveTo:
                newPath.curveTo( controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m );
                break;
            case ofPath::Command::bezierTo:
                newPath.bezierTo(
					controlsTo[i].cp1,
					controlsTo[i].cp2,
					controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m );
                break;
            case ofPath::Command::quadBezierTo:
                newPath.quadBezierTo(
					controlsTo[i].cp1,
					controlsTo[i].cp2,
					controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m );
                break;
            case ofPath::Command::arc:
                newPath.arc(
					controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m,
					controlsTo[i].radiusX,
					controlsTo[i].radiusY,
					controlsTo[i].angleBegin,
					controlsTo[i].angleEnd,
					controlsTo[i].arc);
                break;
            case ofPath::Command::arcNegative:
                newPath.arc(
					controlsTo[i].to - (controlsTo[i].to - controlsFrom[i].to) * m,
					controlsTo[i].radiusX,
					controlsTo[i].radiusY,
					controlsTo[i].angleBegin,
					controlsTo[i].angleEnd,
					controlsTo[i].arcNegative);
                break;
            case ofPath::Command::close:
                newPath.close();
                break;
            default:
                break;
        } // switch
    } // for

	return newPath;
}

ofPoint Laureate::randomPoint(float offsetX, float offsetY){
	return ofPoint(
		ofRandom((float)APP_WIDTH) + offsetX,
		ofRandom((float)APP_HEIGHT) + offsetY);
}

} // namespace nobel
} // namespace bmbf
