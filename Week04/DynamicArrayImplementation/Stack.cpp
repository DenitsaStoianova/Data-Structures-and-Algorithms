#pragma once 
#include "pch.h"
#include "Stack.h"
#include <iostream>

void Stack::copy(const Stack& other)
{
	this->tos = other.tos;
	this->capacity = other.capacity;
	this->elements = new int[this->capacity]; // Заделяме памет за елементите на стека
	for (size_t i = 0; i < this->tos; i++)
	{
		this->elements[i] = other.elements[i];
	}
}

void Stack::del()
{
	delete[] this->elements;
}

void Stack::resize()
{
	this->capacity *= 2;
	int* temp = new int[this->capacity];
	for (size_t i = 0; i < this->tos; i++)
	{
		temp[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = temp;
}

Stack::Stack()
{
	this->tos = 0;
	this->capacity = 8;
	this->elements = new int[this->capacity]; // Първоначално заделяме памет за стек с 8 елемента
}

Stack::Stack(const Stack& other)
{
	this->copy(other);
}

Stack& Stack::operator=(const Stack& other)
{
	if (this != &other)
	{
		this->del();
		this->copy(other);
	}
	return *this;
}

Stack::~Stack()
{
	this->del();
}

void Stack::push(int data)
{
	if (this->isFull())
	{
		this->resize();
	}
	this->elements[this->tos++] = data;
}

int Stack::pop()
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	return this->elements[--this->tos];
}

int Stack::getTop() const
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	return this->elements[this->tos - 1];
}

size_t Stack::getSize() const
{
	return this->tos;
}

bool Stack::isEmpty() const
{
	return this->tos == 0;
}

bool Stack::isFull() const
{
	return this->tos == this->capacity;
}
