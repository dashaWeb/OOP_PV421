#include <iostream>
#include <string>
using namespace std;

const size_t MIN_POWER = 50;
const size_t MAX_POWER = 100;

const double MIN_VOLUME = 0.7;
const double MAX_VOLUME = 6;

const size_t MAX_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;

struct Date
{
	size_t day, month, year;
	string getDate()
	{
		return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
	}
};

class Car {
private:
	string brand = "NoBrand";
	string color = "none";
	size_t power = MIN_POWER;
	double volume = MIN_VOLUME;
	size_t max_speed = MAX_SPEED_LOW;
	Date date{};

public:

	Car() = default;
	//Car(const string& brand, const string& color, const Date& date)
	//{
	//	//this->brand = brand;
	//	setBrand(brand);
	//	this->color = color;
	//	this->date = date;
	//}
	Car(const string& brand, const string& color, const Date& date)
		:date{date}
	{
		setBrand(brand);
		setColor(color);
	}
	string getBrand()
	{
		return this->brand;
	}
	string getColor()
	{
		return this->color;
	}
	void setBrand(const string& brand)
	{
		if (brand.empty() || brand == " ")
		{
			cout << "Error!!! brand is empty" << endl;
		}
		else {
			this->brand = brand;
		}
	}
	void setColor(const string& color)
	{
		if (!color.empty() and color != " ")
			this->color = color;
	}
	void print()
	{
		cout << "====================== " << this->brand << " =======================" << endl;
		cout << "\t Color     :: " << this->color << endl;
		cout << "\t Power     :: " << this->power << endl;
		cout << "\t Volume    :: " << this->volume << endl;
		cout << "\t Max Speed :: " << this->max_speed << endl;
		cout << "\t Date      :: " << this->date.getDate() << endl;
	}
	void input()
	{
		cout << "\t Brand     :: "; getline(cin, this->brand);
		cout << "\t Color     :: "; getline(cin, this->color);
		cout << "\t Power     :: "; cin >> this->power;
		cout << "\t Volume    :: "; cin >> this->volume;
		cout << "\t Max Speed :: "; cin >> this->max_speed;
		cout << "\t Date      :: "; cin >> this->date.day >> this->date.month >> this->date.year;
	}

	double averagePower(Car other)
	{
		return (this->power + other.power) / 2;
	}

};

// public  - відкритий доступ. Маємо досту до полів та методів і за межами класу
// private - доступ закритий, доступ до полів і методів маємо лише в межах класу 
// protected - захищений доступ. Маємо доступ в межах класу і класах наслідників

int main()
{
	Date date = { 2,5,2020 };
	cout << date.getDate() << endl;

	Car ford;
	Car bmw("BMW", "black", { 5,8,2012 });
	cout << "Brand :: " << bmw.getBrand() << endl;
	bmw.setBrand("");
	cout << "Brand :: " << bmw.getBrand() << endl;
	ford.setColor("red");
	cout << "Color ford :: " << ford.getColor() << endl;
	bmw.print();
	ford.input();
	ford.print();
}

