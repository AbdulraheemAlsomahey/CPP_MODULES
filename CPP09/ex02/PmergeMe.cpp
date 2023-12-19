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

void PmergeMe::merg_list(std::list<int>& left, std::list<int>& right, std::list<int>& result) 
{
     std::list<int>::iterator leftIter = left.begin();
    std::list<int>::iterator rightIter = right.begin();

    while (leftIter != left.end() && rightIter != right.end()) {
        if (*leftIter < *rightIter) {
            result.push_back(*leftIter);
            leftIter++;
        } else {
            result.push_back(*rightIter);
            rightIter++;
        }
    }

    result.insert(result.end(), leftIter, left.end());
    result.insert(result.end(), rightIter, right.end());
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
void PmergeMe::merg_sort_list(std::list<int>& lst) 
{
    if (lst.size() <= 1) {
        return;
    }

    std::list<int> left, right;
    int middle = lst.size() / 2;

    std::list<int>::iterator it = lst.begin();
    for (int i = 0; i < middle; i++) {
        left.push_back(*it);
        it++;
    }

    for (; it != lst.end(); it++) {
        right.push_back(*it);
    }

    merg_sort_list(left);
    merg_sort_list(right);
    lst.clear();
    merg_list(left, right, lst);
}