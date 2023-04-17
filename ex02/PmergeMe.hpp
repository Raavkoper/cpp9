#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
 
class PmergeMe {
private: 
	std::vector<int> vec;
	std::deque<int> deq;

public: 
	PmergeMe(); 
	PmergeMe( const PmergeMe &other); 
	~PmergeMe(); 
	PmergeMe& operator=( const PmergeMe &other);

	void fillContainers(int argc, char **argv);
	void mergeInsertionSortVec();
	void mergeInsertionSortDeq();

	void printVec();
	void printDeq();
}; 
 
#endif
