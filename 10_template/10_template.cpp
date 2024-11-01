#include <iostream>
#include "Matrix.h"
using namespace std;


//int sum(int a, int b)
//{
//    return a + b;
//}
//
//double sum(double a, double b)
//{
//    return a + b;
//}
template <typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	/*cout << sum(1, 2) << endl;
	cout << sum(1.2, 2.5) << endl;
	cout << sum('A', ' ') << endl;
	string line1 = "Test";
	string line2 = "Test2";
	cout << sum(line1,line2) << endl;*/
	// T = int, row = 2, col = 3
	Matrix<int, 4, 4> m(8);
	m.print();
	m(2, 2) = 77;
	cout << m + 2<< endl;

	Matrix<double, 3, 3> d(3.3);
	cout << d << endl;
	d = d + 3.0;
	cout << d << endl;

	Matrix<> mm(11);
	cout << mm << endl;
	
	Matrix<string, 5, 5> s("test");
	cout << s << endl;
	s(3, 3) = "ok";
	cout << s << endl;

}
