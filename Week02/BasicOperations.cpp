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

// Добавяне на елемент в началото на списъка
void pushFront(Node* &first, int data)
{
	Node* newNode = new Node(data); // Създаваме си нов възел с подадената стойност

	if (first != nullptr)
	{
		newNode->next = first;
		first->prev = newNode;
	}

	first = newNode; 
}

// Добавяне на елемент в края на списъка
void pushBack(Node* &first, int data)
{
	Node* newNode = new Node(data); // Създаваме си нов възел с подадената стойност
	
	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		Node* current = first;
		while (current->next != nullptr) // Стигаме до последния елемент от списъка
		{
			current = current->next;
		}
		current->next = newNode; // Добавяме новосъздадения възел
		newNode->prev = current;
	}
}

// Добавяне на елемент преди посочената стойност
void pushBefore(Node* &first, int data, int beforeData)
{
	if (first == nullptr)
	{
		return;
	}

	Node* newNode = new Node(data);
	Node* current = first;

	while (current != nullptr && current->data != beforeData) // Стигаме до елемента, преди който искаме да добавим
	{
		current = current->next;
	}

	if (current->prev == nullptr) // Ако искаме да добавим елемент в началото на списъка
	{
		newNode->next = current;
		current->prev = newNode;
		first = newNode;
	}
	else
	{
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;
	}
}

// Добавяне на елемент след посочената стойност
void pushAfter(Node* &first, int data, int afterData)
{
	if (first == nullptr)
	{
		return;
	}

	Node* newNode = new Node(data);
	Node* current = first;

	while (current != nullptr && current->data != afterData)
	{
		current = current->next;
	}

	if (current->next == nullptr) // Ако искаме да добавим елемент в края на списъка
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

// Изтриване на първия елемент от списъка
void popFirst(Node* &first)
{
	if (first == nullptr)
	{
		return;
	}

	Node* holder = first->next;
	delete first;
	first = holder;
}

// Изтриване на последния елемент от списъка
void popLast(Node* &first)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->prev->next = nullptr;
	delete current;
}

// Изтриване на елемент по подадена стойност
void popByKey(Node* &first, int data)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	while (current != nullptr && current->data != data) // Стигаме до елемента, който искаме да изтрием
	{
		current = current->next;
	}

	if (current->prev == nullptr) // Ако трябва да изтрием първия елемент от списъка
	{
		current->next->prev = nullptr;
		first = current->next;
	}
	else if (current->next == nullptr) // Ако трябва да изтрием последния елемент от списъка 
	{
		current->prev->next = nullptr;
	}
	else // Ако трябва да изтрием елемент по средата на списъка
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}

	delete current;
}

// Изтриване на елемент по подадена позиция
void popAtPos(Node* &first, int pos)
{
	if (first == nullptr)
	{
		return;
	}

	Node* current = first;
	for (int i = 0; i < pos; i++) // Стигаме до посочената позиция
	{
		current = current->next;
	}

	if (current->prev == nullptr) // Ако трябва да изтрием първия елемент от списъка
	{
		current->next->prev = nullptr;
		first = current->next;
	}
	else if (current->next == nullptr) // Ако трябва да изтрием последния елемент от списъка 
	{
		current->prev->next = nullptr;
	}
	else // Ако трябва да изтрием елемент по средата на списъка
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}

	delete current;
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

	pushFront(first, 1);
	pushFront(first, 2);
	pushFront(first, 3);
	pushBack(first, 4);
	pushBack(first, 5);
	pushBack(first, 6);

	print(first);
	pushBefore(first, 10, 4);
	print(first);
	pushAfter(first, 11, 4);
	print(first);
	popLast(first);
	print(first);
	popByKey(first, 4);
	print(first);
	popAtPos(first, 2);
	print(first);

	return 0;
}
