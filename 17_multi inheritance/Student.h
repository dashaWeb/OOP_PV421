#pragma once
#include "lib.h"
class Student
{
public:
	Student(const string& name = "Noname", const string& specialization = "Nospec");
	void print() const;
	~Student();
protected:
	string name;
	string specialization;
};

