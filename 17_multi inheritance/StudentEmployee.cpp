#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& nameStudent, const string& nameEmployee, const string& specialization, const string& position)
	:Student(nameStudent, specialization), Employee(nameEmployee,position)
{
	/*this->specialization = specialization;
	this->position = position;
	Student::name = nameStudent;
	Employee::name = nameEmployee;*/
	cout << "\t\t >>>>>>>>>>>>> Ctor STUDENT_Employee :: " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& empl)
:Student(student), Employee(empl) // copy ctor
{
	cout << "\t\t >>>>>>>>>>>>> Ctor STUDENT_Employee :: " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::~StudentEmployee()
{
	cout << "\t\t >>>>>>>>>>>>> Dtor STUDENT_Employee :: " << Student::name << " - " << Employee::name << endl;

}

void StudentEmployee::print() const
{
	Student::print();
	Employee::print();
}
