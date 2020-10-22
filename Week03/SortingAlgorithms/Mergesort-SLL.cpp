#include "pch.h"
#include <iostream>

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

void pushBack(Node* &first, int data)
{			              
	Node* newNode = new Node(data);

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

void split(Node* &head, Node* &firstList, Node* &secondList)
{
	Node* fastPtr = head;
	Node* slowPtr = head;

	// slowwPtr се увеличада веднъж, а fastPtr - два пъти
	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}

	firstList = head;
	secondList = slowPtr->next;
	slowPtr->next = nullptr;
}


Node* merge(Node* &firstList, Node* &secondList)
{
	Node* resultList = nullptr;

	// Базови случаи - ако първия или втория списък са празни
	if (firstList == nullptr)
	{
		return secondList;
	}
	else if (secondList == nullptr)
	{
		return firstList;
	}

	// Рекурсивно сливане на двата списъка, избирайки по-малкия елемент на всяка стъпка
	if (firstList->data <= secondList->data)
	{
		resultList = firstList;
		resultList->next = merge(firstList->next, secondList);
	}
	else
	{
		resultList = secondList;
		resultList->next = merge(firstList, secondList->next);
	}
	return resultList;
}

// Сортиране със сливане
void mergeSort(Node* &head)
{
	Node* currentList = head;
	Node* firstList = nullptr;
	Node* secondList = nullptr;

	if (currentList == nullptr || currentList->next == nullptr) // Базов случай (ако списъка има 0 или 1 елемент)
	{
		return;
	}

	split(head, firstList, secondList); // Разделяне на списъка на две половини

	// Рекурсивно сортиране на двете части 
	mergeSort(firstList);
	mergeSort(secondList);

	head = merge(firstList, secondList); // Сливане на двете части в сортиран списък
}


int main()
{
	Node* first = nullptr;

	pushBack(first, 2);
	pushBack(first, 8);
	pushBack(first, 4);
	pushBack(first, 1);
	pushBack(first, 5);
	pushBack(first, 3);

	print(first);
	mergeSort(first);
	print(first);

	return 0;
}
