#pragma once

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
			int age,
			shared_ptr<Fonts> fonts);
	
		// Draw laureate data
		void draw();
	
		string getFirst();
		string getLast();
		string getField();
	
		int getYear();
		int getAge();
	
	private:
		shared_ptr<Fonts> _fonts;

		string _first;
		string _last;
		string _field;
	
		int _year;
		int _age;
	
		vector<ofPath> _firstPaths;
		vector<ofPath> _yearPaths;
};

} // namespace nobel
} // namespace bmbf
