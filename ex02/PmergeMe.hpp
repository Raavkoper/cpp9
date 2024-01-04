#ifndef _PMERGE_ME_HPP_
#define _PMERGE_ME_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;
    int size;

public:
    PmergeMe() {}
    ~PmergeMe() {}
    PmergeMe(int argc, char **argv);

    void fillContainers(int argc, char **argv);
    void sortContainers();

    void outputVector(std::vector<int> vec);
    void outputDeque(std::deque<int> deq);
};

#endif
