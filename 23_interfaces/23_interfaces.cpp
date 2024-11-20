#include <iostream>
#include <vector>
#include "IMove.h"
using namespace std;
int main()
{
	Eagle eagle;
	eagle.fly();
	eagle.move();

	Gull gull;
	gull.fly();

	Car car("bmw");

	cout << "\n================================" << endl;
	vector<IFly*> fl{ &eagle, &gull};
	for (auto& i : fl)
	{
		i->fly();
	}
	cout << "\n================================" << endl;

	vector<IMove*> mov{ &eagle, &gull , &car };

	for (auto& i : mov)
	{
		i->move();
	}
	cout << "\n================================" << endl;
	Owner owner("Misha", &car);
	owner.go();
}