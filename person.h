#pragma once

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Person{
	char* _name;
	size_t _age;
public:
	Person(const string&, size_t);
	Person(const Person&);
	~Person();
	string ToString()const;
	void Birthday();
	size_t GetAge()const;
	void SetAge(size_t);
	void Write(ostream&)const;
	void Read(istream&);
};
