#include <iostream>
#include <string>
using namespace std;


class Fraction
{
private:
	int num, denom;

public:
	Fraction(const int& num, const int& denom)
		:num{ num }, denom{denom}
	{}
	string getFraction()
	{
		return to_string(num) + "/" + to_string(denom);
	}
	Fraction sum(const Fraction& other)
	{
		int num_ = this->num * other.denom + this->denom * other.num;
		int denom_ = this->denom * other.denom;
		Fraction res(num_, denom_);
		return res;
	}
};

int main()
{
	Fraction one(1, 2);
	Fraction two(2, 3);
	Fraction res = one.sum(two);
	cout << one.getFraction() << " + " << two.getFraction() << " = " << res.getFraction() << endl;
}

