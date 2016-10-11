#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Constants.h"
#include "Laureate.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

struct Data{
	string title;
	vector<Laureate *> laureates;
};

class Settings{
	public:
		Settings();
	
		Data & load(string filename, shared_ptr<Fonts> fonts);
	
		bool debug;
	private:
		ofxXmlSettings _xml;
		Data _data;
		shared_ptr<Fonts> _fonts;
};

} // namespace nobel
} // namespace bmbf
