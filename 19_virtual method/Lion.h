#pragma once
#include "Animal.h"
class Lion :
	public Animal
{
public:
	Lion(const string& place = "Africa", const size_t& age = 0, bool isAlone = false);
	void print() const; // перекриває метод з базового класу
	void eat() const override; // перевизначаємо віртуальний метод базового класу
	~Lion();
private:
	bool isAlone;
};
