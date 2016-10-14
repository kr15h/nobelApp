#pragma once

#include "ofMain.h"
#include "FboSource.h"

#include "Constants.h"
#include "Settings.h"
#include "Particle.h"

namespace bmbf{
namespace nobel{

class BackgroundSource : public ofx::piMapper::FboSource {
	public:
		BackgroundSource();
	
        void setup();
		void update();
		void draw();
	
		void loadImages();
	
		void setSettings(shared_ptr<Settings> s);
	
	private:
		shared_ptr<Settings> _settings;
	
		vector<Particle> _particles;
	
		shared_ptr<ofImage> _chemistryImage;
		shared_ptr<ofImage> _economicsImage;
		shared_ptr<ofImage> _literatureImage;
		shared_ptr<ofImage> _medicineImage;
		shared_ptr<ofImage> _physicsImage;
	
		ofTexture _debugGridTexture;
};

} // namespace nobel
} // namespace bmbf
