#pragma once

#include "Constants.h"
#include "ofMain.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

class Laureate{
	public:
		Laureate(
			string first,
			string last,
			string field,
			int year,
			shared_ptr<Fonts> fonts);
	
		void update();
	
		void draw();
		void drawFirst();
		void drawLast();
		void drawFieldAndYear();
	
		string getFirst();
		string getLast();
		string getField();
	
		int getYear();
	
	private:
		shared_ptr<Fonts> _fonts;

		string _first;
		string _last;
		string _field;
	
		int _year;
	
		vector<ofPath> _firstPaths;
		vector<ofPath> _lastPaths;
		vector<ofPath> _fieldAndYearPaths;
	
		ofRectangle _firstBoundingBox;
		ofRectangle _lastBoundingBox;
		ofRectangle _fieldAndYearBoundingBox;
};

} // namespace nobel
} // namespace bmbf
