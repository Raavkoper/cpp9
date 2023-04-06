#include "RPN.hpp"

RPN::RPN() {}

void print_stack(std::stack<double> s) {
	std::stack<double> temp;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		temp.push(s.top());
		s.pop();
	}
	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}
}

RPN::RPN( const std::string& expression) {
	std::stringstream ss(expression);
	std::string token;
	while (std::getline(ss, token, ' ')) {
		if (isdigit(token[0])) {
			if (operands.size() > 2) {
				std::cerr << "Error: too many operands" << std::endl;
				return;
			}
			operands.push(std::stod(token));
		}
		else {
			if (operands.size() < 2) {
				std::cerr << "Error: invalid input" << std::endl;
				return;
			}
			double operand1 = operands.top();
			operands.pop();
			double operand2 = operands.top();
			operands.pop();
			if (token.length() != 1) {
				std::cerr << "Error: invalid input" << std::endl;
				return;
			}
			if (token[0] == '+')
				operands.push(operand2 + operand1);
			else if (token[0] == '-')
				operands.push(operand2 - operand1);
			else if (token[0] == '*')
				operands.push(operand2 * operand1);
			else if (token[0] == '/')
				operands.push(operand2 / operand1);
		}
	}
	std::cout << operands.top() << std::endl;
}
 
RPN::RPN( const RPN& other) {
	*this = other;
}
 
RPN::~RPN() {}

RPN&	RPN::operator=( const RPN& other ) {
	return *this;
}
