#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe(argc, argv);
    return 0;
}