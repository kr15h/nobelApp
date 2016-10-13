// We use this for the BackgroundSource

#pragma once

#include "ofMain.h"
#include "Constants.h"
#include "Settings.h"

namespace bmbf{
namespace nobel{

class Particle{
	public:
		Particle();
	
		void setup();
		void update();
		void draw();
	
		void setSettings(shared_ptr<Settings> s);
	
		void setImages(
			shared_ptr<ofImage> chem,
			shared_ptr<ofImage> econ,
			shared_ptr<ofImage> lite,
			shared_ptr<ofImage> medi,
			shared_ptr<ofImage> phys);
	
	private:
		shared_ptr<Settings> _settings;
	
		ofVec2f _position;
		ofVec2f _speed;
		float _size;
	
		shared_ptr<ofImage> _chemistryImage;
		shared_ptr<ofImage> _economicsImage;
		shared_ptr<ofImage> _literatureImage;
		shared_ptr<ofImage> _medicineImage;
		shared_ptr<ofImage> _physicsImage;
};

} // namespace nobel
} // namespace bmbf