#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

// Записване на ред в текстов файл
void writeToFile(const std::string& fileName, const std::string& expression)
{
	std::ofstream outFile;
	outFile.open(fileName);

	if (!outFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	outFile << expression;

	outFile.close();
}

// Добаяне на информация в края на файла, веднага след първоначалното му съдържание
void appendToFile(const std::string& fileName, const std::string& expression)
{
	std::ofstream outFile;
	outFile.open(fileName, std::ios::app);

	if (!outFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	outFile << expression;

	outFile.close();
}

// Четене на ред от текстов файл
void readFromFile(const std::string& fileName, std::string& expression)
{
	std::ifstream inFile(fileName);

	// Втори начин за отваряне на файл
	//std::fstream inFile;
	//inFile.open(fileName, std::ios::in); // указваме експлицитно, че отваряме файла за четене

	if (!inFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	inFile >> expression; // чете до срещане на space

	inFile.close();
}

// Четене на отделни изречения от файла
void readTextFromFile(const std::string& fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	std::string rowFromFile;
	while (std::getline(inFile, rowFromFile)) // чете от файла ред по ред
	{		
		std::cout << rowFromFile << "\n"; // принтиране на прочетения ред от файла
	}

	inFile.close();
}

// Намиране на броя на редовете във файла
int countNumberOfRows(const std::string& fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		std::cout << "Unable to open file.\n"; // или хвърляне на изключение
		return -1;
	}

	int rowsCount = 0;
	std::string rowFromFile;
	while (std::getline(inFile, rowFromFile)) // чете от файла ред по ред
	{
		rowsCount++; 
	}

	inFile.close();

	return rowsCount;
}

// Четене на отделни думи от файла
void readDifferentWords(const std::string& fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	std::string wordFromFile;
	while (inFile >> wordFromFile) // оператора >> чете до срещане на разстояние
	{
		std::cout << wordFromFile << "\n";
	}

	inFile.close();
}

// Изтриване на конкретно изречение от файла
void removeFromFile(const std::string& fileName, const std::string& sentenceToDel)
{
	std::ifstream inFile;
	inFile.open(fileName);

	std::ofstream tempFile;
	tempFile.open("temp.txt");

	if (!inFile.is_open() || !tempFile.is_open())
	{
		std::cout << "Unable to open file.\n";
		return;
	}

	std::string rowFromFile;
	while (std::getline(inFile, rowFromFile))
	{
		if (rowFromFile != sentenceToDel)
		{
			tempFile << rowFromFile << "\n";
		}
	}

	tempFile.close();
	inFile.close();

	const char* removedName = fileName.c_str();
	std::remove(removedName);
	std::rename("temp.txt", removedName);
}

int main()
{
	std::string fileName = "textfile.txt";

	writeToFile(fileName, "This is some file.");
	writeToFile(fileName, "Another line from file."); // презаписва новата информация

	appendToFile(fileName, "Text to append.");
	appendToFile(fileName, "\nSecond row from file.\nThird row.");

	readTextFromFile(fileName);

	std::cout << countNumberOfRows(fileName) << "\n";

	readDifferentWords(fileName);

	removeFromFile(fileName, "Second row from file.");

	return 0;
}
