#include "person.h"
#include <iostream>
#include <sstream>


using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

void TryCopyConstructor(Person);

int main(int argc, char* argv[]){
	stringstream inputBuffer;
	inputBuffer.str(
			"John 15\n"
			"Ann 19\n"
			"Mary 21\n"
			"Elizabeth 25\n"
			"Peter 41"
	);
	int numberOfPeople;
	cout << "How many people: ";
	cin >> numberOfPeople;
	// Create an array of Persons of size numberOfPeople
	Person** people = new Person*[numberOfPeople];

	// Use inputBuffer to fill the array of Persons
	string name;
	int age, n = 0;
	while (inputBuffer >> name >> age){
		people[n] = new Person(name, age);
		n++;
	}

	// Output to screen the array of person
	// first output using ToString
	for (size_t i = 0; i < n; i++) {
		cout << people[i]->ToString() << endl;
	}

	// second output using Write
	for (size_t i = 0; i < n; i++) {
		people[i]->Write(cout);
		cout << endl;
	}

	cout << " --------------------------- T E S T " << endl;
	cout << people[0]->ToString() << endl;
	cout << " ------- Before Function" << endl;
	TryCopyConstructor(*people[0]);
	cout << " ------- After Function" << endl;
	cout << people[0]->ToString() << endl;
	cout << " D O N E ------------------- T E S T " << endl;


	// Do you need to do something else before finishing?
	for (size_t i = 0; i < n; i++) {
		delete people[i];
	}
	delete[] people;



	return 0;
}
void TryCopyConstructor(Person p){
	p.Birthday();
	cout << p.ToString();
}
