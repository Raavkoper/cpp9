#include "PmergeMe.hpp"

// OUTPUT

void PmergeMe::outputVector(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::outputDeque(std::deque<int> deq) {
    for (int i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

// CONSTRUCTORS

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
        size = other.size;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char **argv): size(argc - 1) {
    errorChecking(argc, argv);
    fillContainers(argc, argv);
    min = std::min_element(vec.begin(), vec.end())[0];
    auto startVec = std::chrono::high_resolution_clock::now();
    sortVector();
    auto endVec = std::chrono::high_resolution_clock::now();
    std::cout << "Vector time in miliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(endVec - startVec).count() << std::endl;
    std::cout << "Vector time in microsenconds: " << std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec).count() << std::endl;
    auto startDeq = std::chrono::high_resolution_clock::now();
    sortDeque();
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::cout << "Deque time in miliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(endDeq - startDeq).count() << std::endl;
    std::cout << "Deque time in microsenconds: " << std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq).count() << std::endl;
}

// FILLING

void PmergeMe::errorChecking(int argc, char **argv) {
    int i = 0;
    int j;
    while (i < argc - 1) {
        j = 0;
        if (atoi(argv[i + 1]) < 0) {
            std::cout << "Negative number detected: " << argv[i + 1] << std::endl;
            exit(1);
        }
        while (j < argc - 1) {
            if (i != j && atoi(argv[i + 1]) == atoi(argv[j + 1])) {
                std::cout << "Duplicate detected: " << argv[i + 1] << std::endl;
                exit(1);
            }
            j++;
        }
        i++;
    }
}

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

void PmergeMe::sortVector() {
    std::vector<int> sorted;
    determinePairsVec();
    sortLargestVec(sorted);
    insertSmallestVec(sorted);
    addSmallestVec(sorted);
    vec = sorted;
    std::cout << "Vector After: " << std::endl;
    outputVector(vec);
}

void PmergeMe::sortDeque() {
    std::deque<int> sorted;
    determinePairsDeq();
    sortLargestDeq(sorted);
    insertSmallestDeq(sorted);
    addSmallestDeq(sorted);
    deq.clear();
    for (int i = 0; i < sorted.size(); i++) {
        deq.push_back(sorted[i]);
    }
    std::cout << "Deque After: " << std::endl;
    outputDeque(deq);
}

// VECTOR

void PmergeMe::determinePairsVec() {
    for (int i = 0; i < size; i += 2) {
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
    }
}

void PmergeMe::sortLargestVec(std::vector<int> &sorted) {
    for (int i = 1; i < size; i += 2) {
        insertBinarySearchVec(sorted, vec[i]);
    }
}

void PmergeMe::insertSmallestVec(std::vector<int> &sorted) {
    sorted.insert(sorted.begin(), min);
}

void PmergeMe::addSmallestVec(std::vector<int> &sorted) {
    for (int i = 0; i < size; i += 2) {
        if (vec[i] != min)
            insertBinarySearchVec(sorted, vec[i]);
    }
}

void PmergeMe::insertBinarySearchVec(std::vector<int> &sorted, int i) {
    int low = 0;
    int high = sorted.size() - 1;
    int mid = 0;
    int temp = i;
    while (low <= high) {
        mid = (low + high) / 2;
        if (temp > sorted[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    sorted.insert(sorted.begin() + low, temp);
}

// DEQUE

void PmergeMe::determinePairsDeq() {
    for (int i = 0; i < size; i += 2) {
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
    }
}

void PmergeMe::sortLargestDeq(std::deque<int> &sorted) {
    for (int i = 1; i < size; i += 2) {
        insertBinarySearchDeq(sorted, deq[i]);
    }
}

void PmergeMe::insertSmallestDeq(std::deque<int> &sorted) {
    sorted.insert(sorted.begin(), min);
}

void PmergeMe::addSmallestDeq(std::deque<int> &sorted) {
    for (int i = 0; i < size; i += 2) {
        if (deq[i] != min)
            insertBinarySearchDeq(sorted, deq[i]);
    }
}

void PmergeMe::insertBinarySearchDeq(std::deque<int> &sorted, int i) {
    int low = 0;
    int high = sorted.size() - 1;
    int mid = 0;
    int temp = i;
    while (low <= high) {
        mid = (low + high) / 2;
        if (temp > sorted[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    sorted.insert(sorted.begin() + low, temp);
}
