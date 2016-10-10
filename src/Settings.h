#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Constants.h"
#include "Laureate.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

class Settings{
	public:
		vector<Laureate *> & load(string filename, shared_ptr<Fonts> fonts);
	
	private:
		ofxXmlSettings _xml;
		vector <Laureate *> _laureates;
		shared_ptr<Fonts> _fonts;
};

} // namespace nobel
} // namespace bmbf
