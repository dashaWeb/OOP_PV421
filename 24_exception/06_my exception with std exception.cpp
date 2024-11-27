#include <iostream>
using namespace std;

// клас користувацьких винятків



class DivisionByZeroException : public exception
{
	double value = 0;
public:
	DivisionByZeroException(const string& message = "None")
		:exception(message.data()) // c_str
	{}
	double getValue() const
	{
		return value;
	}
};

class TooBigNumberException : public overflow_error
{
	static const int LIMIT_UP = 1'000'000;
	double value = 0;
public:
	TooBigNumberException(const string& message = "None", double value = LIMIT_UP)
		:overflow_error(message), value(value)
	{}
	double getValue() const
	{
		return value;
	}
};

class TooSmallNumberException : public underflow_error
{
	static const int LIMIT_DOWN = -1'000'000;
	double value = 0;
public:
	TooSmallNumberException(const string& message = "None", double value = LIMIT_DOWN)
		:underflow_error(message), value(value)
	{}
	double getValue() const
	{
		return value;
	}
};
double divi(double a, double b)
{
	const int LIMIT = 1'000'000;
	if (b == 0)
		throw DivisionByZeroException("Division by zero"); // викидаємо виняток типу DivisionByZeroException
	if (b > LIMIT)
		throw TooBigNumberException("To big number", b); // викидаємо виняток типу TooBigNumberException
	if (b < -LIMIT)
		throw TooSmallNumberException("Small number", b); // викидаємо виняток типу int

	return a / b;
}
int main()
{
	double a, b;
	cout << "Enter two number :: \n";
	while (cin >> a >> b)
	{
		try
		{
			cout << a << " / " << b << " = " << divi(a, b) << endl;

		}
		/*catch (const DivisionByZeroException& ex)
		{
			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (const TooBigNumberException& ex)
		{
			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (const TooSmallNumberException & ex)
		{
			cout << "Exception : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			cout << "Bad value :: " << ex.getValue() << endl;
		}*/
		catch (const overflow_error& ex)
		{
			cout << "Exception  : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			//cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (const underflow_error& ex)
		{
			cout << "Exception  : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			//cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (const exception& ex)
		{
			cout << "Exception ****** : " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
			//cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (...)
		{
			cout << "Default catch" << endl;
		}
	}
}