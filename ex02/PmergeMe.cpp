#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
 
PmergeMe::PmergeMe( const PmergeMe& other) {
	*this = other;
}
 
PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=( const PmergeMe& other ) {
	return *this;
}

void PmergeMe::printDeq() {
    for (int i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::endl(std::cout);
}

void PmergeMe::printVec() {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::endl(std::cout);
}

void PmergeMe::fillContainers(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        try {
            if (std::stoi(argv[i]) < 0)
                throw std::invalid_argument("negative integer: " + std::string(argv[i]));
            vec.push_back(std::stoi(argv[i]));
            deq.push_back(std::stoi(argv[i]));     
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
}

void PmergeMe::mergeInsertionSortVec() {
    for (int i = 1; i < vec.size(); i++) {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j]) {
            std::swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}

void PmergeMe::mergeInsertionSortDeq() {
    for (int i = 1; i < deq.size(); i++) {
        int j = i;
        while (j > 0 && deq[j - 1] > deq[j]) {
            std::swap(deq[j], deq[j - 1]);
            j--;
        }
    }
}