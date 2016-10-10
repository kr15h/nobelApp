#include "Letter.h"

namespace bmbf{
namespace nobel{

void Letter::setup(shared_ptr<Fonts> fonts){
	_fonts = fonts;
	
	_testString = "A";
	
	//_stringPaths = _fonts->getBig().getStringAsPoints(_testString);
	//_stringBoundingBox = _fonts->getBig().getStringBoundingBox(_testString, 0, 0);
}

void Letter::update(){
	//
}

void Letter::draw(){
	//_fonts->getBig().drawString("Yes", 20, 20 + _fonts->getBig().getLineHeight());
	
	//for(unsigned int i = 0; i < _stringPaths.size(); ++i){
	//	_stringPaths[i].draw(20, 200);
	//}
}

} // namespace nobel
} // namespace bmbf
