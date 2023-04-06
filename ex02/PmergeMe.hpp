#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <algorithm>
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
