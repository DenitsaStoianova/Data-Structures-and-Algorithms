#pragma once
#include "pch.h"
#include <iostream>
#include "DoublyLinkedList.h"

void DoublyLinkedList::copy(const DoublyLinkedList& other)
{
	this->size = other.size;

	Node* copyFirst = new Node(other.first->data);
	this->first = copyFirst;

	Node* otherCurrent = other.first; // Указател, който служи за обхождането на списъка, който искаме да копираме (other)
	Node* copyCurrent = this->first; // Указател, който служи за обхождането на текущия списък (this)
	Node* newNode = nullptr;

	while (otherCurrent->next != nullptr)
	{
		newNode = new Node(otherCurrent->next->data);
		copyCurrent->next = newNode;
		newNode->prev = copyCurrent;

		otherCurrent = otherCurrent->next; 
		copyCurrent = copyCurrent->next;
	}
}

void DoublyLinkedList::clear()
{
	Node* hoder = nullptr; // Указател, който служи за запазване на връзката към следващия елемент
	while (this->first != nullptr)
	{
		hoder = this->first->next;
		delete this->first;
		this->first = hoder;
	}
	this->size = 0;
}

DoublyLinkedList::DoublyLinkedList()
{
	this->first = nullptr;
	this->size = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
{
	this->copy(other);
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

DoublyLinkedList::~DoublyLinkedList()
{
	this->clear();
}

void DoublyLinkedList::pushFront(int data)
{
	Node* newNode = new Node(data);
	if (this->first != nullptr) 
	{
		newNode->next = this->first;
		this->first->prev = newNode;
	}
	this->first = newNode;
	this->size++;
}

void DoublyLinkedList::pushBack(int data)
{
	Node* newNode = new Node(data);
	if (this->first == nullptr) // Проверка дали списъка е празен
	{
		this->first = newNode;
	}
	else
	{
		Node* current = this->first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
	this->size++;
}

void DoublyLinkedList::print() const
{
	Node* current = this->first;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}
