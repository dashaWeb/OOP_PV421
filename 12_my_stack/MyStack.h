#pragma once

template <typename T>
class MyStack
{
	enum Default {EMPTY = -1,DEFAULT_CAPACITY = 10, DEFAULT_GROW = 5};
public:
	MyStack(const size_t& capacity = DEFAULT_CAPACITY,const size_t& grow = DEFAULT_GROW);
	bool isEmpty() const;
	size_t getSize() const;
	void push(const T& element);
	void pop();
	T top() const;
	~MyStack();
private:
	T* stack = nullptr;
	size_t capacity;
	int top_ = EMPTY;
	size_t grow;
	bool full() const;
	void reserve();
};

template<typename T>
inline MyStack<T>::MyStack(const size_t& capacity, const size_t& grow)
	:capacity(capacity), grow(grow), stack(new T[capacity])
{
	//stack = new T[capacity];
}

template<typename T>
inline bool MyStack<T>::isEmpty() const
{
	return top_ == EMPTY;
}

template<typename T>
inline size_t MyStack<T>::getSize() const
{
	return top_ + 1;
}

template<typename T>
inline void MyStack<T>::push(const T& element)
{
	if (full())
		reserve();
	stack[++top_] = element;
}

template<typename T>
inline void MyStack<T>::pop()
{
	if(!isEmpty())
		--top_;
}

template<typename T>
inline T MyStack<T>::top() const
{
	if (!isEmpty())
		return stack[top_];
	return T();
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	delete[] stack;
}

template<typename T>
inline bool MyStack<T>::full() const
{
	return getSize() == capacity;
}

template<typename T>
inline void MyStack<T>::reserve()
{
	T* tmp = new T[capacity += grow];
	for (size_t i = 0; i < getSize(); i++)
	{
		tmp[i] = stack[i];
	}
	delete[] stack;
	stack = tmp;
}
