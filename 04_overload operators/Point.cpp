#include "Point.h"

string Point::print() const
{
	return name + "(" + to_string(x) + "," + to_string(y) + ")";
}

Point Point::operator+(const Point& other)const
{
	//Point result; // x = 0; y = 0
	//result.x = this->x + other.x;
	//result.y = this->y + other.y;
	//return result;
	return Point(this->x + other.x, this->y + other.y);

}

Point Point::operator-(const Point& other)const
{
	return Point(this->x - other.x, this->y - other.y);
}

bool Point::operator==(const Point& other)const
{
	return (this->x == other.x and this->y == other.x);
}

bool Point::operator!=(const Point& other)const
{
	//return !(this->x == other.x and this->y == other.x);
	return !(*this == other);
}

Point& Point::operator+=(double number)
{
	this->x += number;
	this->y += number;
	return *this;
}

Point& Point::operator++()
{
	++this->x;
	++this->y;
	return *this;
}

Point Point::operator++(int)
{
	Point tmp(*this); // copy ctor
	++* this;
	return tmp;
}

Point::operator double() const
{
	return (x + y) / 3;
}
