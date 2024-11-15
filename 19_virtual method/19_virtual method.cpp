#include <iostream>
#include <vector>
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
    Dog dog("Ukraine", 10, 15, "Oleg");
    dog.print();
    cout << "\n\n";
    cout << "\n\n";

    // неявне перетворення похідного типу до базового (тип наслідування public)
    Animal test = lion; // ctor
    test.print();

    cout << "\n\n";
    test = (Animal&)wolf; // якщо тип наслідування protected, використовувати явне перетворення типів
    test.print();
    Animal* test2 = &lion; 
    test2->print();
    cout << "\n\n";
    cout << "===========================================" << endl;
    vector<Animal*> zoo{&lion, &animal, (Animal*)&wolf, (Animal*)&dog};


  
    for (auto& i : zoo)
    {
        cout << "\n==============================\n";
        i->print();
        i->eat();
        cout << endl;
    }
    cout << "\n\n";
}
