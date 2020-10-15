#include "pch.h"
#include <iostream>

struct Node
{
	double data;
	Node* next;
	Node* prev;

	Node(double data, Node* next = nullptr, Node* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

void pushBack(Node* &first, double data)
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

void deleteAverage(Node* &first)
{
	if (first == nullptr || first->next == nullptr || first->next->next == nullptr)
	{
		return;
	}

	Node* current = first;
	Node* holder = nullptr;

	while (current->next->next != nullptr)
	{
		holder = current->next;
		if (current->data == (current->next->data + current->next->next->data) / 2)
		{
			if (current == first)
			{
				current->next->prev = nullptr;
				first = current->next;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			delete current;
		}
		current = holder;
	}
}

int main()
{
	Node* first = nullptr;

	pushBack(first, 5);
	pushBack(first, 3);
	pushBack(first, 7);
	pushBack(first, 3.5);
	pushBack(first, 2);
	pushBack(first, 5);
	pushBack(first, 4.5);
	pushBack(first, 3);
	pushBack(first, 6);
	pushBack(first, 8);
	pushBack(first, 4);

	print(first);
	deleteAverage(first);
	print(first);

	return 0;
}
