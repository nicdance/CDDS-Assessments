/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 1 - Templated Containers - Linked List
*/

#include "LinkedList.h"
#include <iostream>

int main()
{
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

		std::cout << "Attempt top remove 999 which does not exist" << std::endl;
		linkedL->Remove(999);
		linkedL->PrintLinkedList();
			   
		std::cout << "Find 4 and set to 6" << std::endl;
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

		//std::cout << "Clear List" << std::endl;
		//linkedL->Clear();
		//linkedL->PrintLinkedList();
		
		linkedL->PushBack(7);
		linkedL->PrintLinkedList();

		delete(linkedL);
	}
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}
