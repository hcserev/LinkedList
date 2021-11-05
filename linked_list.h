#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <iostream>
#include <map>
#include <vector>

template<typename T>
class List
{
public:
	List();
	List(const List& list_);
	List& operator=(const List& list_);
	~List();

	void push_back(T data);
	void pop_front();
	void clear();
	void set_additional_link(const unsigned int index, const unsigned int second_link_index);

	unsigned int get_size() { return size; }
	T get_value() { return head->data; }
	T& operator[] (const unsigned int index);
private:
	template<typename T>
	class Node
	{
	public:
		std::shared_ptr<Node<T>> next;
		std::weak_ptr<Node<T>> p;
		T data;
		Node(T data = T(), std::shared_ptr<Node<T>> pNext = nullptr, std::shared_ptr<Node<T>> pSomeElement = nullptr)
		{
			this->data = data;
			this->next = pNext;
			this->p = pSomeElement;
		}
	};

	unsigned int size;
	std::shared_ptr<Node<T>> head;

	void copyList(const List& list_);

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::List(const List<T>& list_)
{
	copyList(list_);
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& list_)
{
	copyList(list_);
	return this;
}

template<typename T>
List<T>::~List()
{
	size=0;
}
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = std::make_shared<Node<T>>(data);
	}
	else
	{
		auto current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = std::make_shared<Node<T>>(data);
	}

	size++;
}


template<typename T>
void List<T>::pop_front()
{
	if (size > 0)
	{
		std::shared_ptr<Node<T>> temp = head;

		head = head->next;
		temp.reset();
		temp = nullptr;
		size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size > 0)
	{
		pop_front();
		size--;
	}
}

template<typename T>
void List<T>::set_additional_link(const unsigned int index, const unsigned int second_link_index)
{
	auto current = this->head;
	std::shared_ptr<Node<T>> mainNode = nullptr;
	std::shared_ptr<Node<T>> linkedNode = nullptr;

	unsigned int counter = 0;
	while (counter < size)
	{
		if (counter == index)
			mainNode = current;
		if (counter == second_link_index)
			linkedNode = current;

		current = current->next;
		counter++;
	}
	if (mainNode && linkedNode)
		mainNode->p = linkedNode;
}

template<typename T>
T& List<T>::operator[](const unsigned int index)
{
	auto current = this->head;
	unsigned int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
	return current->data; // never
}

template<typename T>
void List<T>::copyList(const List<T>& list_)
{
	size = 0;
	head = nullptr;

	std::map<Node<T>*, int> map_pointers;
	std::vector<int> vec_connections;

	std::shared_ptr<Node<T>> old_list = list_.head;

	int counter = 0;
	while (old_list != nullptr)
	{
		map_pointers[std::shared_ptr<Node<T>>(old_list).get()] = counter++;
		push_back(old_list->data);
		old_list = old_list->next;
	}

	old_list = list_.head;
	while (old_list != nullptr)
	{
		vec_connections.push_back(map_pointers[std::shared_ptr<Node<T>>(old_list->p).get()]);
		old_list = old_list->next;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		set_additional_link(i, vec_connections[i]);
	}
}

#endif // LINKED_LIST_H
