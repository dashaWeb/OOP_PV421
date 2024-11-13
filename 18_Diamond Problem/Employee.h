#pragma once
#include "Person.h"
class Employee
	:virtual public Person
{
public:
	Employee(const string& name = "Noname", const string& position = "NoPosition");
	void print() const;
	~Employee();

protected:
	//string name; успадкування від класу Person
	string position;
};

