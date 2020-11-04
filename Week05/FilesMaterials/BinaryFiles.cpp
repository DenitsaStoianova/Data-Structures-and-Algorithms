#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

const int SIZE = 100;

// Намиране на размера на файла
int getFileSize(const std::string& fileName)
{
	std::ifstream file; //отваряне на файла за четене
	file.open(fileName, std::ios::binary | std::ios::ate); //поставя указателя на последната позиция

	if (!file.is_open())
	{
		std::cout << "Unable to open file.\n";
		return -1;
	}

	std::fstream::pos_type size = file.tellg(); // взимане на текущата позиция на указателя (намира се в края на файла)
	file.close();

	return (int)size;
}

void splitIntoWords(std::string* infoArray, const std::string& information, int& cntArray)
{
	size_t size = information.size();
	std::string word;

	for (size_t i = 0; i < size; i++) {
		word = "";
		while (information[i] != ' ' && i != size) {
			word += information[i];
			i++;
		}
		infoArray[cntArray++] = word;
	}
}

void writeToFile(const std::string& fileName, const std::string& headerFile, int numberOfWords, int cntArray, std::string* infoArray)
{
	std::ofstream outFile;
	outFile.open(fileName, std::ios::binary);

	if (!outFile)
	{
		std::cout << "Unable to open file!\n";
		return;
	}

	// в началото записваме заглавието на файла 
	unsigned sizeOfStr;
	sizeOfStr = headerFile.size();

	outFile.write((const char*)&sizeOfStr, sizeof(sizeOfStr)); // първо записваме неговият размер
	outFile.write(headerFile.c_str(), sizeOfStr); // а след това самото заглавие, преобразувано в const char*

	outFile.write((const char*)&numberOfWords, sizeof(numberOfWords)); // искаме да пазим във файла и броя на думите в изречението

	// записваме отделните думи в зависимост от това дали са числа или симолни низове
	std::string wordToFile;
	int digit;
	for (int i = 0; i < cntArray; i++)
	{
		wordToFile = infoArray[i];
		if (isdigit(wordToFile[0]))
		{
			digit = std::stoi(wordToFile); // преобразуваме към число и записваме въ файла
			outFile.write((const char*)&digit, sizeof(digit));
		}
		else
		{
			sizeOfStr = wordToFile.size();

			outFile.write((const char*)&sizeOfStr, sizeof(sizeOfStr));// първо записваме размера на думата
			outFile.write(wordToFile.c_str(), sizeOfStr); // а след това нейното съдържание
		}
	}
	outFile.close();
}

void readFromFile(const std::string& fileName, const std::string& headerFile, int numberOfWords, int cntArray, std::string* infoArray)
{
	std::ifstream inFile;
	inFile.open(fileName, std::ios::binary);

	if (!inFile) {
		std::cout << "Unable to open file\n";
		return;
	}

	/*
	// в случай, че искаме да прочетем и принтираме заглавието на файла и броя на думите в изречението
	unsigned strLengthRead;
	inFile.read((char*)&strLengthRead, sizeof(strLengthRead));

	std::string headerFromFile;
	char* bufferToHeader = new char[strLengthRead + 1]; // + 1 заради '/0'
	inFile.read(bufferToHeader, strLengthRead);
	bufferToHeader[strLengthRead] = '\0';
	headerFromFile = bufferToHeader;
	delete[] bufferToHeader;

	int numOfWordsRead;
	inFile.read((char*)&numOfWordsRead, sizeof(numOfWordsRead));

	std::cout << headerFromFile << " " << numOfWordsRead << "\n";
	*/

	// ако искаме да прескочим заглавието на файла и броя на думите в изречението
	// и да прочетем останалата информация
	int sizeToSkip = sizeof(unsigned) + headerFile.size() + sizeof(numberOfWords);
	inFile.seekg(sizeToSkip, std::ios::beg);

	unsigned wordSize;
	std::string wordFromFile;
	// прочитаме отделните думи в зависимост от това дали са числа или симолни низове
	for (int i = 0; i < cntArray; i++)
	{
		if (isdigit(infoArray[i][0])) // четем число
		{ 
			int digit;
			inFile.read((char*)&digit, sizeof(digit));
			std::cout << digit << "\n";
		}
		else // четем символен низ
		{ 
			inFile.read((char*)&wordSize, sizeof(wordSize)); // първо прочитаме размера на симолня низ, който се пази в променлива от тип unsigned във файла преди самия низ 
			
			char* bufferWord = new char[wordSize + 1]; // поставяме прочетения символен низ в буфер (типа на низа във файла е const char*)
			inFile.read(bufferWord, wordSize);
			bufferWord[wordSize] = '\0';
			wordFromFile = bufferWord; // присвояваме прочетения символен низ в буфера на променлива от тип string
			delete[] bufferWord; // освобождаваме паметта, заемана от буфера

			std::cout << wordFromFile << "\n";
		}
	}
	inFile.close();
}


// Четене и писане в двоичен файл
void writeAndReadExample()
{
	std::string name;
	std::getline(std::cin, name);

	int age;
	std::cin >> age;

	std::ofstream ofile;
	ofile.open("file.dat", std::ios::binary);

	if (ofile.is_open())
	{
		unsigned nameSize = name.size();
		ofile.write((const char*)&nameSize, sizeof(nameSize));
		ofile.write(name.c_str(), nameSize);

		ofile.write((const char*)&age, sizeof(age));
		ofile.close();
	}
	else
	{
		std::cout << "Unable to topen file.\n";
	}


	std::ifstream ifile;
	ifile.open("file.dat", std::ios::binary);

	if (ifile.is_open())
	{
		/*
		unsigned size;
		ifile.read((char*)&size, sizeof(size));

		std::string name;
		char* buffer = new char[size + 1];
		ifile.read(buffer, size);
		buffer[size] = '\0';
		name = buffer;
		delete[] buffer;
		*/

		int skipSize = sizeof(unsigned) + name.size();
		ifile.seekg(skipSize, std::ios::beg);

		int age;
		ifile.read((char*)&age, sizeof(age));
		ifile.close();

		//std::cout << "Name: " << name << "\n" << "Age: " << age << "\n";
		std::cout << "Age: " << age << "\n";
	}
	else
	{
		std::cout << "Unable to open file.\n";
	}
}


int main()
{
	std::string fileName = "binaryFile.dat";

	std::string headerFile; // заглавие на файла
	int numberOfWords; // брой думи, които ще се запишат
	std::cin >> headerFile >> numberOfWords;

	std::string information; // текст, който ще бъде записан във файла (състои се от числа и символни низове)
	std::cin.ignore();
	std::getline(std::cin, information);

	std::string infoArray[SIZE];
	int cntArray = 0;
	splitIntoWords(infoArray, information, cntArray); // разделяне на въведения текст на отделни думи

	writeToFile(fileName, headerFile, numberOfWords, cntArray, infoArray);

	readFromFile(fileName, headerFile, numberOfWords, cntArray, infoArray);

	return 0;
}
