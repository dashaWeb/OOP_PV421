#include "Animal.h"


size_t Animal::last_id = 0;

void Animal::setAge(const size_t& age)
{
	this->age = age;
}

void Animal::setPlace(const string& place)
{
	if (!place.empty())
		this->place = place;
}

const string& Animal::getPlace() const
{
	return this->place;
}

const size_t& Animal::getAge() const
{
	return this->age;
}

void Animal::print() const
{
	cout << "\t Animal id    ::#" << id << endl;
	cout << "\t Animal age   :: " << age << endl;
	cout << "\t Animal place :: " << place << endl;
}

Animal::Animal(const string& place, const size_t& age)
{
	/*this->place = place;
	this->age = age;*/
	setAge(age);
	setPlace(place);
	id = ++last_id;

	cout << ">>>>>>>>>>> Ctor Animal id #" << id << endl;
}

Animal::~Animal()
{
	cout << ">>>>>>>>>>> Dtor Animal id #" << id << endl;
}
