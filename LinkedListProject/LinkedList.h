#pragma once
#include "assert.h"
#include "MemoryLeakTester.h"
template <typename T>
class LinkedList {
	// Declares Classes in Linked List
	class Node;
	class Iterator;

private:
	int				nodecount = 0;
	Node*			head;
	Node*			tail;

public:
	// Constructor
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	// Destructor
	~LinkedList() {
		Clear();
		delete head;
		delete tail;
	}

	void PrintLinkedList() {
		T value;
		Iterator begin = { Begin() };
		Iterator end = { End() };
		while (begin.currentNode != nullptr)
		{
			value = *begin;
			std::cout << (value) << ":";
			++begin;
		}
		std::cout << std::endl;

	}

	void PushFront(T value) // add a new value to the front of the list
	{
		std::cout << "PushFront " << std::endl;
		Insert(Begin(), value);
	}
	void PushBack(T value) // add a new value to the end of the list
	{
		std::cout << "PushBack " << std::endl;
		Insert(End(), value);
	}


	void Insert(Iterator it, T value) // add a new value one past the specified iterator location
	{

		std::cout << "Insert " << value << std::endl;
		//Node * node = new Node(value);
		Node * node = DBG_NEW Node(value);

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else if (head == tail) {
			head->next = node;
			node->previous = head;
			tail = node;
		}
		else	if (it.currentNode->next == nullptr) {
			it.currentNode->next = node;
			node->previous = it.currentNode;
			tail = node;
		}
		else {
			node->next = it.currentNode->next;
			it.currentNode->next = node;
			node->previous = it.currentNode;
			node->next->previous = node;
		}
		nodecount++;
	}

	Iterator Begin() // return an iterator to the first element
	{
		return Iterator(head);
	}
	Iterator End() // return an iterator to a null element
	{
		return Iterator(tail);
	}

	T& First() // return the first element by value, assert if no elements
	{
		return head->data;
	}
	T& Last() // return the last element by value, assert if no elements
	{
		return tail->data;

	}

	int Count() // return how many elements exist in the list
	{
		return nodecount;
	}

	void Erase(Node *currentNode) // remove an element by its iterator
	{
		if (currentNode == Begin().currentNode)
		{
			if (currentNode->next != nullptr)
			{
				std::cout << "Remove Start" << std::endl;
				currentNode->next->previous = nullptr;
				head = currentNode->next;
			}
			else
			{
				head = nullptr;
			}
		}
		else if (currentNode == End().currentNode) {
			std::cout << "Remove End" << std::endl;
			currentNode->previous->next = nullptr;
			tail = currentNode->previous;
		}
		else
		{
			std::cout << "Remove Element " << std::endl;
			currentNode->next->previous = currentNode->previous;
			currentNode->previous->next = currentNode->next;
		}
		currentNode->next = nullptr;
		currentNode->previous = nullptr;

		delete (currentNode);
		nodecount--;
	}

	/// LOOK HERE
	void Remove(T value) // remove all elements with matching value
	{
		std::cout << "Remove " << value << std::endl;
		for (auto iterator = Begin(); iterator.currentNode != nullptr; ++iterator)
		{
			if (*iterator == value) {
				Erase(iterator.currentNode);
				break;
			}
		}
	}

	void PopBack() // remove the last element
	{
		std::cout << "PopBack" << std::endl;
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else {
			Erase(End().currentNode);
		}
	}
	void PopFront() // remove the first element
	{
		std::cout << "PopFront" << std::endl;
		if (head != nullptr)
		{
			std::cout << "PopFront" << std::endl;
			if (head->next == nullptr)
			{
				tail = nullptr;
				delete head;
				head = nullptr;
			}
			else if (head == tail)
			{
				//head = nullptr;
				tail = nullptr;
				delete head;
				head = nullptr;
			}
			else {
				Erase(Begin().currentNode);
			}
		}

	}

	bool Empty() // return a Boolean, true if the list is empty, false otherwise
	{
		return head == nullptr;
	}
	void Clear() // remove all elements from the list
	{
		while (head != nullptr) {
			PopFront();
		}
	}

};

template <typename T>
class LinkedList<T>::Node {
public:
	T			data;
	Node*		previous;
	Node*		next;

	// Constructors
	Node()
	{
		previous = nullptr;
		next = nullptr;
	}

	~Node() {
		delete previous;
		delete next;
	}

	Node(T newData)
	{
		data = newData;
		previous = nullptr;
		next = nullptr;
	}
};

template <typename T>
class LinkedList<T>::Iterator {
public:
	Node* currentNode;

	Iterator(Node *pos) {
		currentNode = pos;
	}
	Iterator() { currentNode = nullptr; }
	
	Iterator& operator++() { // steps to next data node if there is one
		currentNode = currentNode->next;
		return *this;
	}
	Iterator operator--() {// step to previous node if there is one
		currentNode = currentNode->previous;
		return *this;
	}
	bool operator==(const Iterator& other) { // Checks if iterators have same target
		return currentNode == other.currentNode;
	}
	bool operator!=(const Iterator& other) { // Checks if iterators don't have same target

		return currentNode != other.currentNode;
	}
	T& operator*() {
		return currentNode->data;
	}
};


