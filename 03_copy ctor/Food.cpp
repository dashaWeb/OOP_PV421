#include "Food.h"
#include <iostream>
using std::cout;
using std::endl;
Food::Food(const char* name, const size_t& kkal, const size_t& weight)
{
	setName(name);
	setKkal(kkal);
	setWeight(weight);
}
Food::~Food()
{
	if (name != nullptr)
	{
		cout << "\n \t\t Dtor for " << name << " done " << endl;
		delete[] name;
		name = nullptr;
	}
}
Food::Food(const Food& other)
{
	//this->name = other.name; // *ptr1 = *ptr2 -- bad!!!
	setName(other.name);
	this->kkal = other.kkal;
	this->weight = other.weight;
}
void Food::operator=(const Food& other)
{
	setName(other.name);
	this->kkal = other.kkal;
	this->weight = other.weight;
}
void Food::setName(const char* name)
{
	// memory leak
	if (this->name != nullptr)
		delete[] this->name;
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Food::print() const
{
	cout << endl;
	cout << "\t Food   :: " << name << endl;
	cout << "\t Kkal   :: " << kkal << endl;
	cout << "\t Weight :: " << weight << endl;
}
size_t Food::counter = 0;