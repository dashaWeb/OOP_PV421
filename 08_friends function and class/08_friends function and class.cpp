#include <iostream>
#include "Pupil.h"
using namespace std;


class Point {
	double x, y;

	friend void print(const Point& obj);
	friend void reset(Point& obj);

public:
	Point(const double& x, const double& y)
		:x{ x }, y{ y } {}

};

void print(const Point& obj) {
	cout << obj.x << "," << obj.y << endl;
}

void reset(Point& obj)
{
	obj.x = 0;
	obj.y = 0;
}

int main()
{
	/*Point A(5,10);
	print(A);
	reset(A);
	print(A);*/

	Pupil olia("Olia", 8, 8);
	Pupil oleg("Oleg", 5, 2);
	olia.print();
	oleg.print();
	Teacher teacher;
	cout << endl;
	teacher.setMarkMath(oleg, 10);
	teacher.setMarkEnglish(oleg, 11);
	olia.print();
	oleg.print();
}

