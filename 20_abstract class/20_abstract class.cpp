#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Employee.h"
int main()
{
    
    // Human test;
    Student denis("Denis",22);
    denis.print();
    
    Employee taras("Taras", 18);
    taras.print();

    std::vector<Human*> peoples{ &denis, &taras, new Student("Olia",25), new Employee("Pasha",34) };

    for (auto& i : peoples)
    {
        i->print();
        i->eat();
        std::cout << "\n\n";
    }
}

