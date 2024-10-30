#pragma once
#include <iostream>
using namespace std;
class Pupil; // prototype

class Teacher {
public:
	void setMarkMath(Pupil& pupil, const size_t mark);
	void setMarkEnglish(Pupil& pupil, const size_t mark);
};

class Pupil {
public:
	Pupil() = default;
	Pupil(const string& name, const size_t& math = 0, const size_t & english = 0)
		: name(name),math(math),english(english)
	{}
	void print() const;
	//friend void Teacher::setMarkMath(Pupil& pupil, const size_t mark);
	friend class Teacher;
private:
	string name = "None";
	size_t math = 0;
	size_t english = 0;
};

inline void Pupil::print() const
{
	cout << name << endl;
	cout << "Math    :: " << math << endl;
	cout << "English :: " << english << endl;
}

inline void Teacher::setMarkMath(Pupil& pupil, const size_t mark)
{
	pupil.math = mark;
}

inline void Teacher::setMarkEnglish(Pupil& pupil, const size_t mark)
{
	pupil.english = mark;
}
