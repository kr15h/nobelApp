#include "Laureate.h"

namespace bmbf{
namespace nobel{

Laureate::Laureate(
	string first,
	string last,
	string field,
	int year,
	int age,
	shared_ptr<Fonts> fonts){

	_first = first;
	_last = last;
	_field = field;
	_year = year;
	_age = age;
	_fonts = fonts;
	
	// Setup paths
	_firstPaths = _fonts->getBigAsPaths(_first);
	_yearPaths = _fonts->getSmallAsPaths(ofToString(_year));
}

void Laureate::draw(){
	ofPushMatrix();
	ofTranslate(20, 100);
	for(unsigned int i = 0; i < _firstPaths.size(); ++i){
		_firstPaths[i].draw();
	}
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(20, 200);
	for(unsigned int i = 0; i < _yearPaths.size(); ++i){
		_yearPaths[i].draw();
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

int Laureate::getAge(){
	return _age;
}

} // namespace nobel
} // namespace bmbf
