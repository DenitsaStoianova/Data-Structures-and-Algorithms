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

void reverse(Node* &first)
{
	Node* current = first;
	Node* prevHolder = nullptr;

	while (current != nullptr)
	{
		prevHolder = current->prev;
		current->prev = current->next;
		current->next = prevHolder;
		current = current->prev;
	}

	if (prevHolder != nullptr)
	{
		first = prevHolder->prev;
	}
}

void reverseFirstK(Node* &first, int k)
{
	Node* current = first;
	Node* secondPart = nullptr;
	for (int i = 0; i < k - 1; i++)
	{
		current = current->next;
	}
	// Разделяме списъка на две части - обръщаме първата част и я сливаме с втората
	secondPart = current->next; // Пазим указател към втората част от списъка (която ще остане непроменена)
	current->next = nullptr;
	secondPart->prev = nullptr;

	Node* firstHolder = first;
	reverse(first); // Обръщаме първата част от списъка (която съдържа k елемента)
	firstHolder->next = secondPart;  
	secondPart->prev = firstHolder;
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

	print(first);
	reverseFirstK(first, 4);
	print(first);

	return 0;
}
