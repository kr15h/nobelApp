#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(true);
	#ifdef TARGET_RASPBERRY_PI
		ofSetFullscreen(true);
	#endif
	
	// Load fonts for sharing among components
	fonts = make_shared<bmbf::nobel::Fonts>();
	fonts->load(
		string(BOLD_FONT_PATH),
		int(BIG_FONT_SIZE),
		string(REGULAR_FONT_PATH),
		int(SMALL_FONT_SIZE));
	
	// Create shareable settings object and load laureate data
	settings = make_shared<bmbf::nobel::Settings>();
	bmbf::nobel::Data data = settings->load(string(XML_SETTINGS_FILENAME), fonts);
	
	// Create laureate display for displaying laureates one by one
	laureateDisplay = make_shared<bmbf::nobel::LaureateDisplay>(data, fonts);
	
	settings->debug = false;
	debugGridStep = 100;
	
	strobeElements = make_shared<bmbf::nobel::StrobeElements>();
	
	mappingSource.settings = settings;
	mappingSource.fonts = fonts;
	mappingSource.laureateDisplay = laureateDisplay;
	mappingSource.setStrobeElements(strobeElements);
	
	mapper.registerFboSource(mappingSource);
	mapper.setup();
}

void ofApp::update(){
	//laureateDisplay->update();
	
	mapper.update();
}

void ofApp::draw(){
	mapper.draw();

	//laureateDisplay->draw();
	
	if(settings->debug){
		//drawDebugGrid();
		
		stringstream ss;
		ss << "frame rate: "  << ofToString(ofGetFrameRate()) << "\n"
			<< "grid step: " << ofToString(debugGridStep);
		ofDrawBitmapStringHighlight(ss.str(), 10, 20, ofColor(0, 100));
	}
}

void ofApp::keyPressed(int key){
	if(key == ' '){
		settings->debug = !settings->debug;
	}else if(key == '+'){
		debugGridStep += 10;
		if(debugGridStep >= 200){
			debugGridStep = 200;
		}
	}else if(key == '-'){
		debugGridStep -= 10;
		if(debugGridStep <= 10){
			debugGridStep = 10;
		}
	}
}


