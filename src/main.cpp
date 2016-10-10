#include "ofMain.h"
#include "ofApp.h"
#include "Constants.h"

int main(){
	ofSetupOpenGL(APP_WIDTH, APP_HEIGHT, OF_WINDOW);
	ofRunApp(new ofApp());
}
