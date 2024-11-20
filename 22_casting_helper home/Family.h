#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Grandpa
{
public:
	Grandpa(const string& name)
		:name(name)
	{}
	virtual void Sleep() const
	{
		cout << typeid(*this).name() << " sleep" << endl;
	}
private:
	string name;
};

class Daddy : public Grandpa
{
public:
	Daddy(const string& name)
		:Grandpa(name)
	{

	}
	virtual void Walk() const
	{
		cout << typeid(*this).name() << " walk" << endl;
	}
	virtual void Sleep() const override
	{
		cout << typeid(*this).name() << " sleep" << endl;
	}
};

class Son : public Daddy
{
public:
	Son(const string& name)
		:Daddy(name)
	{

	}
	virtual void Walk() const override
	{
		cout << typeid(*this).name() << " walk" << endl;
	}
	virtual void Sleep() const override
	{
		cout << typeid(*this).name() << " sleep" << endl;
	}
	virtual void Play() const
	{
		cout << typeid(*this).name() << " play" << endl;
	}
};