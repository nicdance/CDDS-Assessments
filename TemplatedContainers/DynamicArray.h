#pragma once
class DynamicArray
{
public:
	int* m;
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray& other)
	~DynamicArray();
	operator[]();
	//add to end of array
	pushToEnd();
	//remove from end
	removeFromEnd;
	removeFromMiddle();
	addToMiddle();
};

