#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

bool isOpen(char c)
{
	return c == '[' || c == '(' || c == '{';
}

bool isBalanced(const std::string& expression)
{
	std::stack<char> stack;

	size_t size = expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (isOpen(expression[i]))
		{
			stack.push(expression[i]);
		}
		else // При срещане на затваряща скоба
		{
			if (stack.empty()) // Ако няма отварящи скоби преди затваряща - изразът не е валиден
			{
				return false;
			}

			char stackElement = stack.top();
			char exprElement = expression[i];
			if (exprElement == ']' && stackElement == '[')
			{
				stack.pop();
			}
			else if (exprElement == ')' && stackElement == '(')
			{
				stack.pop();
			}
			else if (exprElement == '}' && stackElement == '{')
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return stack.empty();
}

void checkExpression(const std::string& fileName) 
{
	std::ifstream file(fileName); 

	if (!file.is_open()) 
	{
		std::cout << "Unable to open " << fileName << " file.\n";
		return;
	}

	std::string expression;
	file >> expression; 

	file.close(); 

	isBalanced(expression) ? std::cout << "Balanced\n" : std::cout << "Not balanced\n";
}

int main()
{
	std::string fileName; // Примерно имe: brackets.txt
	std::cin >> fileName;

	checkExpression(fileName);

	return 0;
}
