#pragma once
#include <iostream>
namespace Shapes
{
	double areaCircle(double r);
}

namespace Shapes
{
	namespace Trian
	{
		double areaTrian(double side, double height);
		static int value = 100;
	}
}

namespace Person
{
	static std::string name = "Taras";
	void print();
}
namespace Student
{
	static std::string name = "Matviy";
	void print();
}