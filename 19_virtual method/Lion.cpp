#include "Lion.h"

Lion::Lion(const string& place, const size_t& age, bool isAlone)
	:Animal(place, age), isAlone(isAlone)
{
	//this->age = age; // compile error, поле private
	/*setAge(age);
	setPlace(place);*/
	cout << "\t >>>>>>>>>>> Ctor Lion #" << id << endl;
}

void Lion::print() const
{
	cout << "\t ================ Lion #" << id << endl;
	cout << "\t\t Age   :: " << getAge() << endl;
	cout << "\t\t Place :: " << place << endl;
	cout << "\t\t Alone :: " << boolalpha << isAlone << endl;

}

void Lion::eat() const
{
	cout << "Lion id " << id << " likes to eat meat" << endl;
}

Lion::~Lion()
{
	cout << "\t >>>>>>>>>>> Dtor Lion #" << id << endl;
}
