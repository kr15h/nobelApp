#pragma once

#include "ofMain.h"

#include "ofxXmlSettings.h"

#include "Constants.h"
#include "Laureate.h"

namespace bmbf{
namespace nobel{

class Settings{
	public:
		void load();
	
	private:
		ofxXmlSettings _xml;
		vector <Laureate *> _laureates;
};

} // namespace nobel
} // namespace bmbf
