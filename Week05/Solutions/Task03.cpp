// InfixToPostfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

int checkPrecedence(char c)
{
	if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	return  0;
}

bool isDigit(char c)
{
	return c >= '0' &&  c <= '9';
}

std::string infixToPostfix(const std::string& expression)
{
	std::string postfixExpression;
	std::stack<char> stack;
	size_t size = expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (expression[i] == '(')
		{
			stack.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!stack.empty() && stack.top() != '(')
			{
				postfixExpression.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else if (isDigit(expression[i]))
		{
			postfixExpression.push_back(expression[i]);
		}
		else
		{
			while (!stack.empty() && checkPrecedence(stack.top()) >= checkPrecedence(expression[i]))
			{
				postfixExpression.push_back(stack.top());
				stack.pop();
			}
			stack.push(expression[i]);
		}
	}

	while (!stack.empty())
	{
		postfixExpression.push_back(stack.top());
		stack.pop();
	}

	return postfixExpression;
}

int calculate(int num1, char op, int num2)
{
	switch (op)
	{
	case '+': return num1 + num2;
	case '-': return num2 - num1;
	case '*': return num1 * num2;
	case '/': return num2 / num1;
	}
}

int calculatePostfixExpr(const std::string& expression)
{
	std::stack<int> stack;
	int num1, num2, result;

	size_t size = expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (isDigit(expression[i]))
		{
			stack.push(expression[i] - '0');
		}
		else
		{
			num1 = stack.top(); stack.pop();
			num2 = stack.top(); stack.pop();

			result = calculate(num1, expression[i], num2);
			stack.push(result);
		}
	}

	return stack.top();
}

void evaluateExpression(const std::string& fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		std::cout << "Unable to open " << fileName << " file.\n";
		return;
	}

	std::string infix;
	inFile >> infix;

	inFile.close();

	std::string postfix = infixToPostfix(infix);
	int result = calculatePostfixExpr(postfix);

	std::ofstream outFile("postfix.txt");

	if (!outFile.is_open())
	{
		std::cout << "Unable to open postfix.txt file.\n";
		return;
	}

	outFile << infix << "\n" << postfix << "\n" << result;

	outFile.close();
}

int main()
{
	evaluateExpression("infix.txt");

	return 0;
}
