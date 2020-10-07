#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList()
{
	this->first = nullptr;
	this->size = 0;
}

void SinglyLinkedList::copy(const SinglyLinkedList& other)
{
	this->size = other.size;

	Node* copyFirst = new Node(other.first->data);
	this->first = copyFirst; 

	Node* otherCurrent = other.first; // Указател, който служи за обхождането на списъка, който искаме да копираме (other)
	Node* copyCurrent = this->first;// Указател, който служи за обхождането на текущия списък (this)
	Node* newNode = nullptr;

	while (otherCurrent->next != nullptr) 
	{
		newNode = new Node(otherCurrent->next->data);
		copyCurrent->next = newNode;

		copyCurrent = copyCurrent->next;
		otherCurrent = otherCurrent->next;
	}
}

void SinglyLinkedList::clear()
{
	Node* holder = nullptr; // Указател, който служи за запазване на връзката към следващия елемент
	while (this->first != nullptr)
	{
		holder = this->first->next;
		delete this->first;
		this->first = holder;
	}
	this->size = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
{
	this->copy(other);
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

SinglyLinkedList::~SinglyLinkedList()
{
	this->clear();
}

void SinglyLinkedList::pushBack(int data)
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
	}
	this->size++;
}

void SinglyLinkedList::pushFront(int data)
{
	Node* newNode = new Node(data);
	if (this->first != nullptr)
	{
		newNode->next = this->first;
	}
	this->first = newNode;
	this->size++;
}

size_t SinglyLinkedList::getSize() const
{
	return this->size;
}

bool SinglyLinkedList::contains(int data) const
{
	Node* current = this->first;
	while (current != nullptr) 
	{
		if (current->data == data)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void SinglyLinkedList::print() const
{
	Node* current = this->first;

	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}
