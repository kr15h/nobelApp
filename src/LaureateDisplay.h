#pragma once

#include "ofMain.h"
#include "Laureate.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

class LaureateDisplay{
	public:
		LaureateDisplay(vector<Laureate *> laureates, shared_ptr<Fonts> fonts);
	
		void update();
		void draw();
	
	private:
		vector<Laureate *> _laureates;
		shared_ptr<Fonts> _fonts;
};

} // namespace nobel
} // namespace bmbf