#include "pch.h"
#include <iostream>

// Задача 2

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

void pushBack(Node* &first, int data)  // Подаваме списъка (указателя към първия му елемент) по референция за да може промените, които правим върху него да се запазят
{			              // след изпълнението на функцията (работим с оригиналния списък)
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

void splitList(Node* &first)
{
	int middle = countOfNodes(first) / 2;
	Node* current = first;

	for (int i = 0; i < middle - 1; i++)
	{
		current = current->next;
	}

	Node* second = current->next;
	current->next = nullptr; // разделяме списъка на две части

	print(first);
	print(second);
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
	splitList(first);

	return 0;
}
