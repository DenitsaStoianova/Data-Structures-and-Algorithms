#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

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

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int convertCharToNum(const std::string& expr, size_t& i)
{
	int charToNum = 0;
	while (isDigit(expr[i]))
	{
		charToNum = (charToNum * 10) + (expr[i++] - '0');
	}
	i--;
	return charToNum;
}

int calculateExpression(const std::string& expression)
{
	std::stack<char> symbolsStack;
	std::stack<int> numbersStack;
	int num1, num2;
	char op, result;

	size_t size = expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (isDigit(expression[i]))
		{
			numbersStack.push(convertCharToNum(expression, i));
		}
		else if (expression[i] != ')')
		{
			symbolsStack.push(expression[i]);
		}
		else
		{
			num1 = numbersStack.top(); numbersStack.pop();
			op = symbolsStack.top(); symbolsStack.pop();
			num2 = numbersStack.top(); numbersStack.pop();

			if (symbolsStack.top() == '(')
			{
				symbolsStack.pop();
			}

			result = calculate(num1, op, num2);
			numbersStack.push(result);
		}
	}

	return numbersStack.top();
}

void calcExpression(const std::string& fileName)
{
	std::ifstream inFile(fileName); 

	if (!inFile.is_open()) 
	{
		std::cout << "Unable to open " << fileName << " file.\n";
		return;
	}

	std::string expression;
	inFile >> expression; 

	inFile.close(); 

	int result = calculateExpression(expression);

	std::ofstream outFile;
	outFile.open(fileName, std::ios::app);

	if (!outFile.is_open()) 
	{
		std::cout << "Unable to open " << fileName << " file.\n";
		return;
	}

	outFile << " = " << result;

	outFile.close();
}

int main()
{
	calcExpression("expression.txt");

	return 0;
}
