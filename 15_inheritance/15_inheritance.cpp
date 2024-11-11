#include <iostream>
#include "Lion.h"
#include "Wolf.h"
using namespace std;
int main()
{
    
    Animal animal("South Africa", 3);
    animal.print();

    cout << "\n\n";
    Lion lion("North Africa", 4, false);
    lion.print();
    cout << "\n\n";
   /* lion.Animal::print();*/
    Wolf wolf("Africa", 5, 30);
    wolf.print();


    cout << "\n\n";
    Dog dog("Ukraine",10,15,"Oleg");
    dog.print();
    cout << "\n\n";
    cout << "\n\n";


    Animal arr[4]{animal,lion,wolf,dog};
    for (auto& i : arr)
    {
        i.print();
        cout << endl;
    }
    cout << "\n\n";
}
