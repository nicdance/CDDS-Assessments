/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 3 - Searching and Sorting
*/

#include "DynamicArray.h"
#include <time.h>       /* time */
#include <iostream>


void PrintArray(DynamicArray<int> &array);
void SortArray(DynamicArray<int> &array);
void BubbleSortArray(DynamicArray<int> &array);
void InsertionSortArray(DynamicArray<int> &array);
void SelectionSortArray(DynamicArray<int> &array);
void swap(int *valueOne, int *valueTwo);
void SearchArray(DynamicArray<int> &array);
void AddValue(DynamicArray<int> &array);

int main()
{
	DynamicArray<int> *dynamicArray = new DynamicArray<int>();
	bool keepGoing = true;
	int errorcode = 0;

	srand(time(nullptr));
	

	for (int i = 0; i < 20; i++)
	{
		dynamicArray->pushToEnd(rand()%1000);

	}

	system("cls");
	while (keepGoing)
	{
		std::cout << "SEARCHING AND SORTING ASSESSMENT" << std::endl;

		switch (errorcode)
		{
		case 1:
			std::cout << "ERROR: Please enter a numberic value." << std::endl;
			break;
		case 2:
			std::cout << "ERROR: Please enter a number between 0-4." << std::endl;
			break;
		default:
			break;
		}

		std::cout << std::endl << "What would you like to do?" << std::endl;
		std::cout << "1. Add a number to the DynamicArray." << std::endl;
		std::cout << "2. Sort the DynamicArray" << std::endl;
		std::cout << "3. Search the DynamicArray" << std::endl;
		std::cout << "4. Print the DynamicArray. " << std::endl;
		std::cout << "0. Quit " << std::endl;

		int selection = 0;

		std::cin >> selection;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1);
			errorcode = 1;
		}
		else
		{
			switch (selection)
			{
			case 1:
				AddValue(*dynamicArray);
				break;
			case 2:
				SortArray(*dynamicArray);
				break;
			case 3:
				SearchArray(*dynamicArray);				
				break;
			case 4:
				PrintArray(*dynamicArray);
				break;
			case 0:
				keepGoing = false;
				std::cout << std::endl << " =) Good Bye!";
				break;
			default:
				errorcode = 2;
				break;
			}
		}
		std::cout <<  std::endl;
	}


	return 0;
}


void PrintArray(DynamicArray<int> &array) {
	std::cout << std::endl << "-- Printing DynamicArray --" << std::endl;
	for (int i = 0; i < array.getCount(); i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
}

void SortArray(DynamicArray<int> &array) 
{
	bool keepGoing = true;
	int errorcode = 0;

	while (keepGoing)
	{
		std::cout << std::endl << "Sort Array" << std::endl;

		switch (errorcode)
		{
		case 1:
			std::cout << "ERROR: Please enter a numberic value." << std::endl;
			break;
		case 2:
		default:
			break;
		}

		std::cout << "How would you like to sort your DynamicArray?" << std::endl;
		std::cout << "1. Bubble Sort" << std::endl;
		std::cout << "2. Insertion Sort" << std::endl;
		std::cout << "3. Selection Sort" << std::endl;
		std::cout << "0. Quit " << std::endl;

		int selection = 0;

		std::cin >> selection;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1);
			errorcode = 1;
		}
		else
		{
			switch (selection)
			{
			case 1:
				BubbleSortArray(array);
				keepGoing = false;
				break;
			case 2:
				InsertionSortArray(array);
				keepGoing = false;
				break;
			case 3:
				SelectionSortArray(array);
				keepGoing = false;
				break;
			case 0:
				keepGoing = false;
				break;
			default:
				errorcode = 2;
				break;
			}
		}

	}
}

void BubbleSortArray(DynamicArray<int> &array)
{
	std::cout << "- Unsorted Array -";
	PrintArray(array);
	std::cout << "Performing Bubble Sort" << std::endl;
	for (int i = 0; i < array.getCount(); i++)
	{
		for (int j = array.getCount()-1; j >=i+1; j--)
		{
			if (array[j] < array[j-1])
			{
				swap(&array[j], &array[j-1]);
			}
		}
	}
	std::cout << "- Sorted Array -";
	PrintArray(array);
}

void InsertionSortArray(DynamicArray<int> &array)
{
	std::cout << "- Unsorted Array -";
	PrintArray(array);
	std::cout << "Performing Insertion Sort" << std::endl;
	for (int i = 1; i < array.getCount(); i++)
	{
		int key = array[i];
		int j = i - 1;
		while (j>=0 && array[j]>key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
	std::cout << "- Sorted Array -";
	PrintArray(array);
}


void SelectionSortArray(DynamicArray<int> &array)
{
	std::cout << "- Unsorted Array -" << std::endl;
	PrintArray(array);
	std::cout << "Performing Selection Sort" << std::endl << std::endl;
	for (int i = 0; i < array.getCount() - 1; i++)
	{
		int minumumIndex = i;
		for (int j = i + 1; j < array.getCount(); j++)
		{
			if (array[j] < array[minumumIndex])
			{
				minumumIndex = j;
			}
		}
		swap(&array[minumumIndex], &array[i]);

	}
	std::cout << "- Sorted Array -";
	PrintArray(array);
}
void swap(int *valueOne, int *valueTwo)
{
	int temp = *valueOne;
	*valueOne = *valueTwo;
	*valueTwo = temp;
}

void SearchArray(DynamicArray<int> &array)
{
	std::cout << std::endl << "Search Array " << std::endl;
	int positionOfNumberToFind = rand()%array.getCount();
	int numberTofind = array[positionOfNumberToFind];	
	std::cout << "- Searching for " << numberTofind << std::endl;

	bool searching = true;
	int lower = 0;
	int upper = array.getCount();

	BubbleSortArray(array);
	int count = 0;
	while (searching)
	{
		count++;
		// if upperBound < lowerBound
		if (upper < lower)
		{
			std::cout << "Unable to locate " << numberTofind << "." << std::endl;
			break;
		}

		int middle = ((upper - lower) / 2) + lower;
		if (array[middle] < numberTofind)
		{
			lower = middle + 1;
		}
		else if (array[middle] > numberTofind)
		{
			upper = middle - 1;
		}
		else if (array[middle] == numberTofind)
		{
			std::cout << "Located " << numberTofind << " in " << count << " iterations." << std::endl;
			searching = false;
		}
	}


	std::cout << "End of SearchArray" << std::endl;
}

void AddValue(DynamicArray<int> &array) {
	bool addNumber = true;
	int errorcode = 0;
	while (addNumber)
	{
		std::cout << "Please Enter the value you would like to add." << std::endl;

		switch (errorcode)
		{
		case 1:
			std::cout << "ERROR: Please enter a numberic value." << std::endl;
			break;
		default:
			break;
		}

		int value = 0;

		std::cin >> value;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1);
			errorcode = 1;
		}
		else
		{
			array.pushToEnd(value);
			addNumber = false;
		}
	}

}