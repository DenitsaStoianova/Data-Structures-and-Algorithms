#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isLetter(char c)
{
	return c >= 'A' && c <= 'Z';
}

int convertCharToNum(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	int charToNum = 0;
	while (isDigit(expr[i])) 
	{
		charToNum = (charToNum * 10) + (expr[i++] - '0');
	}
	return charToNum;
}

const std::string constructOperator(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	std::string strOperator = "";
	if (expr[i + 1] == '=')
	{
		if (expr[i] == '>')
		{
			strOperator = ">=";
		}
		else if (expr[i] == '<')
		{
			strOperator = "<=";
		}
		else if (expr[i] == '!')
		{
			strOperator = "!=";
		}
		i+=2;
		return strOperator;
	}
	strOperator += expr[i++];
	return strOperator;
}

bool checkNumbers(int num1, const std::string& op, int num2)
{
	if (op == ">")
	{
		return num1 > num2;
	}
	else if (op == ">=")
	{
		return num1 >= num2;
	}
	else if (op == "<")
	{
		return num1 < num2;
	}
	else if (op == "<=")
	{
		return num1 <= num2;
	}
	else if (op == "==")
	{
		return num1 == num2;
	}
	
	return num1 != num2;
}

const std::string constructKeyWord(const std::string& expr, size_t& i)
{
	if (expr[i] == ' ')
	{
		i++;
	}

	std::string word = "";
	while (isLetter(expr[i]))
	{
		word += expr[i++];
	}

	return word;
}

void checkCommandsFromStack(std::stack<std::string>& stack)
{
	std::string rightResult = stack.top(); stack.pop();
	std::string stackCommand = stack.top(); stack.pop();
	std::string leftResult = stack.top(); stack.pop();

	if (stack.top() == "(")
	{
		stack.pop();
	}

	if (stackCommand == "AND")
	{
		(leftResult == "true" && rightResult == "true") ? stack.push("true") : stack.push("false");
	}
	else if (stackCommand == "OR")
	{
		(leftResult == "false" && rightResult == "false") ? stack.push("false") : stack.push("true");
	}
}

const std::string evaluateExpression(const std::string& expression, const std::string& ifText, const std::string& elseText)
{
	std::stack<std::string> stack;

	int num1, num2;
	std::string op, result;
	size_t exprSize = expression.size();
	for (size_t i = 0; i < exprSize; i++)
	{
		if (expression[i] == ' ')
		{
			continue;
		}

		if (expression[i] == '(')
		{
			stack.push("(");
		}
		else if (isDigit(expression[i]))
		{
			num1 = convertCharToNum(expression, i);
			op = constructOperator(expression, i);
			num2 = convertCharToNum(expression, i);

			checkNumbers(num1, op, num2) ? stack.push("true") : stack.push("false");
		}
		else if (expression[i] == ')')
		{
			checkCommandsFromStack(stack);
		}
		else
		{
			stack.push(constructKeyWord(expression, i));
		}
	}
	return stack.top();
}

void readFromFile(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Unable to open " << fileName << " file.\n";
		return;
	}

	file.seekg(3, std::ios::beg);

	std::string expression;
	std::getline(file, expression);
	std::string ifText;
	std::getline(file, ifText);

	file.seekg(6, std::ios::cur);

	std::string elseText;
	std::getline(file, elseText);	

	file.close();

	std::string result = evaluateExpression(expression, ifText, elseText);

	result == "true" ? std::cout << ifText << "\n" : std::cout << elseText << "\n";
}

int main()
{
	readFromFile("expression.txt");

	return 0;
}
