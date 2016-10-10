#include "LaureateDisplay.h"

namespace bmbf{
namespace nobel{

LaureateDisplay::LaureateDisplay(Data data, shared_ptr<Fonts> fonts){
	_data = data;
	_fonts = fonts;
	_titlePaths = _fonts->getSmallAsPaths(_data.title);
}

void LaureateDisplay::update(){
	for(unsigned int i = 0; i < _data.laureates.size(); ++i){
		_data.laureates[i]->update();
	}
}

void LaureateDisplay::draw(){
	_data.laureates[1]->draw();
	
	ofPushMatrix();
	ofTranslate(APP_MARGIN, APP_HEIGHT - APP_MARGIN);
	for(unsigned int i = 0; i < _titlePaths.size(); ++i){
		_titlePaths[i].draw();
	}
	ofPopMatrix();
}

} // namespace nobel
} // namespace bmbf