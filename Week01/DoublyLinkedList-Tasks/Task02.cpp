#include "pch.h"
#include <iostream>

// Задача 2

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node(int data, Node* next = nullptr, Node* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

void pushBack(Node* &first, int data)
{
	Node* newNode = new Node(data);
	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		Node* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}

void print(Node* first)
{
	while (first != nullptr)
	{
		std::cout << first->data << " ";
		first = first->next;
	}
	std::cout << "\n";
}

void addAfter(Node* &first, int afterElement, int addElement)
{
	if (first == nullptr)
	{
		return;
	}

	Node* newNode = new Node(addElement);
	Node* current = first;

	while (current != nullptr && current->data != afterElement) // Стигаме до елемента след който искаме да добавим
	{
		current = current->next;
	}

	if (current->next == nullptr) // Ако елемента след който искаме да добавим (afterElement) е последния елемент от списъка
	{
		current->next = newNode;
		newNode->prev = current;
	}
	else // Ако afterElement е между другите елементи на списъка 
	{
		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;
	}
}

int main()
{
	Node* first = nullptr;

	pushBack(first, 1);
	pushBack(first, 2);
	pushBack(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);
	
	print(first);
	addAfter(first, 3, 9);
	addAfter(first, 5, 9);
	print(first);

	return 0;
}
