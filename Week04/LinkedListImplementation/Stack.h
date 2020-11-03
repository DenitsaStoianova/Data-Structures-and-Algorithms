#pragma once

// Имплементация на стек с едносвързан списък

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

private:
	struct Node // Представяне на възел от списъка
	{
		int data;
		Node* next;

		Node(int data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

private:
	Node* tos; // Указател, който пази връзка към първия елемент в стека (т. е. последния елемент в стека - top of stack)
	size_t size;

	// Помощни функции за работа с конструкторите
	void copy(const Stack& other);
	void clear();
};
