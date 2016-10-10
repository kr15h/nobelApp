#include "Laureate.h"

namespace bmbf{
namespace nobel{

Laureate::Laureate(
	std::string first,
	std::string last,
	std::string field,
	int year,
	int age){

	_first = first;
	_last = last;
	_field = field;
	_year = year;
	_age = age;
}

std::string Laureate::getFirst(){
	return _first;
}

std::string Laureate::getLast(){
	return _last;
}

std::string Laureate::getField(){
	return _field;
}

int Laureate::getYear(){
	return _year;
}

int Laureate::getAge(){
	return _age;
}

} // namespace nobel
} // namespace bmbf
