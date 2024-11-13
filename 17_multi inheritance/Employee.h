#pragma once
#include "lib.h"
class Employee
{
public:
	Employee(const string& name = "Noname", const string& position = "NoPosition");
	void print() const;
	~Employee();

protected:
	string name;
	string position;
};

