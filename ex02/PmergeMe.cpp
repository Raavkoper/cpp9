#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv): size(argc - 1) {
    fillContainers(argc, argv);
    sortContainers();
}

// FILLING

void PmergeMe::fillContainers(int argc, char **argv) {
    int i = 1;
    while (argv[i] != NULL) {
        vec.push_back(atoi(argv[i]));
        deq.push_back(atoi(argv[i]));
        i++;
    }
    std::cout << "Before: " << std::endl;
    outputVector(vec);
}

// SORTING

void PmergeMe::sortContainers() {
    std::sort(vec.begin(), vec.end());
    std::sort(deq.begin(), deq.end());
}

// OUTPUT

void PmergeMe::outputVector(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::outputDeque(std::deque<int> deq) {
    std::cout << "Deque: ";
    for (int i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}