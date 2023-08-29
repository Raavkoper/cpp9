#include "PmergeMe.hpp"

int main(int argc, char	**argv) {
    if (argc < 2) {
		std::cout << "Usage: ./main <sequence of positive integers>" << std::endl;
		return 0;
	}
	PmergeMe p;

	p.fillContainers(argc, argv);

	// std::cout << "Unsorted sequence:" << std::endl;
	// p.printVec();

	std::clock_t startVec = std::clock();
    p.mergeInsertionSortVec();
	std::clock_t endVec = std::clock();
    
	std::clock_t startDeq = std::clock();
    p.mergeInsertionSortDeq();
	std::clock_t endDeq = std::clock();
    
    // std::cout << "Sorted sequence:" << std::endl;
	p.printVec();

	// std::cout << "Time taken by vector: " << (endVec - startVec) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	// std::cout << "Time taken by deque: " << (endDeq - startDeq) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        
    return 0;
}