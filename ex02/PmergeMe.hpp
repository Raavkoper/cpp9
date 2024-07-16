#ifndef _PMERGE_ME_HPP_
#define _PMERGE_ME_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <chrono>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;
    int size;

public:
    PmergeMe() {};
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe() {};
    PmergeMe(int argc, char **argv);

    void errorChecking(int argc, char **argv);

    void fillContainers(int argc, char **argv);
    
    void sortVector();
    void sortDeque();

    void mergeInsertionSortVec(int left, int right);
    void mergeVec(int left, int mid, int right);
    void insertionSortVec(int left, int right);

    void mergeInsertionSortDeq(int left, int right);
    void mergeDeq(int left, int mid, int right);
    void insertionSortDeq(int left, int right);

    void outputVector(std::vector<int> vec);
    void outputDeque(std::deque<int> deq);
};

#endif