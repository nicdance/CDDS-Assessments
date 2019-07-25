

template <typename T>
class DynamicArray {
private:
	T* alocatedSpace;	// stored ins
	int totalMemoryAllocated;		// total able to be stored
	int count;			// Total values stored

public:
	//Initialising
	// Constructors
	DynamicArray() :DynamicArray(0) //Sets up a default size
	{
	}

	DynamicArray(int initial) {
		if (initial > 0) {
			totalMemoryAllocated = initial;
			count = initial;
			alocatedSpace = new T[initial];
			for (int i = 0; i < initial; i++) {
				alocatedSpace[i] = 0; // Fill the array with a default value of 0
			}
		}
		else {
			alocatedSpace = nullptr;
		}
	}
	// Destructor
	~DynamicArray()
	{
		delete[] alocatedSpace;
	}
	// Assignment operator
	DynamicArray& operator=(const DynamicArray& other) {
		if (totalMemoryAllocated < other.count) {
			reserveExtra(other.totalMemoryAllocated - totalMemoryAllocated);
		}
		for (int i = 0; i < other.count; i++)
		{
			alocatedSpace[i] = other.alocatedSpace[i];
		}
	}
	// Copy Constructor
	DynamicArray(const DynamicArray& other) : DynamicArray(other.count) {
		//totalMemoryAllocated = other.count;
		//alocatedSpace = new int[totalMemoryAllocated];
		for (int i = 0; i < totalMemoryAllocated; i++) {
			alocatedSpace[i] = other.alocatedSpace[i];
		}
	}

	// [] operator overrides
	T& operator[](int index) {
		if ((index + 1) > totalMemoryAllocated) {
			reserveExtra(5);			// need to decide if only 1 extra space is allocated or 5? 10? more?
		}
		if (index + 1 > count) {
			count = index + 1;
		}
		return alocatedSpace[index]; // returned as a reference
	}

	const T& operator[](int index) const {
		assert(index < totalMemoryAllocated - 1);
		return alocatedSpace[index]; // returned as a reference
	}




	// add to middle of array
	void addAtIndex(T value, int index) {
		reserveExtra(1);
		for (int i = count; i > index; i--) {
			alocatedSpace[i] = alocatedSpace[i - 1];
		}
		alocatedSpace[index] = value;
	}


	// add to end of array
	void pushToEnd(T value) {
		reserveExtra(5);
		alocatedSpace[count] = value;
		count++;
	}
	// remove from end
	void removeFromEnd() {
		alocatedSpace[count - 1] = 0;
		count--;
	}


	// remove element at place position and copy rest of the values in order back
	void orderedRemove(int index) {
		count--;
		for (int i = index; i < count; i++) {
			alocatedSpace[i] = alocatedSpace[i + 1];
		}
	}
	// Copy last element to pisition and reduce count of total elements
	void unorderedRemove(int index) {
		if (index < (count - 1)) {
			alocatedSpace[index] = alocatedSpace[count - 1];
			removeFromEnd();
		}
	}


	//  Array can store this many but this isn't how many elements their actually is
	void reserveTotal(int size) {
		if (size < totalMemoryAllocated) {
			return;
		}
		// allocate new array
		T *temp = new T[size];
		// Copy Balues from old to new Array
		for (int i = 0; i < count; i++) {
			temp[i] = alocatedSpace[i];
		}
		for (int i = count; i < size; i++) {
			temp[i] = 0;
		}
		delete[] alocatedSpace;
		alocatedSpace = temp;
		totalMemoryAllocated = size;
	}


	void reserveExtra(int extra) {
		reserveTotal(count + extra);
	}


	// clear the array
	void clearAll() {
		count = 0;
		totalMemoryAllocated = 0;
		delete[] alocatedSpace;
		alocatedSpace = nullptr;
	}
	void clear() {
		count = 0;
	}



	bool operator==(DynamicArray) {
		return true;	// temp value so will compile
	}
	bool operator!=(DynamicArray) {
		return true;	// temp value so will compile
	}

	// returns how many elements there are
	int getCount() {
		return count;
	}

	// returns the current cappacity of the array
	int getCapacity() {
		return totalMemoryAllocated;
	}
};


