/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 1 - Templated Containers
*/
#include "pch.h"
#include "assert.h"


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
		delete *head;
		delete *tail;
	}

	void PrintLinkedList() {
		T value;
		std::cout << std::endl << "From Begin" << std::endl;
		Iterator begin = { Begin() };
		Iterator end = { End() };

		while (begin.currentNode != nullptr )
		{
			value = *begin;
			std::cout << (value) << ":";
			++begin;
		}

	}

	void PushFront(T value) // add a new value to the front of the list
	{
		Node *node = new Node(value);
		Node *temp = head;
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head = node;
			node->next->previous = node;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			tail = temp;
		}
		nodecount++;
	}
	void PushBack(T value) // add a new value to the end of the list
	{
		Node *node = new Node(value);
		if (tail->next == nullptr) {
			node->previous = tail;
			tail->next = node;
			tail = node;
		}
		nodecount++;
	}


	void Insert(Iterator it, T value) // add a new value one past the specified iterator location
	{
		Node * node = new Node(value);

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		if (it.currentNode->next == nullptr) {
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

	void Erase(Iterator it) // remove an element by its iterator
	{

	}
	void Remove(T value) // remove all elements with matching value
	{

	}

	void PopBack() // remove the last element
	{

	}
	void PopFront() // remove the first element
	{

	}

	bool Empty() // return a Boolean, true if the list is empty, false otherwise
	{
		return head == nullptr;
	}
	void Clear() // remove all elements from the list
	{

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




#include <iostream>


int main()
{
	LinkedList<int>* linkedL = new LinkedList<int>();
	linkedL->PushFront(1);
	linkedL->PrintLinkedList();
	linkedL->PushFront(3);
	linkedL->PrintLinkedList();
	linkedL->PushBack(4);
	linkedL->PrintLinkedList();
	linkedL->PushFront(5);
	linkedL->PrintLinkedList();

	std::cout << std::endl << "Looping with Iterator in main" << std::endl;
	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		std::cout << *iterator << ":";
	} 

	std::cout << std::endl << "Inser After 3" << std::endl;
	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		if (iterator.currentNode->data == 3) {
			linkedL->Insert(iterator, 10);
		}
	}


	std::cout << std::endl << "Looping with Iterator in main" << std::endl;
	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		std::cout << *iterator << ":";
	}


	std::cout << std::endl;
	std::cout << linkedL->First() << std::endl;
	std::cout << linkedL->Last() << std::endl;
	std::cout << "Total Elements: " << linkedL->Count() << std::endl;



	//TestDynamicArray();
	return 0;
}

