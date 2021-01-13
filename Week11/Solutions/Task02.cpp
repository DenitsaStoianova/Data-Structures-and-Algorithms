#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int convertCharToNum(const std::string& expr)
{
	int index = 0;
	int charToNum = 0;
	while (isDigit(expr[index]))
	{
		charToNum = (charToNum * 10) + (expr[index++] - '0');
	}
	return charToNum;
}

int calculateNewValue(char op, int variableValue, int number)
{
	switch (op)
	{
	case '+': return variableValue + number;
	case '-': return variableValue - number;
	case '*': return variableValue * number;
	case '/': return variableValue / number;
	case '%':return variableValue % number;
	}
}

void fillTable(HashTable<std::string, int>& hashTable, const std::string& instruction)
{
	std::string variableName = "";
	int number;
	int variableValue;

	size_t size = instruction.size();
	for (unsigned i = 0; i < size; ++i)
	{
		if (instruction[i] != ' ')
		{
			variableName += instruction[i];
			continue;
		}

		if (instruction[i + 1] == '=')
		{
			number = convertCharToNum(instruction.substr(i + 3, size - (i + 3)));
			hashTable.put(variableName, number);
			break;
		}
		else
		{
			number = convertCharToNum(instruction.substr(i + 4, size - (i + 4)));
			variableValue = hashTable.getValue(variableName);
			hashTable.put(variableName, calculateNewValue(instruction[i + 1], variableValue, number));
			break;
		}
	}
}

void executeProgram()
{
	std::ifstream file("file.txt");
	if (!file.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	HashTable<std::string, int> hashTable(6);
	std::string line;
	while (std::getline(file, line))
	{
		fillTable(hashTable, line);
	}

	file.close();
	hashTable.print();
}

int main()
{
	executeProgram();

	return 0;
}
