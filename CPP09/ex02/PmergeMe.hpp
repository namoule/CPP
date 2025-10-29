#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>	

struct				Pair
{
	unsigned int	loser;
	unsigned int	winner;
    bool        isLast;
};

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        
        ~PmergeMe();
        
        void run(int argc, char **argv);
    private:
        std::vector<Pair> _vPairs;
        std::deque<Pair> _dPairs;

        std::vector<unsigned int> _vector;
        std::deque<unsigned int> _deque;

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        bool isPositiveInteger(const std::string& str);
        void parseInput(int argc, char** argv);

       double runDeque();
       double runVector();

        void    sort_deq(std::deque<unsigned int> &sort);
        void    sort_vec(std::vector<unsigned int> &sort);

        std::vector<unsigned int>    Jacobsthal(unsigned int nbOfValues);

        void dMakePairs();
        void vMakePairs();

        unsigned int dfindPairs(unsigned int f);
        unsigned int vfindPairs(unsigned int f);


        bool isSortedD(const std::deque<unsigned int> &sort) const;
        bool isSortedV(const std::vector<unsigned int> &sort) const;

        void isSorted(unsigned int n);

        void    PrintResult();
};


#endif
