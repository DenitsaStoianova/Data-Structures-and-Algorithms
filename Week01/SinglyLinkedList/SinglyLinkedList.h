#pragma once

// Имплементация на едносвързан списък

class SinglyLinkedList
{
public:
	// Конструктори
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& other);
	SinglyLinkedList& operator=(const SinglyLinkedList& other);
	~SinglyLinkedList();

	// Добавяне на нов елемент в списъка
	void pushBack(int data);
	void pushFront(int data);

	// Информативни методи
	size_t getSize() const;
	bool contains(int data) const;
	void print() const;

private:
	struct Node // Представяне на възел от списъка
	{
		int data; // Стойност на възела
		Node* next; // Указател, който пази връзка към следващия елемент

		Node(int data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

private:
	Node* first; // Указател, който пази връзка към първия елемент в списъка
	size_t size; // Пазим размера на списъка (ако е неоходимо)

	// Помощни функции за работа с конструкторите
	void copy(const SinglyLinkedList& other);
	void clear();
};