template <typename T>
class Node {
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
class Iterator {
protected:
	Node<T>* position;
public:
	Iterator(Node<T> pos) {
		position = pos;
	}
	Iterator() { position = nullptr; }

	Iterator& operator++() { // steps to next data node if there is one
		position = position->next;
		return *this;
	}
	Iterator operator--() {// step to previous node if there is one
		position = position->previous;
		return *this;
	}
	bool operator==(const Iterator& other) { // Checks if iterators have same target
		return position == other.position;
	}
	bool operator!=(const Iterator& other) { // Checks if iterators don't have same target

		return position != other.position;
	}
	T& operator*() {
		return position->data;
	}
};

template <typename T>
class LinkedList {

private:
	int				nodecount = 0;
	Node<T>*			head;
	Node<T>*			tail;

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
		Iterator<T> begin = Begin();
		Iterator<T> end = End();
		do {
			value = *begin;
			std::cout << (value) << ":";
			++begin;
		} while (begin != end);

		/*
		Iterator<T> begin2 = Begin();
		Iterator<T> end2 = End();

		std::cout << std::endl << "From End" << std::endl;
		do {
			value = *end2;
			std::cout << value << ":";
			end2--;
		} while (end2 != begin2);


		T value;
		std::cout << std::endl << "From Begin" << std::endl;
		Iterator<T>* begin = Begin();
		Iterator<T>* end = End();
		do {
			value = **begin;
			std::cout << (value) << ":";
			begin++;
		} while (begin != end);

		Iterator<T>* begin2 = Begin();
		Iterator<T>* end2 = End();

		std::cout << std::endl << "From End" << std::endl;
		do {
			value = **end2;
			std::cout << value << ":";
			end2--;
		} while (end2 != begin2);






		Iterator<T> temp = Begin();
		std::cout << temp->position->data << ":";
		while (temp->position->next != nullptr) {
			temp->position = temp->position->next;
			std::cout << temp->position->data << ":";
		}

		Iterator<T> *temp2 = End();
		std::cout << std::endl << "Print backwards" << std::endl;
		std::cout << temp2->position->data << ":";
		while (temp2->position->previous != nullptr) {
			temp2->position = temp2->position->previous;
			std::cout << temp2->position->data << ":";
		}
		*/
	}

	void PushFront(T value) // add a new value to the front of the list
	{
		Node<T> *node = new Node<T>(value);
		Node<T> *temp = head;
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
		Node<T> *node = new Node<T>(value);
		if (tail->next == nullptr) {
			node->previous = tail;
			tail->next = node;
			tail = node;
		}
		nodecount++;
	}


	void Insert(Iterator<T> it, T value) // add a new value one past the specified iterator location
	{
		Node * node = new Node(value);

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		if (it->currentNode.next == NULL) {
			it->currentNode.next = node;
			node->previous = it->currentNode;
			tail = node;
		}
		else {
			node->next = it->currentNode.next;
			it->currentNode.next = node;
			node->previous = it->currentNode;
			node->next->previous = node;
		}
		nodecount++;
	}
	/*
	Iterator<T> Begin() // return an iterator to the first element
	{

		return Iterator<T>(head);
	}
	Iterator<T> End() // return an iterator to a null element
	{
		return Iterator<T>(tail);
	}
	*/


	Iterator<T> Begin() // return an iterator to the first element
	{
		Iterator<T>  iterator = new Iterator<T>(head);
		return iterator;
	}
	Iterator<T> End() // return an iterator to a null element
	{
		Iterator<T> iterator = new Iterator<T>(tail);
		return iterator;
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

	void Erase(Iterator<T> it) // remove an element by its iterator
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

	}
	void Clear() // remove all elements from the list
	{

	}

};


#include <iostream>

void TestDynamicArray();

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



	//for (auto i = linkedL->Begin(); i != linkedL->End(); i++)
	//{
	//	std::cout << *i << " ";
	//}

	std::cout << std::endl;
	std::cout << linkedL->First() << std::endl;
	std::cout << linkedL->Last() << std::endl;
	std::cout << "Total Elements: " << linkedL->Count() << std::endl;



	//TestDynamicArray();
	return 0;
}

void TestDynamicArray() {
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
}