#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>
#include <sstream>
 
class RPN {
private: 
	std::stack<double> operands;

public: 
	RPN();
	RPN( const std::string &expression);
	RPN( const RPN &other); 
	~RPN(); 
	RPN& operator=( const RPN &other); 
}; 
 
#endif
