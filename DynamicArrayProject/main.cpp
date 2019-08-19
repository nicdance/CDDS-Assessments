/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 1 - Templated Containers - Dynamic Array
*/
#include "DynamicArray.h"
#include <iostream>

int main()
{
	DynamicArray<int> testArray = DynamicArray<int>();
	std::cout << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;

	testArray[0] = 1;
	testArray[1] = 2;
	testArray[2] = 3;
	testArray[3] = 4;
	std::cout << std::endl << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;
	for (int i = 0; i < testArray.getCount(); i++)
	{
		std::cout << testArray[i] << ",";
	}
	std::cout << std::endl;

	testArray.pushToEnd(5);
	testArray.pushToEnd(6);
	testArray.pushToEnd(7);
	testArray.pushToEnd(8);
	std::cout << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;
	for (int i = 0; i < testArray.getCount(); i++)
	{
		std::cout << testArray[i] << ",";
	}
	std::cout << std::endl << "Remove From End" << std::endl;

	testArray.removeFromEnd();
	std::cout << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;
	for (int i = 0; i < testArray.getCount(); i++)
	{
		std::cout << testArray[i] << ",";
	}
	std::cout << std::endl << "UNOrdered Remove" << std::endl;

	testArray.unorderedRemove(1);
	std::cout << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;
	for (int i = 0; i < testArray.getCount(); i++)
	{
		std::cout << testArray[i] << ",";
	}

	testArray.orderedRemove(3);
	std::cout << std::endl << "Ordered Remove" << std::endl;
	std::cout << "Elements in array: " << testArray.getCount() << std::endl;
	std::cout << "Capacity of Array: " << testArray.getCapacity() << std::endl;
	for (int i = 0; i < testArray.getCount(); i++)
	{
		std::cout << testArray[i] << ",";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}