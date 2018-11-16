#include "person.h"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::stringstream;

using std::cout;
using std::endl;

void DebugLine(const char* message){
	cout << "- - - - - - - - - - " << message << endl;
}

Person::Person(const string& name, size_t age): _age(age){
	DebugLine("Person::Person(const string& name, size_t age)");
	_name = new char[name.length() + 1];
	strcpy(_name, name.c_str());
}
Person::Person(const Person& other): _age(other._age){
	DebugLine("Person::Person(const Person& other)");
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);
}
Person::~Person(){
	DebugLine("Person::~Person()");
	if (_name)
		delete[] _name;
}
string Person::ToString()const{
	stringstream ss;
	ss << "{_name: " << _name << ", _age: " << _age << "}";
	return ss.str();
}
void Person::Birthday(){
	_age++;
}
size_t Person::GetAge()const{
	return _age;
}
void Person::SetAge(size_t age){
	_age = age;
}
void Person::Write(ostream& out)const{
	out << _name << " " << _age;
}
void Person::Read(istream& in){
	in >> _name >> _age;
}
