﻿#pragma once
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
struct Node
{
	T data;
	Node * next;
	Node(const T& data = T(), Node* next = nullptr)
	:data(data),next(next){}
};
template<typename T>
class FwdList
{
public:
	FwdList() = default;
	bool empty() const;
	void print() const;

	void addHead(const T& data);
	void removeHead();
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline bool FwdList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (empty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head; // починаємо з початку списку;
	cout << "List :\t";
	while (tmp != nullptr) // виводимо доки не дойшли до кінця
	{
		cout << tmp->data << "\t";
		tmp = tmp->next; // переходимо до наступного вузла
	}
	cout << endl;
}

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
		tail = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	if (empty())
		tail = head;
	delete tmp;
	--size;
}
