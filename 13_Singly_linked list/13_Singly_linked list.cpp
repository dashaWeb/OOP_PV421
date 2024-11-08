#include <iostream>
#include "FwdList.h"
using namespace std;


int main()
{
	FwdList<int> list, list_2;
	for (size_t i = 0; i < 5; i++)
	{
		list.addHead(rand() % 50); 
		list.print();
	}

	cout << "Remove head" << endl;
	while (!list.empty()) {
		list.removeHead();
		list.print();
	}
	for (size_t i = 0; i < 5; i++)
	{
		list.addTail(rand() % 10);
		list_2.addTail(rand() % 10);
		//list.print();
	}
	cout << "\n\n =====================================\n";
	cout << "List 1 :: \n";
	list.print();
	cout << "List 2 :: \n";
	list_2.print();

	auto result = list * list_2;
	cout << "List result :: \n";
	result.print();

}
// clear() - видаляти всі вузли;
// деструктор
// addTail(const T& data); -- додати в кінець списку

// *** removeTail() - видалення останнього вузла 