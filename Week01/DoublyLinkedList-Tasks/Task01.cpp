#include "pch.h"
#include <iostream>

// Задача 1

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

void swapNodes(Node* &first, int element)
{
	if (first == nullptr || first->next == nullptr || first->next->next == nullptr)  
	{
		std::cout << "Cannot swap elements\n";
		return;
	}

	bool found = false;
	int temp;
	Node* current = first;

	while (current != nullptr)
	{
		if (current->data == element && current->prev->prev != nullptr)
		{
			found = true;
			temp = current->data;
			current->data = current->prev->prev->data;
			current->prev->prev->data = temp;
		}
		current = current->next;
	}

	if (!found)
	{
		std::cout << "Cannot swap elements\n";
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
	swapNodes(first, 9);
	print(first);

	return 0;
}
