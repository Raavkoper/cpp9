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
    int min;

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

    void determinePairsVec();
    void sortLargestVec(std::vector<int> &sorted);
    void insertSmallestVec(std::vector<int> &sorted);
    void addSmallestVec(std::vector<int> &sorted);
    void insertBinarySearchVec(std::vector<int> &sorted, int i);

    void determinePairsDeq();
    void sortLargestDeq(std::deque<int> &sorted);
    void insertSmallestDeq(std::deque<int> &sorted);
    void addSmallestDeq(std::deque<int> &sorted);
    void insertBinarySearchDeq(std::deque<int> &sorted, int i);

    void outputVector(std::vector<int> vec);
    void outputDeque(std::deque<int> deq);
};

#endif
