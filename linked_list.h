#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <iostream>

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void pop_front();
	void clear();
	void set_additional_link(const unsigned int index, const unsigned int second_link_index);

	unsigned int getSize() { return Size; }
	T& operator[] (const unsigned int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pSomeElement;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pSomeElement = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pSomeElement = pSomeElement;
		}
	};

	unsigned int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}


template<typename T>
void List<T>::pop_front()
{
	if (Size > 0)
	{
		Node<T>* temp = head;

		head = head->pNext;
		delete temp;
		temp = nullptr;
		Size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (Size > 0)
	{
		pop_front();
		Size--;
	}
}

template<typename T>
void List<T>::set_additional_link(const unsigned int index, const unsigned int second_link_index)
{
	Node<T>* current = this->head;
	Node<T>* mainNode = nullptr;
	Node<T>* linkedNode = nullptr;

	int counter = 0;
	while (counter < Size)
	{
		if (counter == index)
			mainNode = current;
		if (counter == second_link_index)
			linkedNode = current;

		current = current->pNext;
		counter++;
	}
	mainNode->pSomeElement = linkedNode;
}

template<typename T>
T& List<T>::operator[](const unsigned int index)
{
	Node<T>* current = this->head;
	unsigned int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	return current->data; // never
}

#endif // LINKED_LIST_H
