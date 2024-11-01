#include "Vector.h"

Vector::Vector()
	:Vector(1)
{
}

Vector::Vector(const size_t& size)
	:size(size), capacity(size)
{
	this->arr = new int[this->size] {};
}

Vector::Vector(const size_t& size, const int& value)
	:Vector(size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = value;
	}
}

Vector::Vector(const Vector& other)
	:Vector(other.size)
{
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
}
// a = b
Vector& Vector::operator=(const Vector& other)
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->size = other.size;
	this->capacity = this->size;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

void Vector::print() const
{
	std::cout << " Array has size ==> " << size << "; capacity ==> " << capacity << "\n\t";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

Vector::~Vector()
{
	if (arr != nullptr)
		delete[] arr;
}

int Vector::operator[](size_t index) const
{
	if (isValidIndex(index))
		return arr[index];
	std::cout << ">>>>>>>>> Error index (get) : " << index << std::endl;
	return INT_MIN;
}

int& Vector::operator[](size_t index)
{
	static int errVal;
	if (isValidIndex(index))
		return arr[index];
	std::cout << ">>>>>>>>> Error index (set) : " << index << std::endl;
	return errVal;
}

Vector Vector::operator()(size_t startIndex, size_t lastIndex) const
{
	if (startIndex > lastIndex)
		std::swap(startIndex, lastIndex);
	if (!isValidIndex(startIndex))
		return Vector(0);
	if (lastIndex >= size)
		lastIndex = size - 1;
	Vector tmp(lastIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = this->arr[i + startIndex];
	}
	return tmp;
}




void Vector::pushBack(const int& value)
{
	if (size >= capacity)
		resize();
	arr[size++] = value;
}
void Vector::resize()
{
	this->capacity *= 2;
	int* tmp = new int[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

std::ostream& operator<<(std::ostream& out, const Vector& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		out << obj.arr[i] << "\t";
	}
	out << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Vector& obj)
{
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		in >> obj[i];
	}
	return in;
}
