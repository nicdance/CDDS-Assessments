/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 4 - InterProcessCommunication
*/

#include <windows.h>
#include <IPC.h>
#include <iostream>

void printMyData(MyData* data) {

	// write out what is in the memory block
	std::cout << "MyData = { ";
	std::cout << data->i << ", ";
	std::cout << data->f << ", ";
	std::cout << data->c << ", ";
	std::cout << data->b << ", ";
	std::cout << data->d << ", ";
	std::cout << " };" << std::endl;

}
int main()
{
	// IN APPLICATION 1 – The host of the named shared memory
	// open a named shared memory block
	HANDLE fileHandle = CreateFileMapping(
	INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
	nullptr, // optional security attributes
	PAGE_READWRITE, // read/write access control
	0, sizeof(MyData), // size of the memory block,
		mem_block);		// map the memory from the shared block to a pointer we can manipulate
		MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS,
			0, 0, sizeof(MyData));	data-> = true;	data->c = 'x';	data->d = 3.122345;

	// write to the memory block
	*data = myData;


	CloseHandle(fileHandle);
	return 0;
}