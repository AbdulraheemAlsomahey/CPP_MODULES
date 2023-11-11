#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &object)
{
    *this = object;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {}
    return (*this);
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::merg_vector(std::vector<int>& vec, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftVec(n1);
    std::vector<int> rightVec(n2);

    for (int i = 0; i < n1; i++) {
        leftVec[i] = vec[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightVec[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void PmergeMe::merg_deque(std::deque<int>& deq, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> leftDeq(n1);
    std::deque<int> rightDeq(n2);

    for (int i = 0; i < n1; i++) {
        leftDeq[i] = deq[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightDeq[i] = deq[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftDeq[i] <= rightDeq[j]) {
            deq[k] = leftDeq[i];
            i++;
        } else {
            deq[k] = rightDeq[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        deq[k] = leftDeq[i];
        i++;
        k++;
    }

    while (j < n2) {
        deq[k] = rightDeq[j];
        j++;
        k++;
    }
}

void PmergeMe::merg_sort_vector(std::vector<int>& vec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
        
		merg_sort_vector(vec, l, m);
		merg_sort_vector(vec, m + 1, r);

		merg_vector(vec, l, m, r);
	}
}
void PmergeMe::merg_sort_deque(std::deque<int>& deq, int l, int r)
{
    if (l < r)
	{
		int m = l + (r - l) / 2;
        
		merg_sort_deque(deq, l, m);
		merg_sort_deque(deq, m + 1, r);

		merg_deque(deq, l, m, r);
	}
}