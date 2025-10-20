#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <vector>

struct				Pair
{
	unsigned int	loser;
	unsigned int	winner;
};

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
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}

bool PmergeMe::isPositiveInteger(const std::string &str)
{
	if (str.empty())
		throw std::invalid_argument("Error: empty argument.");
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void PmergeMe::parseInput(int argc, char **argv)
{
	int	value;

	for (int i = 1; i < argc; i++)
	{
		if (!isPositiveInteger(argv[i]))
			throw std::invalid_argument("Error: invalid argument.");
		value = std::atoi(argv[i]);
		_vector.push_back(value);
		_deque.push_back(value);
	}
	if (_vector.empty())
		throw std::invalid_argument("Error: empty input.");
}

std::vector<unsigned int> PmergeMe::Jacobsthal(unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	next;

	std::vector<unsigned int> index;
	std::vector<bool> seen(size, false);
	i = 0;
	j = 1;
	while (j < size)
	{
		if (!seen[j])
		{
			index.push_back(j);
			seen[j] = true;
		}
		next = j + 2 * i;
		i = j;
		j = next;
	}
	for (unsigned int k = 0; k < size; ++k)
	{
		if (!seen[k])
			index.push_back(k);
	}
	return (index);
}

void PmergeMe::sort_vec(std::vector<unsigned int> &sort)
{
	int				tmp;
	unsigned int	a;
	unsigned int	b;
	unsigned int	idx;
	unsigned int	loser;
	unsigned int	winner;

	if (sort.size() <= 1)
		return ;
	tmp = -1;
	if (sort.size() % 2)
	{
		tmp = sort.back();
		sort.pop_back();
	}
	std::vector<Pair> pairs;
	for (size_t i = 0; i < sort.size(); i += 2)
	{
		a = sort[i];
		b = sort[i + 1];
		pairs.push_back((Pair){ std::min(a, b), std::max(a, b) });
	}
	std::vector<unsigned int> main;
	for (size_t i = 0; i < pairs.size(); ++i)
		main.push_back(pairs[i].winner);
	sort_vec(main);
	std::vector<Pair> toInsert = pairs;
	if (tmp >= 0)
    {
		Pair tmpPair;
        tmpPair.loser = static_cast<unsigned int>(tmp);
        tmpPair.winner = static_cast<unsigned int>(-1);
        toInsert.push_back(tmpPair);
    }

	std::vector<unsigned int> jacobIndices = Jacobsthal(toInsert.size());
	for (size_t i = 0; i < jacobIndices.size(); ++i)
	{
		idx = jacobIndices[i];
		if (idx >= toInsert.size())
			continue ;
		loser = toInsert[idx].loser;
		winner = toInsert[idx].winner;
		std::vector<unsigned int>::iterator rangeEnd;
		if (winner == (unsigned int)-1)
		{
			rangeEnd = main.end();
		}
		else
		{
			rangeEnd = std::find(main.begin(), main.end(), winner);
			if (rangeEnd == main.end())
				rangeEnd = main.end();
		}
		std::vector<unsigned int>::iterator insertPos = std::lower_bound(main.begin(),
				rangeEnd, loser);
		main.insert(insertPos, loser);
	}
	sort = main;
}

void PmergeMe::sort_deq(std::deque<unsigned int> &sort)
{
	int				tmp;
	unsigned int	a;
	unsigned int	b;
	unsigned int	idx;
	unsigned int	loser;
	unsigned int	winner;

	if (sort.size() <= 1)
		return ;
	tmp = -1;
	if (sort.size() % 2)
	{
		tmp = sort.back();
		sort.pop_back();
	}
	std::vector<Pair> pairs;
	for (size_t i = 0; i < sort.size(); i += 2)
	{
		a = sort[i];
		b = sort[i + 1];
		Pair p;
        p.loser = std::min(a, b);
        p.winner = std::max(a, b);
        pairs.push_back(p);
	}
	std::deque<unsigned int> main;
	for (size_t i = 0; i < pairs.size(); ++i)
		main.push_back(pairs[i].winner);
	sort_deq(main);
	std::vector<Pair> toInsert = pairs;
	if (tmp >= 0)
    {
        Pair tmpPair;
        tmpPair.loser = static_cast<unsigned int>(tmp);
        tmpPair.winner = static_cast<unsigned int>(-1);
        toInsert.push_back(tmpPair);
    }

	std::vector<unsigned int> jacobIndices = Jacobsthal(toInsert.size());
	for (size_t i = 0; i < jacobIndices.size(); ++i)
	{
		idx = jacobIndices[i];
		if (idx >= toInsert.size())
			continue ;
		loser = toInsert[idx].loser;
		winner = toInsert[idx].winner;
		std::deque<unsigned int>::iterator rangeEnd;
		if (winner == (unsigned int)-1)
		{
			rangeEnd = main.end();
		}
		else
		{
			rangeEnd = std::find(main.begin(), main.end(), winner);
			if (rangeEnd == main.end())
				rangeEnd = main.end();
		}
		std::deque<unsigned int>::iterator insertPos = std::lower_bound(main.begin(),
				rangeEnd, loser);
		main.insert(insertPos, loser);
	}
	sort = main;
}

void	printVector(const std::vector<unsigned int> &vec)
{
	for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	printDeque(const std::deque<unsigned int> &deq)
{
	for (std::deque<unsigned int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != deq.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::runDeque()
{
	clock_t	start;
	clock_t	end;
	double	elapsed_ms;

	start = clock();
	sort_deq(_deque);
	end = clock();
	elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque<unsigned int> : " << elapsed_ms << " ms" << std::endl;
	std::cout << "After: ";
	printDeque(_deque);
}

void PmergeMe::runVector()
{
	clock_t	start;
	clock_t	end;
	double	elapsed_ms;

	start = clock();
	sort_vec(_vector);
	end = clock();
	elapsed_ms = double(end - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<unsigned int> : " << elapsed_ms << " ms" << std::endl;
	std::cout << "After: ";
	printVector(_vector);
}

std::deque<unsigned int> PmergeMe::getDeque()
{
    return this->_deque;
}
std::vector<unsigned int> PmergeMe::getVector()
{
    return this->_vector;
}

bool PmergeMe::isSortedV(const std::vector<unsigned int> &sort) const
{
    for (std::vector<unsigned int>::const_iterator it = sort.begin(); it + 1 != sort.end(); ++it)
    {
        if (*(it + 1) < *it)
            return false;
    }
    return true;
}

bool PmergeMe::isSortedD(const std::deque<unsigned int> &sort) const
{
    for (std::deque<unsigned int>::const_iterator it = sort.begin(); it + 1 != sort.end(); ++it)
    {
        if (*(it + 1) < *it)
            return false;
    }
    return true;
}


void PmergeMe::run(int argc, char **argv)
{
	parseInput(argc, argv);
	std::cout << "\nBefore: ";
	printVector(_vector);

	std::cout << "\n---------------------------------" << std::endl;
	runDeque();
    std::cout << "is sorted deque: " << std::boolalpha << isSortedD(this->getDeque()) << std::noboolalpha << std::endl;
	std::cout << "\n---------------------------------" << std::endl;
	runVector();
    std::cout << "is sorted vector: " << std::boolalpha << isSortedV(this->getVector())<< std::noboolalpha << std::endl;
}
