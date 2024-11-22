//#include <iostream>
//using namespace std;
//
////Exception - помилкова ситуація, яка потребує обробки
//double divi(double a, double b)
//{
//	const int LIMIT = 1'000'000;
//	if (b == 0)
//		throw "Error!!! Division by zero"; // викидаємо виняток типу const char*
//	if (b > LIMIT)
//		throw b; // викидаємо виняток типу double
//	if (b < -LIMIT)
//		throw (int)b; // викидаємо виняток типу int
//
//	return a / b;
//}
//
//// якщо виняток не оброблено, викликається ф-я terminate, яка викликає ф-ю abort()
////void terminate()
////{
////    cout << "Override terminate" << endl;
////    exit(EXIT_FAILURE);
////}
//
//void my_terminate()
//{
//	cout << "my_terminate worked" << endl;
//	exit(EXIT_SUCCESS);
//}
//int main()
//{
//	set_terminate(my_terminate);
//	double a, b;
//	cout << "Enter two number :: \n";
//	while (cin >> a >> b)
//	{
//		try
//		{
//			cout << a << " / " << b << " = " << divi(a, b) << endl;
//
//		}
//		/*catch (const char* ex)
//		{
//			cout << ex << endl;
//		}*/
//		catch (double ex)
//		{
//			cout << "Big number ---> " << ex << endl;
//		}
//		catch (int ex)
//		{
//			cout << "Small number ---> " << ex << endl;
//		}
//		catch (...)
//		{
//			cout << "Default catch" << endl;
//		}
//	}
//}
