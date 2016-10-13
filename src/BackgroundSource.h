#pragma once

#include "ofMain.h"
#include "FboSource.h"

#include "Constants.h"
#include "Settings.h"

namespace bmbf{
namespace nobel{

class BackgroundSource : public ofx::piMapper::FboSource {
	public:
		BackgroundSource();
	
        void setup();
		void update();
		void draw();
	
		void setSettings(shared_ptr<Settings> s);
	
	private:
		shared_ptr<Settings> _settings;
	
};

} // namespace nobel
} // namespace bmbf
