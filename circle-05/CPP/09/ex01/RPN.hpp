#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> operands;
	bool isValidDigit(const std::string &token, int &digit) const;

public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);

	int evaluate(const std::string &expression);
};

#endif // RPN_HPP
