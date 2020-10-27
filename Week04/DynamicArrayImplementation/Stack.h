#pragma once

// Имплементация на стек с динамичен масив

class Stack
{
public:
// Конструктори
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

// Основни операции
	void push(int data); // Добавяне на елемент
	int pop(); // Премахване на последния елемент

	bool isEmpty() const; // Проверка за празен стек

// Допълнителни операции
	int getTop() const; // Прочитане на първия елемент (последния добавен)
	size_t getSize() const; // Извличане на броя елементи

	bool isFull() const; // Проверка за препълнен стек

private:
	int* elements;
	size_t tos; // top of stack - броя на елементите
	size_t capacity;

// Помощни функции за работа с конструкторите
	void copy(const Stack& other);
	void del();
	void resize();
};
