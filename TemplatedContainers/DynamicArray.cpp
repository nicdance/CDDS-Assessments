#include "pch.h"
#include "DynamicArray.h"
,.


DynamicArray::DynamicArray()
{
}


DynamicArray::~DynamicArray()
{
}


int main() {
	DynamicArray myArray(10);
	myArray[3] = 8;

	return 0;
}