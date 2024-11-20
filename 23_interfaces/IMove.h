#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
// interface - пропонує абстрактну поведінку (може містити чисті віртуальні функції)

struct IMove
{
	virtual void move() const = 0;
	virtual size_t getSpeed() const = 0;
};

struct IFly : public IMove
{
	virtual void fly() const = 0;
	virtual size_t getHeight() const = 0;
};


class Bird : public IFly
{
public:
	Bird(const size_t & height, const size_t& speed)
		:height(height), speed(speed)
	{

	}
	virtual void fly() const
	{
		cout << "Bird " << typeid(*this).name() << " can fly on height " << getHeight() << endl;
	}
	virtual size_t getHeight() const
	{
		return height;
	}
	virtual void move() const
	{
		cout << "Bird " << typeid(*this).name() << " can walk and fly "  << endl;
	}
	virtual size_t getSpeed() const
	{
		return speed;
	}
private:
	size_t height;
	size_t speed;
};


class Eagle : public Bird
{
public:
	Eagle()
		:Bird(2000, 30)
	{}
};

class Gull : public Bird
{
public:
	Gull()
		:Bird(500, 5)
	{}
};
class Car : public IMove // клас реалізує інтерфейс IMove = реалізує кожен абстрактний метод
{
public:
	Car(const string& brand, const size_t& speed = 200)
		:brand(brand), speed(speed)
	{
	}
	virtual void move() const
	{
		cout << "Car " << brand << " can move with speed " << getSpeed() << endl;
	}
	virtual size_t getSpeed() const
	{
		return speed;
	}
private:
	string brand;
	size_t speed;
};


class Owner
{
public:
	Owner(const string& name, IMove* moveable)
		:name(name),moveable(moveable)
	{
	}
	void go() const
	{
		moveable->move();
	}
private:
	string name;
	IMove* moveable;
};