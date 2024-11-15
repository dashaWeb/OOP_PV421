#pragma once
#include "Human.h"
class Employee
	: public Human
{
public:
	Employee(const string& name, const size_t& age)
		:Human(name, age)
	{
		cout << "Employee ctor " << name << endl;
	}
	void eat() const override
	{
		cout << "Employee   " << name << " likes to eat sandwich" << endl;
	}
	void print() const override
	{
		cout << "\t Employee     " << name << endl;
		cout << "\t Employee age " << age << endl;
	}
};
