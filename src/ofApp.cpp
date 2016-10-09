#include "ofApp.h"

void ofApp::setup(){
	
	// Load Nobel Price laureates here
	bool loaded = xmlSettings.load("laureates.xml");
	
	if(!loaded){
		cout << "Could not load laureates.xml" << endl;
		ofExit();
	}
	
	// Parse
	if(xmlSettings.tagExists("laureates")){
		xmlSettings.pushTag("laureates");
		
		unsigned int numLaureates = xmlSettings.getNumTags("laureate");
		for(unsigned int i = 0; i < numLaureates; ++i){
			xmlSettings.pushTag("laureate", i);
			
			Laureate * l = new Laureate();
			l->first = xmlSettings.getValue("first", "Johny");
			l->last = xmlSettings.getValue("last", "Mason");
			l->field = xmlSettings.getValue("field", "Cooking");
			l->year = xmlSettings.getValue("year", 1956);
			laureates.push_back(l);
			
			xmlSettings.popTag(); // laureate
		}
		
		xmlSettings.popTag(); // laureates
	}else{
		cout << "Wrong XML or it is empty" << endl;
		ofExit();
	}
	
	// Test print
	for(unsigned int i = 0; i < laureates.size(); ++i){
		cout << laureates[i]->first << ", "
			<< laureates[i]->last << ", "
			<< laureates[i]->field << ", "
			<< laureates[i]->year
			<< endl;
	}
}

void ofApp::update(){

}

void ofApp::draw(){

}