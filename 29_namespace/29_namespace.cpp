#include <iostream>
#include "fun.h"
using namespace std;
//using namespace Shapes;

using Shapes::areaCircle;
//using Shapes::Trian::areaTrian;
using namespace Shapes::Trian;

//void fun()
//{
//    cout << "Test fun " << endl;
//}
//void fun()
//{
//    cout << "Test fun 2" << endl;
//}


//class Shapes
//{
//
//};
//
//class Shapes
//{
//
//};

int main()
{
    //fun();
    //int a = 5;

    //Shapes t;

    ////////////////////
   /* int a = 8;*/
    //cout << "Area Circle" << Shapes::areaCircle(5) << endl;
    cout << "Area Circle" << areaCircle(5) << endl;
    cout << "Area Trian" << areaTrian(4,10) << endl;
    cout << "Value" << value << endl;

    Person::print();
    Student::print();
}

