#pragma once

#include <string>

namespace bmbf{
namespace nobel{

class Laureate{
	public:
		Laureate(
			std::string first,
			std::string last,
			std::string field,
			int year,
			int age);
	
		std::string getFirst();
		std::string getLast();
		std::string getField();
	
		int getYear();
		int getAge();
	
	private:
		std::string _first;
		std::string _last;
		std::string _field;
	
		int _year;
		int _age;
};

} // namespace nobel
} // namespace bmbf
