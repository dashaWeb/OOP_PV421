//#include <iostream>
//using namespace std;
//
//// клас користувацьких винятків
//
//class MyException // базовий клас для помилок (по задачі ділення)
//{
//	string message;
//	double value;
//public:
//	MyException(const string& message = "None", double value = 0)
//		:message(message), value(value)
//	{
//	}
//	const string& what() const
//	{
//		return message;
//	}
//	const double& getValue() const
//	{
//		return value;
//	}
//
//};
//
//class DivisionByZeroException : public MyException
//{
//public:
//	DivisionByZeroException(const string& message = "None")
//		:MyException(message)
//	{}
//};
//
//class TooBigNumberException : public MyException
//{
//	static const int LIMIT_UP = 1'000'000;
//public:
//	TooBigNumberException(const string& message = "None", double value = LIMIT_UP)
//		:MyException(message, value)
//	{}
//};
//
//class TooSmallNumberException : public MyException
//{
//	static const int LIMIT_DOWN = -1'000'000;
//public:
//	TooSmallNumberException(const string& message = "None", double value = LIMIT_DOWN)
//		:MyException(message, value)
//	{}
//};
//double divi(double a, double b)
//{
//	const int LIMIT = 1'000'000;
//	if (b == 0)
//		throw DivisionByZeroException("Division by zero"); // викидаємо виняток типу DivisionByZeroException
//	if (b > LIMIT)
//		throw TooBigNumberException("To big number", b); // викидаємо виняток типу TooBigNumberException
//	if (b < -LIMIT)
//		throw TooSmallNumberException("Small number", b); // викидаємо виняток типу int
//
//	return a / b;
//}
//int main()
//{
//	double a, b;
//	cout << "Enter two number :: \n";
//	while (cin >> a >> b)
//	{
//		try
//		{
//			cout << a << " / " << b << " = " << divi(a, b) << endl;
//
//		}
//		catch (const DivisionByZeroException& ex)
//		{
//			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//			cout << "Bad value :: " << ex.getValue() << endl;
//		}
//		catch (const TooBigNumberException& ex)
//		{
//			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//			cout << "Bad value :: " << ex.getValue() << endl;
//		}
//		catch (const TooSmallNumberException & ex)
//		{
//			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//			cout << "Bad value :: " << ex.getValue() << endl;
//		}
//		catch (const MyException& ex)
//		{
//			cout << "Exception ****** : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//			cout << "Bad value :: " << ex.getValue() << endl;
//		}
//		catch (...)
//		{
//			cout << "Default catch" << endl;
//		}
//	}
//}