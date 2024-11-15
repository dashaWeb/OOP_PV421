#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Human abstract
{
public:
	Human(const string& name, const size_t& age)
		:name(name),age(age)
	{
		cout << "Human ctor " << name << endl;
	}
	virtual void print() const;
	virtual void eat() const = 0;
protected:
	string name;
	size_t age;
};

inline void Human::print() const
{
	cout << "Human name :: " << name << endl;
	cout << "Human age  :: " << age << endl;
}