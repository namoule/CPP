#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>	

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        
        ~PmergeMe();
        
        void run(int argc, char **argv);
    private:
        std::vector<unsigned int> _vector;
        std::deque<unsigned int> _deque;

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        bool isPositiveInteger(const std::string& str);
        void parseInput(int argc, char** argv);

       void runDeque();
       void runVector();


        void    sort_deq(std::deque<unsigned int> &sort);
        void    sort_vec(std::vector<unsigned int> &sort);

        std::vector<unsigned int>    Jacobsthal(unsigned int nbOfValues);

        void    PrintTime();
        void    PrintResult();
};


#endif
