/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 1 - Templated Containers - Linked List
*/

#include "LinkedList.h"

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
			linkedL->Insert(iterator, 3);
		}
	}
	linkedL->PrintLinkedList();

	linkedL->PushBack(4);
	linkedL->PrintLinkedList();

	linkedL->PushBack(5);
	linkedL->PrintLinkedList();

	linkedL->Remove(2);
	linkedL->PrintLinkedList();


	for (auto iterator = linkedL->Begin(); iterator.currentNode != NULL; ++iterator)
	{
		if (iterator.currentNode->data == 4) {
			*iterator = 6;
		}
	}

	linkedL->PrintLinkedList();


	linkedL->PopBack();
	linkedL->PrintLinkedList();

	linkedL->PopFront();
	linkedL->PrintLinkedList();

	linkedL->Clear();
	linkedL->PrintLinkedList();


	linkedL->PushBack(7);
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


	system("pause");
	return 0;
}
