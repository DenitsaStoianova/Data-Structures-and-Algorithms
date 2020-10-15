#include "pch.h"
#include <iostream>

// Задача 3

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

void moveLast(Node* &first)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	while (current->next != nullptr) // Стигаме до последния възел
	{
		current = current->next;
	}

	current->prev->next = nullptr;
	current->prev = nullptr;
	current->next = first; 
	first->prev = current;
	first = current;
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
	moveLast(first);
	print(first);

	return 0;
}
