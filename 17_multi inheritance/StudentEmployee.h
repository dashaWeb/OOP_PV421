#pragma once
#include "Student.h"
#include "Employee.h"
class StudentEmployee
	:public Student, public Employee
{
public:
	StudentEmployee(const string& nameStudent, const string& nameEmployee, const string& specialization, const string& position);
	StudentEmployee(const Student& student, const Employee& empl);
	~StudentEmployee();
	void print() const;
};

