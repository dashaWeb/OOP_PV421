#pragma once
#include <iostream>
using namespace std;
class Person
{
	string name;
	size_t counter = 0;

public:
	Person() = default;
	Person(const string& name)
	{
		setName(name);
	}
	void setName(const string& name)
	{
		if (!name.empty())
		{
			this->name = name;
		}
	}
	const size_t& getCounter() const
	{
		return counter;
	}
	string getName() const
	{
		++const_cast<size_t&>(counter);
		return name;
	}
	virtual void print() const
	{
		cout << "Name :: " << name << "\t" << counter << endl;
	}
};

class Student : public Person
{
	string specialization;
public:
	Student() = default;
	Student(const string& name, const string& spec)
		:Person(name),specialization(spec)
	{}
	virtual void print() const override
	{
		cout << ">>>>>>>> " << typeid(*this).name() << " specialization :: " << specialization << endl;
		Person::print();
	}

	void lear()
	{
		cout << ">>>>>>>> " << typeid(*this).name() << " studies :: " << specialization << endl;
	}
};

class Aspirant : public Student
{
	string theme;
public:
	Aspirant() = default;
	Aspirant(const string& name, const string& spec, const string& theme)
		:Student(name,spec), theme(theme)
	{}
	void print() const override
	{
		Student::print();
		cout << "Theme :: " << theme << endl;
	}
	void writeDyplom()
	{
		cout << "Scientic theme :: " << theme << endl;
	}
};
