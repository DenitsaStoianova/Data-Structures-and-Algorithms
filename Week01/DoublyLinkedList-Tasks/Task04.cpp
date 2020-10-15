#include "pch.h"
#include <iostream>

// Задача 4

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

void addElement(Node* &first, int n, int element)
{
	Node* current = first;
	int count = 1;
	Node* newNode = nullptr;

	while (current != nullptr)
	{
		if (count == n - 1)
		{
			newNode = new Node(element);
			if (current->next == nullptr)
			{
				current->next = newNode;
				newNode->prev = current;
			}
			else
			{
				newNode->next = current->next;
				newNode->prev = current;
				current->next->prev = newNode;
				current->next = newNode;
			}
			current = newNode;
			count = 0;
		}

		count++;
		current = current->next;
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
	pushBack(first, 6);
	pushBack(first, 7);
	pushBack(first, 8);
	pushBack(first, 9);
	pushBack(first, 10);

	print(first);
	addElement(first, 4, 11);
	print(first);

	return 0;
}
