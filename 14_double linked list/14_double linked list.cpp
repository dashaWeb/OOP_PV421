#include <iostream>
#include "List.h"
using namespace std;



int main()
{
	List<int> list;
	for (size_t i = 0; i < 5; i++)
	{
		list.addHead(rand() % 50);
	}
	list.print();
	cout << "\n\n";
	list.printR();
	cout << "\n\n Remove :: \n";
	list.removeHead();
	list.print();
	list.printR();


	cout << "\n\n Remove Data:: \n";
	list.removeByData(34);
	list.print();
	list.printR();

}

