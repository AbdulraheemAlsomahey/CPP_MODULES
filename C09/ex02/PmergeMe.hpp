#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>


class PmergeMe
{
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &object);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();
    void merg_vector(std::vector<int>& vec, int left, int mid, int right);
    void merg_deque(std::deque<int>& deq, int left, int mid, int right);
    void merg_sort_vector(std::vector<int>& arr, int l, int r);
    void merg_sort_deque(std::deque<int>& arr, int l, int r);
};

#endif