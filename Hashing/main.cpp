/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 4 - Hashing
*/
#include "HashFunction.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

int main()
{
	std::vector<std::string> dictionary;
	std::ifstream inputFile("../words.txt", std::ios::in);
	while (!inputFile.eof())
	{
		std::string word;
		getline(inputFile, word);
		std::cout << word << std::endl;
		dictionary.push_back(word);
	}

	// hash processing
	const int size = 100;

	std::vector<std::vector<std::string>> hashmap;
	hashmap.resize(size);

	for (const auto& word : dictionary)
	{
		auto hash = HashFunction::defaultHashFunction(word.c_str(), word.length) % size;
		hashmap[hash].push_back(word);
	}

	// hash pre processing done
	
	for (int i = 0; i < dictionary.size; i++)
	{
		const auto& stringToFind = dictionary[rand() % dictionary.size()];
		auto hash = HashFunction::defaultHashFunction(stringToFind.c_str(), stringToFind.length) % size;
		auto & listToSearch = hashmap[hash];
		for (const auto& word : listToSearch)
		{
			if (stringToFind == word)
			{
				std::cout << "You found " << stringToFind << std::endl;
			}
		}
	}
	return 0;
}