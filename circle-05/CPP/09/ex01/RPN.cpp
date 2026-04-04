#include "RPN.hpp"

RPN::RPN() : operands()
{
}

RPN::RPN(const RPN &other) : operands(other.operands)
{
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		operands = other.operands;
	}
	return *this;
}

bool RPN::isValidDigit(const std::string &token, int &digit) const
{
	int val;
	char extra;
	std::istringstream iss(token);

	if (!(iss >> val))
		return false;

	if (iss >> extra)
		return false;

	if (val > 9)
		return false;

	digit = val;
	return true;
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	int digit;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operands.size() < 2)
				throw std::runtime_error("Error");

			int b = operands.top();
			operands.pop();
			int a = operands.top();
			operands.pop();

			if (token == "+")
				operands.push(a + b);
			else if (token == "-")
				operands.push(a - b);
			else if (token == "*")
				operands.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error");
				operands.push(a / b);
			}
		}
		else if (isValidDigit(token, digit))
		{
			operands.push(digit);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (operands.size() != 1)
		throw std::runtime_error("Error");

	return operands.top();
}
