#include "BackgroundSource.h"

namespace bmbf{
namespace nobel{

BackgroundSource::BackgroundSource(){
	name = "Background";
	
	_settings = 0;
	
	_chemistryImage = make_shared<ofImage>();
	_economicsImage = make_shared<ofImage>();
	_literatureImage = make_shared<ofImage>();
	_medicineImage = make_shared<ofImage>();
	_physicsImage = make_shared<ofImage>();
}

void BackgroundSource::setup(){
	allocate(APP_WIDTH, APP_HEIGHT);
	
	// Load images
	_chemistryImage->load("icons_Chemistry.png");
	_economicsImage->load("icons_Economics.png");
	_literatureImage->load("icons_Literature.png");
	_medicineImage->load("icons_Medicine.png");
	_physicsImage->load("icons_Physics.png");
	
	// Create particles
	_particles.clear();
	for(unsigned int i = 0; i < 50; ++i){
		Particle p;
		p.setSettings(_settings);
		p.setImages(
			_chemistryImage,
			_economicsImage,
			_literatureImage,
			_medicineImage,
			_physicsImage);
		p.setup();
		_particles.push_back(p);
	}
	
	// Create debug grid texture for increased performance
	ofFbo fbo;
	fbo.allocate(APP_WIDTH, APP_HEIGHT);
	fbo.begin();
	ofClear(0, 0, 0, 0);
	ofPushStyle();
	ofSetLineWidth(2);
	ofSetColor(255, 255, 0);
	for(unsigned int x = 0; x < APP_WIDTH; x += 50){
		ofDrawLine(x, 0, x, APP_HEIGHT);
	}
	for(unsigned int y = 0; y < APP_HEIGHT; y += 50){
		ofDrawLine(0, y, APP_WIDTH, y);
	}
	ofPopStyle();
	fbo.end();
	_debugGridTexture = fbo.getTexture();
}

void BackgroundSource::update(){
	// Move particles
	for(unsigned int i = 0; i < _particles.size(); ++i){
		_particles[i].update();
	}
}

void BackgroundSource::draw(){
	ofClear(0);

	for(unsigned int i = 0; i < _particles.size(); ++i){
		_particles[i].draw();
	}
	
	if(_settings->debug){
		_debugGridTexture.draw(0, 0);
	}
}

void BackgroundSource::setSettings(shared_ptr<bmbf::nobel::Settings> s){
	_settings = s;
	for(unsigned int i = 0; i < _particles.size(); ++i){
		_particles[i].setSettings(s);
	}
}

} // namespace nobel
} // namespace bmbf
