#pragma once

#include "ofMain.h"
#include "FboSource.h"

#include "Constants.h"
#include "Settings.h"
#include "Fonts.h"
#include "Laureate.h"
#include "LaureateDisplay.h"

class MappingSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
	
		void drawDebugGrid();
	
		shared_ptr<bmbf::nobel::Settings> settings;
		shared_ptr<bmbf::nobel::Fonts> fonts;
		shared_ptr<bmbf::nobel::LaureateDisplay> laureateDisplay;
	
		int debugGridStep;
};