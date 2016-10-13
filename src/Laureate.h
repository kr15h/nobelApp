#pragma once

#include "Constants.h"
#include "ofMain.h"
#include "Fonts.h"

namespace bmbf{
namespace nobel{

struct LaureateState{
	vector<ofPath> firstPaths;
	vector<ofPath> lastPaths;
	vector<ofPath> fieldAndYearPaths;
	
	vector<ofPolyline> firstPolylines;
};

class Laureate{
	public:
		Laureate(
			string first,
			string last,
			string field,
			string fieldId,
			int year,
			shared_ptr<Fonts> fonts);
	
		void update();
	
		void draw();
		void drawFirst();
		void drawLast();
		void drawFieldAndYear();
	
		void dissolve();
	
		string getFirst();
		string getLast();
		string getField();
		string getFieldId();
	
		int getYear();
	
		ofPath randomizePath(ofPath p, float offsetX, float offsetY);
		ofPath ipolatePath(ofPath from, ofPath to, float m);
	
		ofPoint randomPoint(float offsetX, float offsetY);
	
	private:
		shared_ptr<Fonts> _fonts;

		string _first;
		string _last;
		string _field;
		string _fieldId;
	
		int _year;
	
		ofRectangle _firstBoundingBox;
		ofRectangle _lastBoundingBox;
		ofRectangle _fieldAndYearBoundingBox;
	
		LaureateState _defaultState;
		LaureateState _currentState;
		LaureateState _targetState;
};

} // namespace nobel
} // namespace bmbf
