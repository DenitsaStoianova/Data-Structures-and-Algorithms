#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include <unordered_map>

int convertCharToNum(const std::string& expr)
{
	size_t size = expr.size();
	int charToNum = 0;
	for (size_t i = 0; i < size; i++)
	{
		charToNum = (charToNum * 10) + (expr[i++] - '0');
	}
	return charToNum;
}

void addData(const std::string& fileLine, std::string& firstElement, std::string& secondElement)
{
	int separatorIndex = fileLine.find(" - ");
	firstElement = fileLine.substr(0, separatorIndex);
	secondElement = fileLine.substr(separatorIndex + 3, fileLine.size() - separatorIndex);
}

void readProducts(const std::string& fileName, std::unordered_map<std::string, int>& products)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Cannot open " << fileName << " file.\n";
		return;
	}

	std::string fileLine;
	std::string productName;
	std::string productQuantity;
	while (std::getline(file, fileLine))
	{
		addData(fileLine, productName, productQuantity);
		products[productName] = convertCharToNum(productQuantity);
	}

	file.close();
}

bool isLetter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

const std::string constructName(const std::string& fileLine, size_t& i)
{
	if (fileLine[i] == ' ' || fileLine[i] == ',')
	{
		i++;
	}

	std::string productName;
	while (isLetter(fileLine[i]))
	{
		productName += fileLine[i++];
	}
	return productName;
}

void readClients(const std::string& fileName, std::unordered_map<std::string, std::queue<std::string>>& clients)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Cannot open " << fileName << " file.\n";
		return;
	}

	std::string fileLine;
	std::string clientName;
	std::string products;
	size_t productsSize;
	std::string productName;
	while (std::getline(file, fileLine))
	{
		addData(fileLine, clientName, products);

		productsSize = products.size();
		for (size_t i = 0; i < productsSize; i++)
		{
			productName = constructName(products, i);
			clients[clientName].push(productName);
		}
	}

	file.close();
}

int main()
{
	std::unordered_map<std::string, int> products;
	readProducts("products.txt", products);

	std::cout << "Go shop:\n";
	std::queue<std::string> clientsQueue;
	std::string clientName;
	while (std::getline(std::cin, clientName)) // чете до въвеждане на ctrl + z
	{
		clientsQueue.push(clientName); // нареждаме клиентите в магазина
	}

	std::unordered_map<std::string, std::queue<std::string>> clients;
	readClients("clients.txt", clients);

	std::queue<std::string> clientList;
	std::string clientProduct;
	int productQuantityInMarket;
	int clientListSize;
	while (!clientsQueue.empty())
	{
		clientName = clientsQueue.front();
		clientsQueue.pop();

		std::cout << "Client " << clientName << " buy:\n";
		clientListSize = clients[clientName].size();
		while (clientListSize > 0)
		{
			clientProduct = clients[clientName].front();
			clients[clientName].pop();
			clientListSize--;

			productQuantityInMarket = products[clientProduct];
			if (productQuantityInMarket > 0)
			{
				std::cout << clientProduct << "\n";
				products[clientProduct]--;
			}
			else
			{
				std::cout << "Product " << clientProduct << " is not available.\n";
				clients[clientName].push(clientProduct);
			}
		}
	}

	std::cout << "Clients bought all products: \n";
	for (std::unordered_map<std::string, std::queue<std::string>>::iterator p = clients.begin(); p != clients.end(); p++)
	{
		if (p->second.size() == 0)
		{
			std::cout << p->first << "\n";
		}
	}
	
	return 0;
}
