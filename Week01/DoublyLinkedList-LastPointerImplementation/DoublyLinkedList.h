#pragma once

// Имплементация на двусвързан списък с указател към последния елемент

struct Node // Представяне на възел от списъка
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

class DoublyLinkedList
{
public:
	// Конструктори
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& otherList);
	DoublyLinkedList& operator=(const DoublyLinkedList& otherList);
	~DoublyLinkedList();

	// Добавяне на нов елемент в списъка
	void pushFront(int data);
	void pushBack(int data);

	// Изтриване на елемент от списъка
	void removeByKey(int data);
	void removeByNode(Node* toRemove);

	// Принтиране на елементите
	void print() const;

private:
	Node* first; // Указател, който пази връзка към първия елемент в списъка
	Node* last; // Указател, който пази връзка към последния елемент в списъка

	// Помощни функции за работа с конструкторите
	void copy(const DoublyLinkedList& otherList);
	void clear();
};
