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

Node* split(Node* head)
{
	Node* slowPtr = head;
	Node* fastPtr = head;

	// slowwPtr се увеличада веднъж, а fastPtr - два пъти
	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}

	Node* secondHalf = slowPtr->next;
	slowPtr->next = nullptr;
	return secondHalf;
}

Node* merge(Node* &firstList, Node* &secondList)
{
	// Базови случаи - ако първия или втория списък са празни
	if (firstList == nullptr)
	{
		return secondList;
	}

	if (secondList == nullptr)
	{
		return firstList;
	}

	// Рекурсивно сливане на двата списъка, избирайки по-малкия елемент на всяка стъпка
	if (firstList->data < secondList->data)
	{
		firstList->next = merge(firstList->next, secondList);
		firstList->next->prev = firstList;
		firstList->prev = nullptr;
		return firstList;
	}
	else
	{
		secondList->next = merge(firstList, secondList->next);
		secondList->next->prev = secondList;
		secondList->prev = nullptr;
		return secondList;
	}
}

// Сортиране със сливане
Node *mergeSort(Node *head)
{
	if (head == nullptr || head->next == nullptr) // Базов случай (ако списъка има 0 или 1 елемент)
	{
		return head;
	}

	Node *second = split(head); // Разделяне на списъка на две половини

	// Рекурсивно сортиране на двете части 
	head = mergeSort(head); // head става първата половина от списъка
	second = mergeSort(second);

	return merge(head, second); // Сливане на двете части в сортиран списък
}

void print(Node* &head)
{
	Node* current = head;
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

	pushBack(first, 2);
	pushBack(first, 8);
	pushBack(first, 4);
	pushBack(first, 5);
	pushBack(first, 1);
	pushBack(first, 3);

	print(first);
	first = mergeSort(first);
	print(first);

	return 0;
}
