#include <iostream>
#include "Food.h"
using namespace std;

// MyClass.h --> struct(class), definition (prototype method) + realization inline
// MyClass.cpp -->realization of notinline
// main.cpp --> program



int main()
{
    cout << Food::MAX_WEIGHT << endl;
    cout << Food::getCounter() << endl;

    Food food;
    cout << Food::getCounter() << endl;
    food.setName("Borshch");
    food.setKkal(200);
    food.setWeight(250);
    food.print();

    Food olivie("Salad 'Olivie'", 330, 200);
    cout << Food::getCounter() << endl;
    olivie.print();

    //Food clone = food; // ctor cope (compile create copy ctor = shallow copy);
    //Food clone(food); // ctor cope (compile create copy ctor = shallow copy);
    Food clone{food}; // ctor cope (compile create copy ctor = shallow copy);

    cout << "Clone   :: ";
    clone.print();
    cout << "Origine :: ";
    food.print();

    clone.setName("Milk");

    cout << "Clone   :: ";
    clone.print();
    cout << "Origine :: ";
    food.print();

    clone = olivie;
    cout << "\n\n";
    cout << "Clone   :: ";
    clone.print();
    cout << "Origine :: ";
    olivie.print();

    clone.setName("Milk");

    cout << "Clone   :: ";
    clone.print();
    cout << "Origine :: ";
    olivie.print();
    system("pause");
    cout << Food::getCounter() << endl;
}
