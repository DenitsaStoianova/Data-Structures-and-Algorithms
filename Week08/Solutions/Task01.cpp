#include "pch.h"
#include <iostream>

struct Node
{
	int data;
	Node* prev;
	Node* next;

	Node(int data, Node* prev = nullptr, Node* next = nullptr)
	{
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

void pushBack(Node* &head, int data)
{
	Node* newNode = new Node(data);

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newNode;
	newNode->prev = current;
}

void print(Node* &head)
{
	if (head == nullptr)
	{
		std::cout << "List is empty.";
		return;
	}

	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}

void modifyList(Node* &head)
{
	int countRotations = 0;
	int minData = head->data;
	Node* current = head;
	while (current != nullptr && minData <= current->data)
	{
		countRotations++;
		current = current->next;
	}

	current->prev->next = nullptr;
	current->prev = nullptr;

	Node* secondPartPtr = current;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = head;
	head->prev = current;

	head = secondPartPtr;
	current = head;
	while (current->next != nullptr && current->next->data < countRotations)
	{
		current = current->next;
	}

	Node* newNode = new Node(countRotations);

	if (current->prev == nullptr)
	{
		newNode->next = current;
		current->prev = newNode;
		head = newNode;
	}
	else if (current->next == nullptr)
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
}

int main()
{
	Node* list1 = nullptr;
	pushBack(list1, 11);
	pushBack(list1, 12);
	pushBack(list1, 13);
	pushBack(list1, 14);
	pushBack(list1, 15);
	pushBack(list1, 1);
	pushBack(list1, 2);
	pushBack(list1, 3);
	pushBack(list1, 10);

	print(list1);
	modifyList(list1);
	print(list1);

	return 0;
}
