#include "LaureateDisplay.h"

namespace bmbf{
namespace nobel{

LaureateDisplay::LaureateDisplay(vector<Laureate *> laureates, shared_ptr<Fonts> fonts){
	_laureates = laureates;
	_fonts = fonts;
}

void LaureateDisplay::update(){
	for(unsigned int i = 0; i < _laureates.size(); ++i){
		_laureates[i]->update();
	}
}

void LaureateDisplay::draw(){
	_laureates[1]->draw();
}

} // namespace nobel
} // namespace bmbf