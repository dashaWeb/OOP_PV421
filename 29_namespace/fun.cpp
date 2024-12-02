#include "fun.h"

double Shapes::areaCircle(double r)
{
    return 3.14 * r * r;
}

double Shapes::Trian::areaTrian(double side, double height)
{
    std::cout << "Test " << value << std::endl;
    return side * height / 2;
}

void Person::print()
{
    std::cout << Person::name << std::endl;
}

void Student::print()
{
    std::cout << Student::name << std::endl;
}
