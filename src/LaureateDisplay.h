#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Laureate.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

class LaureateDisplay{
	public:
		LaureateDisplay(Data data, shared_ptr<Fonts> fonts);
	
		void update();
		void draw();
	
		void dissolve();
	
	private:
		Data _data;
		shared_ptr<Fonts> _fonts;
		vector<ofPath> _titlePaths;
		unsigned int _laureateIndex;
};

} // namespace nobel
} // namespace bmbf