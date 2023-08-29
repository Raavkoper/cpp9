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
    std::vector<int> s, l;
    int len = vec.size();
    for (int i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            if (vec[i] < vec[i + 1]) {
                s.push_back(vec[i]);
                l.push_back(vec[i + 1]);
            } else {
                s.push_back(vec[i + 1]);
                l.push_back(vec[i]);
            }
        } else {
            s.push_back(vec[i]);
        }
    }
    // int max = *max_element(vec.begin(), vec.end());
    // int min = *min_element(vec.begin(), vec.end());
    // for (int i = 0; i < s.size(); i++) {
    //     std::cout << s[i] << " ";
    // }
    // std::endl(std::cout);

    vec.clear();

    std::vector<int>::iterator l_it = l.begin();
    std::vector<int>::iterator s_it = s.begin();

    while (l_it != l.end() && s_it != s.end()) {
        if (*s_it < *l_it) {
            vec.push_back(*s_it);
            ++s_it;
        } else {
            vec.push_back(*l_it);
            ++l_it;
        }
    }

    while (l_it != l.end()) {
        vec.push_back(*l_it);
        ++l_it;
    }

    while (s_it != s.end()) {
        vec.push_back(*s_it);
        ++s_it;
    }

    // vec.reserve(len + 1);
    // for (int i = 0; i < len; i++) {
    //     int smin = *min_element(s.begin(), s.end());
    //     int lmin = *min_element(l.begin(), l.end());
    //     if (smin <= lmin) {
    //         vec.push_back(smin);
    //         s.erase(std::find(s.begin(), s.end(), smin));
    //     }
    //     else {
    //         vec.push_back(lmin);
    //         l.erase(std::find(l.begin(), l.end(), lmin));
    //     }
    //     std::cout << "hoi" << std::endl;
    // }
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