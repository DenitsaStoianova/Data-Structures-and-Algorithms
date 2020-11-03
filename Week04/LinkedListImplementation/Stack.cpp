#pragma once
#include "Stack.h"
#include <iostream>

void Stack::copy(const Stack& other)
{
	this->size = other.size;
	this->tos = new Node(other.tos->data);

	Node* otherCurrent = other.tos;
	Node* copyCurrent = this->tos;

	while (otherCurrent->next != nullptr)
	{
		copyCurrent->next = new Node(otherCurrent->next->data);
		copyCurrent = copyCurrent->next;
		otherCurrent = otherCurrent->next;
	}
}

void Stack::clear()
{
	Node* holder = nullptr; 
	while (this->tos != nullptr)
	{
		holder = this->tos->next;
		delete this->tos;
		this->tos = holder;
	}
	this->size = 0;
}

Stack::Stack()
{
	this->tos = nullptr;
	this->size = 0;
}

Stack::Stack(const Stack& other)
{
	this->copy(other);
}

Stack& Stack::operator=(const Stack& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

Stack::~Stack()
{
	this->clear();
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);
	newNode->next = this->tos;
	this->tos = newNode;
	this->size++;
}

int Stack::pop()
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	Node* holder = this->tos->next;
	int data = holder->data;
	delete this->tos;
	this->tos = holder;
	this->size--;
	return data;
}

bool Stack::isEmpty() const
{
	return this->tos == nullptr;
}

int Stack::getTop() const
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	return this->tos->data;
}

size_t Stack::getSize() const
{
	return this->size;
}
