#pragma once
#include <iostream>
#include <string>

using std::string;
using std::to_string;
// not overload :: sizeof, typeid, ?, :
class Point {
public:
	void setX(const double& x);
	void setY(const double& y);
	void setName(const string& name);

	const double& getX() const;
	const double& getY() const;
	const string& getName() const;

	string print() const;

	Point() = default;
	explicit Point(const double& x); // explicit - допускається лише явне створення обєкту
	explicit Point(const double& x, const double& y, const string& name = "");

	// binary
	Point operator +(const Point& other) const;// A - this(left) + B - other(right);
	Point operator -(const Point& other) const;// A - this(left) + B - other(right);

	bool operator ==(const Point& other)const;// A - this(left) + B - other(right);
	bool operator !=(const Point& other)const;// A - this(left) + B - other(right);

	Point& operator +=(double number); 

	// ++ unary
	Point& operator++(); // префіксна форма
	Point operator++(int);// постфіксна форма має прийняти фіктивний параметр


	explicit operator double() const; 

private:
	double x = 0, y = 0;
	string name;
};
inline void Point::setX(const double& x)
{
	this->x = x;
}

inline void Point::setY(const double& y)
{
	this->y = y;
}

inline void Point::setName(const string& name)
{
	this->name = name;
}

inline const double& Point::getX() const
{
	return this->x;
}

inline const double& Point::getY() const
{
	return this->y;
}

inline const string& Point::getName() const
{
	return this->name;
}

inline Point::Point(const double& x)
	:Point(x,0) // cascade (delegate) ctor
{
}

inline Point::Point(const double& x, const double& y, const string& name)
	:x(x), y(y), name(name)
{
}
