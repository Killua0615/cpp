#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/')) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (token[0] == '+')
				_stack.push(a + b);
			else if (token[0] == '-')
				_stack.push(a - b);
			else if (token[0] == '*')
				_stack.push(a * b);
			else if (token[0] == '/') {
				if (b == 0)
					throw std::runtime_error("Error");
				_stack.push(a / b);
			}
		} else {
			if (token.length() != 1 || token[0] < '0' || token[0] > '9')
				throw std::runtime_error("Error");
			_stack.push(token[0] - '0');
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}
