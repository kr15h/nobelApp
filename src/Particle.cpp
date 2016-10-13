#include "Particle.h"

namespace bmbf{
namespace nobel{

Particle::Particle(){
	_settings = 0;
	_position = ofVec2f(0.0f, 0.0f);
	_speed = ofVec2f(0.0f, 0.0f);
	_size = 5.0f;
}

void Particle::setup(){
	_position = ofVec2f(ofRandom(APP_WIDTH), ofRandom(APP_HEIGHT));
	_speed = ofVec2f(ofRandom(6.0f) - 3.0f, ofRandom(6.0f) - 3.0f);
	_size = 25.0f + ofRandom(50.0f);
}

void Particle::update(){
	_position += _speed;
	
	if(_position.x - _size / 2.0f > APP_WIDTH){
		_position.x = -_size / 2.0f;
	}
	
	if(_position.y - _size / 2.0f > APP_HEIGHT){
		_position.y = -_size / 2.0f;
	}
}

void Particle::draw(){
	ofPushStyle();
	ofSetColor(255, 255, 255, _settings->backgroundAlpha);
	
	shared_ptr<ofImage> i = 0;
	if(_settings->currentField == Settings::Field::CHEMISTRY){
		i = _chemistryImage;
	}else if(_settings->currentField == Settings::Field::ECONOMICS){
		i = _economicsImage;
	}else if(_settings->currentField == Settings::Field::LITERATURE){
		i = _literatureImage;
	}else if(_settings->currentField == Settings::Field::MEDICINE){
		i = _medicineImage;
	}else if(_settings->currentField == Settings::Field::PHYSICS){
		i = _physicsImage;
	}
	
	i->draw(
		_position.x - _size / 2.0f,
		_position.y - _size / 2.0f,
		_size,
		_size);
	
	//ofDrawCircle(_position.x, _position.y, _size);
	ofPopStyle();
}

void Particle::setSettings(shared_ptr<bmbf::nobel::Settings> s){
	_settings = s;
}

void Particle::setImages(
	shared_ptr<ofImage> chem,
	shared_ptr<ofImage> econ,
	shared_ptr<ofImage> lite,
	shared_ptr<ofImage> medi,
	shared_ptr<ofImage> phys){
	
	_chemistryImage = chem;
	_economicsImage = econ;
	_literatureImage = lite;
	_medicineImage = medi;
	_physicsImage = phys;
}

} // namespace nobel
} // namespace bmbf