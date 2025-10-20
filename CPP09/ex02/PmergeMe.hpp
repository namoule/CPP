#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstdlib>
# include <deque>
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

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

	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	bool isPositiveInteger(const std::string &str);
	void parseInput(int argc, char **argv);

	void runDeque();
	void runVector();

	std::deque<unsigned int> getDeque();
	std::vector<unsigned int> getVector();

    bool isSortedD(const std::deque<unsigned int> &sort) const ;
    bool isSortedV(const std::vector<unsigned int> &sort) const ;

    void sort_deq(std::deque<unsigned int> &sort);
    void sort_vec(std::vector<unsigned int> &sort);

	std::vector<unsigned int> Jacobsthal(unsigned int nbOfValues);

	void PrintTime();
	void PrintResult();
};

#endif
