#include "LaureateDisplay.h"

namespace bmbf{
namespace nobel{

LaureateDisplay::LaureateDisplay(Data data, shared_ptr<Fonts> fonts){
	_data = data;
	_fonts = fonts;
	_titlePaths = _fonts->getSmallAsPaths(_data.title);
	_laureateIndex = 1;
}

void LaureateDisplay::update(){
	_data.laureates[_laureateIndex]->update();
}

void LaureateDisplay::draw(){
	_data.laureates[_laureateIndex]->draw();
	
	ofPushMatrix();
	ofTranslate(APP_MARGIN, APP_HEIGHT - APP_MARGIN);
	for(unsigned int i = 0; i < _titlePaths.size(); ++i){
		_titlePaths[i].draw();
	}
	ofPopMatrix();
}

void LaureateDisplay::dissolve(){
	_data.laureates[_laureateIndex]->dissolve();
}

} // namespace nobel
} // namespace bmbf