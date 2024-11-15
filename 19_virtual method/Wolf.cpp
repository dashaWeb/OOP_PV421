#include "Wolf.h"

Wolf::Wolf(const string& place, const size_t& age, const size_t& weight)
	:Animal(place, age), weight(weight)
{
	cout << "\t >>>>>>>>>>> Ctor Wolf #" << id << endl;
}

Wolf::~Wolf()
{
	cout << "\t >>>>>>>>>>> Dtor Wolf #" << id << endl;
}

void Wolf::print() const
{
	//Animal::print();

	cout << "\t ================ Wolf #" << id << endl;
	cout << "\t\t Age    :: " << getAge() << endl;
	cout << "\t\t Place  :: " << place << endl;
	cout << "\t\t Weigth :: " << weight << endl;
}

void Wolf::eat() const
{
	cout << "Lion id " << id << " likes to eat hares" << endl;
}

Dog::Dog(const string& place, const size_t& age, const size_t& weight, const string& master)
	:master(master)
{
	cout << "\t >>>>>>>>>>> Ctor Dog #" << id << endl;
}

Dog::~Dog()
{
	cout << "\t >>>>>>>>>>> Dtor Dog #" << id << endl;
}

//void Dog::print() const
//{
//	cout << "\t ================ Dog #" << id << endl;
//	cout << "\t\t Age    :: " << getAge() << endl;
//	cout << "\t\t Place  :: " << place << endl;
//	cout << "\t\t Master :: " << master << endl;
//}

void Dog::eat() const
{
	cout << "Lion id " << id << " likes to eat sausage" << endl;
}
