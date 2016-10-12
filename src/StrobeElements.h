#pragma once

#include "ofMain.h"
#include "Constants.h"
#include "Settings.h"

namespace bmbf{
namespace nobel{

struct StrobeRect{
	ofRectangle rect;
	ofColor color;
	float alpha;
};

class StrobeElements{
	public:
		StrobeElements();
	
		void setup();
		void update();
		void draw();
	
		void triggerRandomStrobe();
		void setSettings(shared_ptr<bmbf::nobel::Settings> s);
	
		float x;
		float y;
	
	private:
		vector<StrobeRect> _strobeRects;
		shared_ptr<bmbf::nobel::Settings> _settings;
	
};

} // namespace nobel
} // namespace bmbf
