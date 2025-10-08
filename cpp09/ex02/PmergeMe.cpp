#include "PmergeMe.hpp"
#include <exception>

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe class created: please call run(int argc, char **argv) function to start" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::cout << "PmergeMe class created: start" << std::endl;
    run(argc, argv);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_vector = other._vector;
    this->_deque = other._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this->_vector != other._vector)
    {
        this->_vector = other._vector;
    }
    else if (this->_deque != other._deque)
    {
        this->_deque = other._deque;
    }
    return *this;
}

bool PmergeMe::isPositiveInteger(const std::string &str)
{
    if (str.empty())
        std::invalid_argument("Error: wrong arguments.");
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::invalid_argument("argument list not ok");
        int value = std::atoi(argv[i]);
        _vector.push_back(value);
        _deque.push_back(value);
    }
    if (_deque.empty())
        throw std::invalid_argument("argument empty");
}

void PmergeMe::PrintTime()
{
}
std::vector<unsigned int> PmergeMe::Jacobsthal(unsigned int size)
{
    std::vector<unsigned int> index;
    std::vector<bool> seen(size, false);
    unsigned int i = 0;
    unsigned int j = 1;
    while (j < size)
    {
        if (!seen[j])
        {
            index.push_back(j);
            seen[j] = true;
        }
        unsigned int next = j + 2 * i;
        i = j;
        j = next;
    }
    for (unsigned int k = 0; k < size; ++k)
    {
        if (!seen[k])
            index.push_back(k);
    }
    return index;
}

void PmergeMe::sort_vec(std::vector<unsigned int> &sort)
{
    if (sort.size() <= 1)
        return;
    int tmp = -1;
    int size = sort.size();

    if (sort.size() % 2)
    {
        tmp = sort.back();
        sort.pop_back();
    }

    std::vector<unsigned int> main, loser;
    std::vector<unsigned int>::iterator it;
    for (it = sort.begin(); it != sort.end(); it += 2)
    {
        main.push_back(std::max(*it, *(it + 1)));
        loser.push_back(std::min(*it, *(it + 1)));
        size--;
    }

    sort_vec(main);

    if (tmp >= 0)
        loser.push_back(tmp);

    std::vector<unsigned int> jacobshtalresults = Jacobsthal(size);
    for (int i = 0; i < size; ++i)
    {
        int toInsert = jacobshtalresults[i];
        std::vector<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), loser[toInsert]);
        main.insert(pos, loser[toInsert]);
    }

    sort = main;
}
void PmergeMe::sort_deq(std::deque<unsigned int> &sort)
{
    if (sort.size() <= 1)
        return;
    int tmp = -1;
    int size = sort.size();

    if (sort.size() % 2)
    {
        tmp = sort.back();
        sort.pop_back();
    }

    std::deque<unsigned int> main, loser;
    std::deque<unsigned int>::iterator it;
    for (it = sort.begin(); it != sort.end(); it += 2)
    {
        main.push_back(std::max(*it, *(it + 1)));
        loser.push_back(std::min(*it, *(it + 1)));
        size--;
    }

    sort_deq(main);

    if (tmp >= 0)
        loser.push_back(tmp);

    std::vector<unsigned int> jacobshtalresults = Jacobsthal(size);
    for (int i = 0; i < size; ++i)
    {
        int toInsert = jacobshtalresults[i];
        std::deque<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), loser[toInsert]);
        main.insert(pos, loser[toInsert]);
    }

    sort = main;
}

void printVector(const std::vector<unsigned int> &vec)
{
    for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
    }
}

void printDeque(const std::deque<unsigned int> &deq)
{
    for (std::deque<unsigned int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
    {
        std::cout << *it;
        if (it + 1 != deq.end())
            std::cout << " ";
    }
}

void PmergeMe::runDeque()
{
    clock_t start = clock();
    sort_deq(_deque);
    clock_t end = clock();
    double elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque<unsigned int> : " << elapsed_ms << " ms" << std::endl;
    printDeque(_deque);
}

void PmergeMe::runVector()
{
    clock_t start = clock();
    sort_vec(_vector);
    clock_t end = clock();
    double elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<unsigned int> : " << elapsed_ms << " ms" << std::endl;
    printVector(_vector);
}

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);
    std::cout << "\n---------------------------------" << std::endl;
    runDeque();
    std::cout << "\n---------------------------------" << std::endl;
    runVector();
    std::cout << "\n---------------------------------" << std::endl;

}
