#include "pch.h"
#include <iostream>

// Задача 1

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

void pushBack(Node* &first, int data) // Подаваме списъка (указателя към първия му елемент) по референция
{			// за да може промените, които правим върху него да се запазят
	Node* newNode = new Node(data);   // след изпълнението на функцията (работим с оригиналния списък)

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

void swapWithSecond(Node* &first, int element)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	int temp;

	while (current->next->next != nullptr)
	{
		if (current->data == element)
		{
			temp = current->data;
			current->data = current->next->next->data;
			current->next->next->data = temp;
		}
		current = current->next;
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

int main()
{
	Node* first = nullptr;

	pushBack(first, 1);
	pushBack(first, 2);
	pushBack(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);

	print(first);
	swapWithSecond(first, 4);
	print(first);

	return 0;
}
