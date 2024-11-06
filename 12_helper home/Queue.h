#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;

template<typename T>
struct Element
{
	T data;
	int priority;
	Element(const T& data = T(), const int& pr = 0)
		:data(data),priority(pr)
	{}
	string toString() {
		return "[" + to_string(priority) + "] - " + to_string(data) + ";";
	}
};

template<typename T>
class Queue
{
	enum Default {DEFAULT_CAPACITY = 10, DEFAULT_GROW = 5 };
public:
	Queue(const size_t& capacity = DEFAULT_CAPACITY, const size_t& grow = DEFAULT_GROW);
	size_t size() const;
	bool empty() const;
	T peek() const;
	void remove();
	void add(const Element<T>& data);
	void print() const;
private:
	Element<T>* queue = nullptr;
	size_t capacity = DEFAULT_CAPACITY;
	size_t grow = DEFAULT_GROW;
	size_t size_ = 0;
	bool full() const;
	void reserve();
	int priority() const;
};

template<typename T>
inline Queue<T>::Queue(const size_t& capacity, const size_t& grow)
	:capacity(capacity),grow(grow),queue(new Element<T>[capacity])
{}

template<typename T>
inline size_t Queue<T>::size() const
{
	return size_;
}

template<typename T>
inline bool Queue<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
inline T Queue<T>::peek() const
{
	return queue[priority()].data;
}

template<typename T>
inline void Queue<T>::remove()
{
	int index = priority();
	for (size_t i = index; i < size() - 1; i++)
	{
		queue[i] = queue[i + 1];
	}
	--size_;
}

template<typename T>
inline void Queue<T>::add(const Element<T>& data)
{
	if (full())
		reserve();
	queue[size_++] = data;
}

template<typename T>
inline void Queue<T>::print() const
{
	cout << "print Queue :: \t";
	for (size_t i = 0; i < size_; i++)
	{
		cout << queue[i].toString() << "\t";
	}
	cout << endl;
}

template<typename T>
inline bool Queue<T>::full() const
{
	return size_ == capacity;
}

template<typename T>
inline void Queue<T>::reserve()
{
	Element<T>* tmp = new Element<T>[capacity += grow];
	for (size_t i = 0; i < size(); i++)
	{
		tmp[i] = queue[i];
	}
	delete[] queue;
	queue = tmp;
}

template<typename T>
inline int Queue<T>::priority() const
{

	int max = 0; // index
	for (size_t i = 1; i < size(); i++)
	{
		if (queue[max].priority < queue[i].priority)
			max = i;
	}
	
	return max;
}
