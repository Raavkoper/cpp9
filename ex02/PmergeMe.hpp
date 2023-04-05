#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
 
class PmergeMe {
private: 
 
public: 
	PmergeMe(); 
	PmergeMe( const PmergeMe &other); 
	~PmergeMe(); 
	PmergeMe& operator=( const PmergeMe &other); 
}; 
 
#endif
