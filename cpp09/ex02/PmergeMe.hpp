#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    public:
        class WrongInput : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Error: could not open file.";
                }
        };
        void parseInput(int argc, char** argv);
        void run();
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
    private:
        std::vector<int> _input;
        std::deque<int> _result;

        void fordJohnsonSort();
        void binaryInsert(int value);
        bool isPositiveInteger(const std::string& str);
        void printResult();


};


#endif
