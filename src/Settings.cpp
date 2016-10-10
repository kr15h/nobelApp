#include "Settings.h"

namespace bmbf{
namespace nobel{

void Settings::load(){
	bool loaded = _xml.load("laureates.xml");
	
	if(!loaded){
		cout << "Could not load laureates.xml" << endl;
		ofExit();
	}
	
	// Parse
	if(_xml.tagExists("laureates")){
		_xml.pushTag("laureates");
		
		unsigned int numLaureates = _xml.getNumTags("laureate");
		for(unsigned int i = 0; i < numLaureates; ++i){
			_xml.pushTag("laureate", i);
			
			string first = _xml.getValue("first", "Johny");
			string last = _xml.getValue("last", "Mason");
			string field = _xml.getValue("field", "Cooking");
			int year = _xml.getValue("year", 1956);
			int age = _xml.getValue("age", 18);
			
			Laureate * l = new Laureate(first, last, field, year, age);
			_laureates.push_back(l);
			
			_xml.popTag(); // laureate
		}
		
		_xml.popTag(); // laureates
	}else{
		cout << "Wrong XML or it is empty" << endl;
		ofExit();
	}
	
	// Test print
	for(unsigned int i = 0; i < _laureates.size(); ++i){
		cout << _laureates[i]->getFirst() << ", "
			<< _laureates[i]->getLast() << ", "
			<< _laureates[i]->getField() << ", "
			<< _laureates[i]->getYear() << ", "
			<< _laureates[i]->getAge()
			<< endl;
	}
}

} // nobel
} // bmbf