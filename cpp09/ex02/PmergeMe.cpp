#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}


PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->_result = other._result;
    this->_input = other._input;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this->_result != other._result)
    {
        this->_result = other._result;
    }
    else if(this->_input != other._input)
    {
        this->_input = other._input;
    }
    return *this;
}

bool PmergeMe::isPositiveInteger(const std::string& str)
{
    if(str.empty())
        throw WrongInput();
    for(int i = 0; str[i]; i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        if(!isPositiveInteger(argv[i]))
            throw WrongInput();
        int value = std::atoi(argv[i]);
        _input.push_back(value);
    }
    if(_input.empty())
        throw WrongInput();
}
void PmergeMe::fordJohnsonSort()
{
    _result.clear();

    size_t n = _input.size();
    size_t i = 0;
    for (; i + 1 < n; i += 2)
    {
        int a = _input[i];
        int b = _input[i + 1];

        if (a < b)
            _result.push_back(b);  // gagnant
        else
            _result.push_back(a);
    }
    if (i < n)
        _result.push_back(_input[i]);
    std::sort(_result.begin(), _result.end());
    for (i = 0; i + 1 < n; i += 2)
    {
        int a = _input[i];
        int b = _input[i + 1];
        int loser = (a < b) ? a : b;
        binaryInsert(loser);
    }
}

void PmergeMe::binaryInsert(int value)
{
    std::deque<int>::iterator it = std::lower_bound(_result.begin(), _result.end(), value);
    _result.insert(it, value);
}

void PmergeMe::printResult()
{
    std::cout << "Après  : ";
    for (std::deque<int>::const_iterator it = _result.begin(); it != _result.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::run()
{
    std::cout << "Avant  : ";
    for (size_t i = 0; i < _input.size(); ++i)
    {
        std::cout << _input[i] << " ";
    }
    std::cout << std::endl;
    fordJohnsonSort();
    printResult();
}