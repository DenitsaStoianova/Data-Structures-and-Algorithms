#include "pch.h"
#include <iostream>

// Задача 3

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

void pushBack(Node* &first, int data) // Подаваме списъка (указателя към първия му елемент) по референция за да може промените, които правим върху него да се запазят
{				      // след изпълнението на функцията (работим с оригиналния списък)				  
	Node* newNode = new Node(data);   

	if (first == nullptr)
	{
		first = newNode;
		return;
	}

	Node* current = first;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newNode;
}

void print(Node* &first)
{
	Node* current = first;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}

int countOfNodes(Node* &first)
{
	Node* current = first;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return count;
}

Node* constructList(Node* &first, int n)
{
	Node* current = first;
	Node* newList = nullptr;

	int size = countOfNodes(first);
	int lastN = size - n + 1;

	for (int i = 1; i <= size; i++)
	{
		if (i > n && i < lastN)
		{
			pushBack(newList, current->data);
		}

		current = current->next;
	}
	return newList;
}

int main()
{
	Node* first = nullptr;

	pushBack(first, 1);
	pushBack(first, 2);
	pushBack(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);
	pushBack(first, 6);
	pushBack(first, 7);
	pushBack(first, 8);
	pushBack(first, 9);
	pushBack(first, 10);

	print(first);
	Node* result = constructList(first, 3);
	print(result);

	return 0;
}
