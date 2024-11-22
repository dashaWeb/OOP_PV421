//#include <iostream>
//using namespace std;
//
//void fnT(int& value)
//{
//	try
//	{
//		if (value < 0)
//		{
//			throw exception("Error!!! value < 0");
//		}
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Inner catch" << endl;
//		throw;
//	}
//	value *= 2;
//}
//
//int main()
//{
//	int number = -10;
//	try
//	{
//		fnT(number);
//		cout << "Number :: " << number << endl;
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Outer catch" << endl;
//		cout << "Message :: " << ex.what() << endl;
//	}
//}