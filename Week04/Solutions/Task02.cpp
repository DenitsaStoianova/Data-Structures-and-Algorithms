#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

struct Node
{
	std::string data;
	Node* next;
	Node* prev;

	Node(const std::string& data, Node* next = nullptr, Node* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

void pushBack(Node* &first, const std::string& data)
{
	Node* newNode = new Node(data);
	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		Node* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}

const std::string convertToString(int number)
{
	if (number == 0)
	{
		return "0";
	}

	std::stack<char> stack;
	while (number != 0)
	{
		stack.push(number % 10 + '0');
		number /= 10;
	}
	std::string stringNum;
	while (!stack.empty())
	{
		stringNum += stack.top(); stack.pop();
	}
	return stringNum;
}

const std::string findMaxLength(const std::string& expression)
{
	std::stack<int> stack;
	stack.push(-1);
	int maxLength = 0, length;

	size_t size = expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (expression[i] == '(')
		{
			stack.push(i);
		}
		else
		{
			stack.pop();

			if (!stack.empty())
			{
				length = i - stack.top();
				if (length > maxLength)
				{
					maxLength = length;
				}
			}
			else
			{
				stack.push(i);
			}
		}
	}

	return convertToString(maxLength);
}

void modifyList(Node* &first)
{
	Node* current = first;
	while (current != nullptr)
	{
		current->data = findMaxLength(current->data);
		current = current->next;
	}
}

void print(Node* &first)
{
	Node* current = first;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}

int main()
{
	Node* first = nullptr;
	pushBack(first, "()))((()())(()");
	pushBack(first, "()()");
	pushBack(first, "(((()");
	pushBack(first, "(()())(()");
	pushBack(first, "((()()");
	pushBack(first, ")))");

	modifyList(first);
	print(first);


	return 0;
}
