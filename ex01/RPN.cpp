#include "RPN.hpp"

RPN::RPN() {}

int iterate_stack(std::stack<double> s) {
	int i = 0;
	while (!s.empty()) {
		s.pop();
		i++;
	}
	return i;
}

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
	int i = 0;
	while (std::getline(ss, token, ' ')) {
		if (isdigit(token[0])) {
			if (operands.size() >= 2) {
				std::cerr << "Error: too many operands" << std::endl;
				return;
			}
			operands.push(std::stod(token));
			i = 1;
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
			else {
				std::cerr << "Error: invalid input" << std::endl;
				return;
			}
			i = 0;
		}
	}
	if (i) {
		std::cerr << "Error: expression cant end with an integer" << std::endl;
		return;
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
