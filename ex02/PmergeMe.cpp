#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
 
PmergeMe::PmergeMe( const PmergeMe& other) {
	*this = other;
}
 
PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=( const PmergeMe& other ) {
	return *this;
}
