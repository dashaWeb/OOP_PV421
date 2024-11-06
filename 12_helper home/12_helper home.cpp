#include <iostream>
#include "Queue.h"
using namespace std;


int main()
{
	Queue<int> list;
	for (size_t i = 1; i <= 5; i++)
	{
		list.add(Element<int>(rand()%100, rand() % 20));
	}
	list.print();
	list.remove();
	list.print();

	cout << list.peek() << endl;
}
