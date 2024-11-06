#include <iostream>
#include "FwdList.h"
using namespace std;


int main()
{
	FwdList<int> list;
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
}
