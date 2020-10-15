#include "pch.h"
#include <iostream>

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

void removeByNode(Node* &first, Node* toRemove)
{
	if (toRemove->prev == nullptr) // Ако елемента който искаме да изтрием стои в началото на списъка
	{
		toRemove->next->prev = nullptr;
		first = toRemove->next;
	}
	else if (toRemove->next == nullptr) // Ако елемента който искаме да изтрием стои в края на списъка
	{
		toRemove->prev->next = nullptr;
	}
	else
	{
		toRemove->prev->next = toRemove->next;
		toRemove->next->prev = toRemove->prev;
	}

	delete toRemove;
}

void deleteSum(Node* &first)
{
	Node* current = first;
	int smallestData = INT_MAX, largestData = INT_MIN;
	while (current != nullptr) // Намираме най-малкия и най-големия елемент от списъка
	{
		if (current->data < smallestData)
		{
			smallestData = current->data;
		}

		if (current->data > largestData)
		{
			largestData = current->data;
		}

		current = current->next;
	}

	current = first;
	Node* nextHolder = nullptr;
	bool found = false;

	while (current != nullptr)
	{
		nextHolder = current->next; // Запазваме връзката към следващия елемент (за да не я изгубим след изтриването)
		if (current->data == largestData - smallestData)
		{
			found = true;
			removeByNode(first, current);
		}
		current = nextHolder;
	}

	if (!found)
	{
		std::cout << "Element not found.\n";
	}
}

int main()
{
	Node* first = nullptr;

	pushBack(first, 3);
	pushBack(first, 5);
	pushBack(first, 2);
	pushBack(first, 1);
	pushBack(first, 4);
	pushBack(first, 6);
	pushBack(first, 5);
	pushBack(first, 5);
	pushBack(first, 1);

	print(first);
	deleteSum(first);
	print(first);

	return 0;
}
