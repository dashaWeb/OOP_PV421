#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node
{
	T data;
	Node* next, * prev;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		:data(data),prev(prev),next(next)
	{}
};

template<typename T>
class List
{
public:
	List() = default;
	void addHead(const T& data);
	void removeHead();
	void print() const;
	void printR() const;
	bool empty() const;
	void removeByData(const T& data);
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
	Node<T>* findNode(const T& data);
};

template<typename T>
inline void List<T>::addHead(const T& data)
{
	auto tmp = new Node<T>(data,nullptr,head);
	if (empty())
		tail = tmp;
	if (!empty())
		head->prev = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void List<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	delete tmp;
	if (empty())
		tail = nullptr;
	else
		head->prev = nullptr;
	--size;
}

template<typename T>
inline void List<T>::print() const
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List :: \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void List<T>::printR() const
{
	if (empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = tail;
	cout << "List :: \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline bool List<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void List<T>::removeByData(const T& data)
{
	auto find = findNode(data);
	if (find == nullptr)
		return;
	if (find == head)
	{
		removeHead();
		return;
	}
	if (find == tail) {
		//removeTail()
		return;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;

	delete find;
	--size;
}

template<typename T>
inline Node<T>* List<T>::findNode(const T& data)
{

	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}

	return tmp;
}
