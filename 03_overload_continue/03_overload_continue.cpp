#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector a(10, 3);
	a.print();
	/*a[0] = 2;*/

	a[0] = 10;
	a.print();
	for (size_t i = 0; i < a.getSize(); i++)
	{
		a[i] = (i + 1) * 10;
	}
	a.print();
	cout << a[222] << endl;

	Vector b = a(2, 4);
	b.print();
	b.pushBack(33);
	b.print();
	b.pushBack(43);
	b.print();
	b.pushBack(53);
	b.print();
	b.pushBack(63);
	b.print();
}

// Task
/* До класу Vector додати наступний функціонал.
* arr    ==> 2 8 5 1 10 5 9 9 3 5
* splice ==> 5 1 10 22 33 44
1. Використовуючи механізм перевантаження оператора +, обєднати два вектора (arr + splice) ==> new vector(2 8 5 1 10 5 9 9 3 5 5 1 10 22 33 44 )
 Vector operator + (const Vector& other) const;
2. Використовуючи механізм перевантаження оператора -, знайти унікальні елементи arr які не належать splice (arr - splice) ==> new vector(2 8 9 9 3)
Vector operator - (const Vector& other) const;
3. Використовуючи механізм перевантаження оператора *, результат новий вектор у якого кожне значення збільшили в n - разів
Vector operator * (const size_t& n) const;
4. Перетворення до int повертає суму елементів масиву
explicit operator int() const;
5. Перетворення до char* повертає значення елементів массива у вигляді рядка
explicit operator char*() const;
methods
6. void pushBack(const int& value); ==> додати в кінець
7. void pushFront(const int& value); ==> додати на початок
8. void insert(const int& value, const size_t& index); ==> додати за вказаною позицією
9. void popBack(); ==> видалити в кінці
10. void popFront(); ==> видалити на початку
11. void remove(const size_t& index); ==> видалити за вказаною позицією
12. int find(const int& value); -1 - якщо немає, повертаємо індекс першого входження елемента
*/