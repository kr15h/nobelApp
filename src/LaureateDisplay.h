#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Laureate.h"
#include "Fonts.h"
#include "StrobeElements.h"

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
		void setLaureateField();
	
		void setStrobeElements(shared_ptr<bmbf::nobel::StrobeElements> sr);
		void setSettings(shared_ptr<bmbf::nobel::Settings> s);
	
	private:
		Data _data;
	
		shared_ptr<Fonts> _fonts;
	
		vector<ofPath> _titlePaths;
	
		unsigned int _laureateIndex;
	
		float _lastTriggerTime;
		float _strobeTime;
	
		DisplayState _state;
	
		shared_ptr<bmbf::nobel::StrobeElements> _strobeElements;
		shared_ptr<bmbf::nobel::Settings> _settings;
};

} // namespace nobel
} // namespace bmbf