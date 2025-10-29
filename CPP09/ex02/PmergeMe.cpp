#include "PmergeMe.hpp"
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe class created: please call run(int argc, char **argv) function to start" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::cout << "PmergeMe class created: start" << std::endl;
    run(argc, argv);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

bool PmergeMe::isPositiveInteger(const std::string &str)
{
    if (str.empty())
        throw std::invalid_argument("Error: wrong arguments.");
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::invalid_argument("Error: non-positive integer argument.");
        unsigned int value = std::atoi(argv[i]);
        _vector.push_back(value);
        _deque.push_back(value);
    }
    if (_deque.empty())
        throw std::invalid_argument("Error: no numbers provided.");
}

std::vector<unsigned int> PmergeMe::Jacobsthal(unsigned int n)
{
    std::vector<unsigned int> seq;
    if (n == 0)
        return seq;
    seq.push_back(0);
    if (n == 1)
        return seq;
    seq.push_back(1);

    unsigned int j1 = 0, j2 = 1;
    while (true)
    {
        unsigned int next = j2 + 2 * j1;
        if (next >= n)
            break;
        seq.push_back(next);
        j1 = j2;
        j2 = next;
    }

    for (unsigned int i = 1; i < n; ++i)
    {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }
    return seq;
}

void PmergeMe::vMakePairs()
{
    _vPairs.clear();
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        unsigned int a = _vector[i];
        unsigned int b = _vector[i + 1];
        _vPairs.push_back((Pair){std::min(a, b), std::max(a, b)});
    }
    if (_vector.size() % 2)
        _vPairs.push_back((Pair){_vector.back(), _vector.back()});
}

void PmergeMe::dMakePairs()
{
    _dPairs.clear();
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        unsigned int a = _deque[i];
        unsigned int b = _deque[i + 1];
        _dPairs.push_back((Pair){std::min(a, b), std::max(a, b)});
    }
    if (_deque.size() % 2)
        _dPairs.push_back((Pair){_deque.back(), _deque.back()});
}

void PmergeMe::sort_vec(std::vector<unsigned int> &arr)
{
    if (arr.size() <= 1)
        return;

    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
        pairs.push_back((Pair){std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])});
    if (arr.size() % 2)
        pairs.push_back((Pair){arr.back(), arr.back()});

    std::vector<unsigned int> winners, losers;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        winners.push_back(pairs[i].winner);
        if (pairs[i].loser != pairs[i].winner)
            losers.push_back(pairs[i].loser);
    }

    sort_vec(winners);

    std::vector<unsigned int> order = Jacobsthal(losers.size());
    std::vector<unsigned int> sorted = winners;

    for (size_t i = 0; i < order.size() && i < losers.size(); ++i)
    {
        unsigned int loser = losers[order[i]];
        unsigned int winner = pairs[order[i]].winner;
        std::vector<unsigned int>::iterator winnerIt = std::find(sorted.begin(), sorted.end(), winner);
        std::vector<unsigned int>::iterator insertPos = std::lower_bound(sorted.begin(), winnerIt, loser);
        sorted.insert(insertPos, loser);
    }
    arr = sorted;
}

void PmergeMe::sort_deq(std::deque<unsigned int> &arr)
{
    if (arr.size() <= 1)
        return;

    std::deque<Pair> pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
        pairs.push_back((Pair){std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])});
    if (arr.size() % 2)
        pairs.push_back((Pair){arr.back(), arr.back()});

    std::deque<unsigned int> winners, losers;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        winners.push_back(pairs[i].winner);
        if (pairs[i].loser != pairs[i].winner)
            losers.push_back(pairs[i].loser);
    }

    sort_deq(winners);

    std::vector<unsigned int> order = Jacobsthal(losers.size());
    std::deque<unsigned int> sorted = winners;

    for (size_t i = 0; i < order.size() && i < losers.size(); ++i)
    {
        unsigned int loser = losers[order[i]];
        unsigned int winner = pairs[order[i]].winner;
        std::deque<unsigned int>::iterator winnerIt = std::find(sorted.begin(), sorted.end(), winner);
        std::deque<unsigned int>::iterator insertPos = std::lower_bound(sorted.begin(), winnerIt, loser);
        sorted.insert(insertPos, loser);
    }
    arr = sorted;
}



bool PmergeMe::isSortedV(const std::vector<unsigned int> &sort) const
{
    for (size_t i = 1; i < sort.size(); ++i)
        if (sort[i] < sort[i - 1])
            return false;
    return true;
}

bool PmergeMe::isSortedD(const std::deque<unsigned int> &sort) const
{
    for (size_t i = 1; i < sort.size(); ++i)
        if (sort[i] < sort[i - 1])
            return false;
    return true;
}

void printVector(const std::vector<unsigned int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << " | ";
    }
    std::cout << std::endl;
}

void printDeque(const std::deque<unsigned int> &deq)
{
    for (size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i];
        if (i + 1 < deq.size()) std::cout << " | ";
    }
    std::cout << std::endl;
}

double PmergeMe::runDeque()
{
    clock_t start = clock();
    sort_deq(_deque);
    clock_t end = clock();
    double elapsed = double(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "\033[32mTime to process " << _deque.size() 
              << " elements with std::deque : " << elapsed << " ms\033[0m" << std::endl;
    printDeque(_deque);
    return elapsed;
}

double PmergeMe::runVector()
{
    clock_t start = clock();
    sort_vec(_vector);
    clock_t end = clock();
    double elapsed = double(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "\033[32mTime to process " << _vector.size() 
              << " elements with std::vector : " << elapsed << " ms\033[0m" << std::endl;
    printVector(_vector);
    return elapsed;
}

void PmergeMe::isSorted()
{
    std::cout << (isSortedV(_vector) ? "\033[32mVector sorted\033[0m\n" : "\033[31mVector not sorted\033[0m\n");
    std::cout << (isSortedD(_deque) ? "\033[32mDeque sorted\033[0m\n" : "\033[31mDeque not sorted\033[0m\n");
}

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);
    for (int i = 1; i < argc; ++i)
        std::cout << "\033[31m" << argv[i] << "\033[0m" << " | ";
    std::cout << "\n---------------------------------\n";

    double dq = runDeque();
    std::cout << "\n---------------------------------\n";
    double vct = runVector();

    std::cout << "\n---------------------------------\n";
    isSorted();
    std::cout << "Compare times:\nDeque : \033[32m" << dq << " ms\033[0m\nVector : \033[32m" << vct << " ms\033[0m" << std::endl;
}
