#pragma once
#include "Animal.h"
class Wolf :
    public Animal
{
public:
    Wolf(const string& place = "Africa", const size_t& age = 0, const size_t& weight = 0);
    ~Wolf();
    void print() const;
private:
    size_t weight;
};


class Dog :public Wolf
{
public:
    Dog(const string& place = "Africa", const size_t& age = 0, const size_t& weight = 0, const string& master = "No master");
    ~Dog();
    void print() const;
private:
    string master;
};
