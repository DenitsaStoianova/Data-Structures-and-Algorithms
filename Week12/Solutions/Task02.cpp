#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>

void generateWordVector(const std::string& word, std::unordered_map<std::string, int>& wordVector)
{
	std::string wordToken;
	size_t size = word.length() - 2;
	for (size_t i = 0; i <= size; i++) 
	{
		wordToken = word.substr(i, 2);
		wordVector[wordToken]++;
	}
}

void printWordVector(std::unordered_map<std::string, int>& wordVector)
{
	int vectorTokensSum = 0;

	std::cout << "Word vector: { ";
	for (std::unordered_map<std::string, int>::iterator it = wordVector.begin(); it != wordVector.end(); it++)
	{
		std::cout << "(" << it->first << ", " << it->second << ") ";
		vectorTokensSum += pow(it->second, 2);
	}
	std::cout << "}";

	std::cout << "Word vector length: " << sqrt(vectorTokensSum);
}

int main()
{
	std::string word;
	std::cout << "Enter word: ";
	std::cin >> word;
	
	std::unordered_map<std::string, int> wordVector;
	
	generateWordVector(word, wordVector);

	printWordVector(wordVector);
	
	return 0;
}
