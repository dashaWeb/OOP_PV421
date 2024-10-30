#pragma once
#include <iostream>
class Vector {

public:
	Vector(); // default ctor; size = 1
	Vector(const size_t& size);
	Vector(const size_t& size, const int& value);


	Vector(const Vector& other);
	Vector& operator = (const Vector& other);

	const size_t& getSize() const { return this->size; }
	const size_t& getCapacity() const { return this->capacity; }
	void print() const;

	~Vector();

	int operator[](size_t index) const; // get
	int& operator[](size_t index); // set
	Vector operator()(size_t startIndex, size_t lastIndex) const;
	// 10 20 *30 *40 *50 60 70 80
	// [2:4]

	void pushBack(const int& value);


	friend std::ostream& operator << (std::ostream& out,const Vector& obj); // cout << obj
private:
	int* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	bool isValidIndex(size_t index) const;
	void resize();
};

std::istream& operator >> (std::istream& in, Vector& obj); // cin >> obj;

inline bool Vector::isValidIndex(size_t index) const
{
	return index < size;
}


