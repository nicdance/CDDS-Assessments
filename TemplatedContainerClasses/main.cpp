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
		Iterator begin = { Begin() };
		Iterator end = { End() };
		std::cout << std::endl;
		while (begin.currentNode != nullptr )
		{
			value = *begin;
			std::cout << (value) << ":";
			++begin;
		}

	}

	void PushFront(T value) // add a new value to the front of the list
	{
		Insert(Begin(), value);
		/*
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
		nodecount++;*/
	}
	void PushBack(T value) // add a new value to the end of the list
	{
		Insert(End(), value);
		/*
		Node *node = new Node(value);
		if (tail == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->previous = tail;
			tail->next = node;
			tail = node;
		}
		nodecount++;*/
	}


	void Insert(Iterator it, T value) // add a new value one past the specified iterator location
	{
		Node * node = new Node(value);

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

	void Erase(Iterator it) // remove an element by its iterator
	{
		if (it == Begin())
		{
			it.currentNode->next->previous = nullptr;
			head = it.currentNode->next;
		}
		else if (it == End()) {
			it.currentNode->previous->next = nullptr;
			tail = it.currentNode->previous;
		}
		else
		{
			it.currentNode->next->previous = it.currentNode->previous;
			it.currentNode->previous->next = it.currentNode->next;
		}
		nodecount--;
	}
	void Remove(T value) // remove all elements with matching value
	{
		for (auto iterator = Begin(); iterator.currentNode != nullptr; ++iterator)
		{
			if (*iterator == value) {
				Erase(iterator);
			}
		}
	}

	void PopBack() // remove the last element
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else {
			Erase(End());
		}
	}
	void PopFront() // remove the first element
	{		
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else {
			Erase(Begin());
		}
		
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


	linkedL->PopBack();
	linkedL->PrintLinkedList();

	linkedL->PopFront();
	linkedL->PrintLinkedList();

	linkedL->PushFront(1);
	linkedL->PrintLinkedList();

	linkedL->PushBack(2);
	linkedL->PrintLinkedList();

	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		if (iterator.currentNode->data == 1) {
			linkedL->Insert(iterator, 10);
		}
	}
	linkedL->PrintLinkedList();


	linkedL->Remove(1);
	linkedL->PrintLinkedList();

	/*
	linkedL->Remove(1);
	linkedL->PrintLinkedList();

	linkedL->PopBack();
	linkedL->PrintLinkedList();

	linkedL->PopFront();
	linkedL->PrintLinkedList();

	linkedL->PushFront(1);
	linkedL->PrintLinkedList();

	linkedL->PushBack(3);
	linkedL->PrintLinkedList();
	*/


	/*
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


	linkedL->Remove(1);

	std::cout << std::endl << "Looping with Iterator in main" << std::endl;
	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		std::cout << *iterator << ":";
	}

	std::cout << "Total Elements: " << linkedL->Count() << std::endl;
	*/


	//TestDynamicArray();
	return 0;
}

