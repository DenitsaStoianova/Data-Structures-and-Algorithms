#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

bool isLetter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

const std::string constructName(const std::string& fileLine, size_t& i)
{
	std::string personName;
	i++; // прескачаме @
	while (isLetter(fileLine[i]))
	{
		personName += fileLine[i++];
	}
	return personName;
}

void findNamesInLine(const std::string& fileLine, std::unordered_map<std::string, int>& mentionedPeople)
{
	std::string personName;
	size_t size = fileLine.size();
	for (size_t i = 0; i < size; i++) 
	{
		if (fileLine[i] == '@')
		{
			personName = constructName(fileLine, i);
			mentionedPeople[personName]++;
		}
	}
}

void readFromFile(const std::string& fileName, std::unordered_map<std::string, int>& mentionedPeople)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Cannot open " << fileName << " file.\n";
		return;
	}

	std::string fileLine;
	while (std::getline(file, fileLine))
	{
		findNamesInLine(fileLine, mentionedPeople);
	}

	file.close();
}

int main()
{
	std::unordered_map<std::string, int> mentionedPeople;
	
	readFromFile("text.txt", mentionedPeople);

	std::string personName;
	std::cout << "Enter person name: ";
	std::cin >> personName;

	if (mentionedPeople.count(personName)) // .count() - връща 1 ако ключа е намерен и 0 в противен случай
	{
		std::cout << personName << " is mentioned " << mentionedPeople[personName] << " times at the text.\n";
	}
	else
	{
		std::cout << personName << " is not mentioned at the text.\n";
	}

	return 0;
}
