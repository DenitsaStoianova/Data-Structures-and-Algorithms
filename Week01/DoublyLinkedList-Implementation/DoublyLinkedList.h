#pragma once

// Имплементация на двусвързан списък

class DoublyLinkedList
{
public:
	// Конструктори
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	DoublyLinkedList& operator=(const DoublyLinkedList& other);
	~DoublyLinkedList();

	// Добавяне на нов елемент в списъка
	void pushFront(int data);
	void pushBack(int data);

	// Принтиране на елементите
	void print() const;

private:
	struct Node  // Представяне на възел от списъка
	{
		int data; // Стойност на възела
		Node* next; // Указател, който пази връзка към следващия елемент в списъка
		Node* prev; // Указател, който пази връзка към предишния елемент в списъка

		Node(int data, Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

private:
	Node* first; // Указател, който пази връзка към първия елемент в списъка
	size_t size; // Пазим размера на списъка (ако е необходимо)

	// Помощни функции за работа с конструкторите
	void copy(const DoublyLinkedList& other);
	void clear();
};
