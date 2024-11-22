//#include <iostream>
//#include <exception>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	//string str = "124514";
//	string str = "2fr124514";
//	try
//	{
//		int value = stoi(str);
//		cout << "Value :: " << value << "\t type(" << typeid(value).name() << ")" << endl;
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Exception :: " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//	}
//
//	vector<int> v{ 1,2,3,4 };
//	try
//	{
//		//cout << "v[5] :: " << v[5] << endl;
//		cout << "v.at(5) :: " << v.at(5) << endl;
//
//	}
//	catch (const std::exception& ex)
//	{
//		cout << "Exception :: " << typeid(ex).name() << "\t Message :: " << ex.what() << endl;
//	}
//
//}