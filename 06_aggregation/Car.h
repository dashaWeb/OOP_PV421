#pragma once
#include "Engine.h"
class Car {
public:
	Car() = default;
	Car(const string& brand, const Engine& engine, const size_t& maxSpeed);
	Car(const string& brand, const string& model, const size_t& power, const double& volume, const size_t& maxSpeed);
	void print() const;
private:
	string brand = "Nobrand";
	//Engine engine; // {"Nomodel", 0,0}
	Engine engine = { "None",200,3.5 }; // ctor with parameters
	size_t maxSpeed = 120;
};

inline Car::Car(const string& brand, const Engine& engine, const size_t& maxSpeed)
	:brand{brand},
	engine{engine},
	maxSpeed{maxSpeed}
{}

inline Car::Car(const string & brand, const string & model, const size_t & power, const double& volume, const size_t & maxSpeed)
	: brand{brand},
	engine{model,power,volume},
	maxSpeed{maxSpeed}
{}

inline void Car::print() const
{
	cout << "Car  -->   " << brand << endl;
	cout << "Engine    :: "; engine.print();
	cout << "Max Speed :: " << maxSpeed << endl;
}

