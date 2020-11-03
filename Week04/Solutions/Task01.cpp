#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

struct Node
{
	char data;
	Node* next;

	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

void pushBack(Node* &head, char data)
{
	Node* newNode = new Node(data);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

bool isPalindrome(Node* &first)
{
	std::stack<char> stack;
	Node* current = first;
	while (current != nullptr)
	{
		stack.push(current->data);
		current = current->next;
	}

	current = first;
	while (current != nullptr)
	{
		if (current->data != stack.top())
		{
			return false;
		}

		stack.pop();
		current = current->next;
	}
	return true;
}


int main()
{
	Node* first = nullptr;
	pushBack(first, 'A');
	pushBack(first, 'B');
	pushBack(first, 'C');
	pushBack(first, 'B');
	pushBack(first, 'A');

	 std::string result = isPalindrome(first) ? "Is Palinrome\n" : "Not Palindrome\n";
	 std::cout << result;

	return 0;
}
