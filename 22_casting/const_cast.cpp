//#include <iostream>
//using namespace std;
//
//void funInt(const int& value)
//{
//	//++value;
//	++const_cast<int&>(value);
//	int& ref = const_cast<int&>(value);
//	ref++;
//}
//
//void funString(const string& value)
//{
//	//++value[0];
//	++const_cast<string&>(value)[0];
//	string& ref = const_cast<string&>(value);
//	ref += "!!!!";
//}
//
//class Person
//{
//public:
//	Person(const string& name = "Noname", const size_t& age = 0)
//		:name{ name }, age{age}
//	{}
//	const string& getName() const
//	{
//		//this->name[0] = '0';
//		if (islower(name[0]))
//		{
//			string& refName = const_cast<string&>(name);
//			refName[0] = toupper(refName[0]);
//		}
//		return name;
//	}
//	const size_t& getAge() const
//	{
//		Person* changeThis = const_cast<Person*>(this);
//		changeThis->age++;
//		changeThis->name += "*";
//		return age;
//	}
//private:
//	string name;
//	size_t age;
//};
//
//int main()
//{
//	int number = 1000;
//	cout << "Number :: " << number << endl;
//	funInt(number);
//	cout << "Number :: " << number << endl;
//
//	string line = "CONST CAST";
//	cout << line << endl;
//	funString(line);
//	cout << line << endl;
//
//	Person people("dmytro", 22);
//	cout << "Name :: " << people.getName() << endl;
//	cout << "Age  :: " << people.getAge() << endl;
//	cout << "Age  :: " << people.getAge() << endl;
//	cout << "Name :: " << people.getName() << endl;
//}