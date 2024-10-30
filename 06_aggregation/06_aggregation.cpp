#include <iostream>
#include "Engine.h"
#include "Car.h"
using namespace std;



int main()
{
    Engine engine("B1",150,2.6);
    engine.print();
    cout << endl;

    Car car;
    car.print();
    cout << endl;

    Car audi{ "Audi",engine,350 };
    audi.print();
    cout << endl;

    Car bmw{ "BMW","HH",180,3.6,200 };
    bmw.print();
    cout << endl;

    Car ford("Ford", "AA", 250, 4.2, 350);
    ford.print();
    cout << endl;
}
