#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Laureate.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

enum DisplayState{
	SHOWING,
	STROBING
};

class LaureateDisplay{
	public:
		LaureateDisplay(Data data, shared_ptr<Fonts> fonts);
	
		void update();
		void draw();
	
		void dissolve();
		void nextLaureate();
	
	private:
		Data _data;
	
		shared_ptr<Fonts> _fonts;
	
		vector<ofPath> _titlePaths;
	
		unsigned int _laureateIndex;
	
		float _lastTriggerTime;
		float _strobeTime;
	
		DisplayState _state;
};

} // namespace nobel
} // namespace bmbf