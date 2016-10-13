#include "Settings.h"

namespace bmbf{
namespace nobel{

Settings::Settings(){
	debug = false;
	currentField = Field::PHYSICS;
	backgroundAlpha = 255;
}

Data & Settings::load(string filename, shared_ptr<Fonts> fonts){
	_fonts = fonts;
	
	bool loaded = _xml.load(filename);
	if(!loaded){
		cout << "Could not load " << filename << endl;
		ofExit();
	}
	
	if(_xml.tagExists("settings")){
		_xml.pushTag("settings");
		_data.title = _xml.getValue("title", "Nobel Laureates");
		
			if(_xml.tagExists("background")){
				_xml.pushTag("background");
				backgroundAlpha = _xml.getValue("alpha", 255);
				_xml.popTag();
			}
		_xml.popTag();
	}else{
		_data.title = "Nobel Laureates";
	}
	
	if(_xml.tagExists("laureates")){
		_xml.pushTag("laureates");
		
		unsigned int numLaureates = _xml.getNumTags("laureate");
		for(unsigned int i = 0; i < numLaureates; ++i){
			_xml.pushTag("laureate", i);
			
			string first = _xml.getValue("first", "Johny");
			string last = _xml.getValue("last", "Mason");
			string field = _xml.getValue("field", "Cooking");
			string fieldId = _xml.getAttribute("field", "id", "Pets");
			int year = _xml.getValue("year", 1956);
			
			Laureate * l = new Laureate(first, last, field, fieldId, year, fonts);
			_data.laureates.push_back(l);
			
			_xml.popTag(); // laureate
		}
		
		_xml.popTag(); // laureates
	}else{
		cout << "Wrong XML or it is empty" << endl;
		ofExit();
	}
	
	// Test print
	for(unsigned int i = 0; i < _data.laureates.size(); ++i){
		cout << _data.laureates[i]->getFirst() << ", "
			<< _data.laureates[i]->getLast() << ", "
			<< _data.laureates[i]->getField() << ", "
			<< _data.laureates[i]->getYear()
			<< endl;
	}
	
	return _data;
}

} // nobel
} // bmbf