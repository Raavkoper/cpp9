#include "PmergeMe.hpp"

// OUTPUT

void PmergeMe::outputVector(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::outputDeque(std::deque<int> deq)
{
    for (int i = 0; i < deq.size(); i++)
    {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

void checkIfSorted(std::vector<int> vec, std::deque<int> deq)
{
    if (is_sorted(vec.begin(), vec.end()) && is_sorted(deq.begin(), deq.end()))
    {
        std::cout << "Both containers are sorted correctly." << std::endl;
    }
    else if (!is_sorted(vec.begin(), vec.end()) && !is_sorted(deq.begin(), deq.end()))
    {
        std::cout << "Both containers are not sorted." << std::endl;
    }
    else if (!is_sorted(vec.begin(), vec.end()))
    {
        std::cout << "Deque is sorted correctly, Vector is not sorted." << std::endl;
    }
    else if (!is_sorted(deq.begin(), deq.end()))
    {
        std::cout << "Vector is sorted correctly, Deque is not sorted." << std::endl;
    }
}

// CONSTRUCTORS

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
        size = other.size;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char **argv) : size(argc - 1)
{
    errorChecking(argc, argv);
    fillContainers(argc, argv);
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
    checkIfSorted(vec, deq);
}

// FILLING

void PmergeMe::errorChecking(int argc, char **argv)
{
    int i = 0;
    int j;
    while (i < argc - 1)
    {
        j = 0;
        if (atoi(argv[i + 1]) < 0)
        {
            std::cout << "Negative number detected: " << argv[i + 1] << std::endl;
            exit(1);
        }
        while (j < argc - 1)
        {
            if (i != j && atoi(argv[i + 1]) == atoi(argv[j + 1]))
            {
                std::cout << "Duplicate detected: " << argv[i + 1] << std::endl;
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void PmergeMe::fillContainers(int argc, char **argv)
{
    int i = 1;
    while (argv[i] != NULL)
    {
        vec.push_back(atoi(argv[i]));
        deq.push_back(atoi(argv[i]));
        i++;
    }
    std::cout << "Before: " << std::endl;
    outputVector(vec);
}

// SORTING

void PmergeMe::sortVector()
{
    mergeInsertionSortVec(0, size - 1);
    std::cout << "Vector After: " << std::endl;
    outputVector(vec);
}

void PmergeMe::sortDeque()
{
    mergeInsertionSortDeq(0, size - 1);
    std::cout << "Deque After: " << std::endl;
    outputDeque(deq);
}

// VECTOR

void PmergeMe::insertionSortVec(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

// Merge function to merge two sorted subvecs
void PmergeMe::mergeVec(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vecs
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary vecs L and R
    for (int i = 0; i < n1; ++i)
    {
        L[i] = vec[left + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        R[i] = vec[mid + 1 + i];
    }

    // Merge the temporary vecs back into vec[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            ++i;
        }
        else
        {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L, if any
    while (i < n1)
    {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R, if any
    while (j < n2)
    {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to perform merge insertion sort on the vecay
void PmergeMe::mergeInsertionSortVec(int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 <= 10)
        {
            // Use insertion sort for small subvecs
            insertionSortVec(left, right);
        }
        else
        {
            // Use merge sort for larger subvecs
            int mid = left + (right - left) / 2;
            mergeInsertionSortVec(left, mid);
            mergeInsertionSortVec(mid + 1, right);
            mergeVec(left, mid, right);
        }
    }
}

// DEQUE

void PmergeMe::insertionSortDeq(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = deq[i];
        int j = i - 1;
        while (j >= left && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

// Merge function to merge two sorted subDeqs
void PmergeMe::mergeDeq(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary Deqs
    std::deque<int> L(n1), R(n2);

    // Copy data to temporary Deqs L and R
    for (int i = 0; i < n1; ++i)
    {
        L[i] = deq[left + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        R[i] = deq[mid + 1 + i];
    }

    // Merge the temporary Deqs back into Deq[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            deq[k] = L[i];
            ++i;
        }
        else
        {
            deq[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L, if any
    while (i < n1)
    {
        deq[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R, if any
    while (j < n2)
    {
        deq[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to perform merge insertion sort on the Deqay
void PmergeMe::mergeInsertionSortDeq(int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 <= 10)
        {
            // Use insertion sort for small subDeqs
            insertionSortDeq(left, right);
        }
        else
        {
            // Use merge sort for larger subDeqs
            int mid = left + (right - left) / 2;
            mergeInsertionSortDeq(left, mid);
            mergeInsertionSortDeq(mid + 1, right);
            mergeDeq(left, mid, right);
        }
    }
}
