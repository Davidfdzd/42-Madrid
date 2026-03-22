#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <climits>
#include <iomanip>

class PmergeMe
{
	private:
		std::deque<int>		_deq;
		std::vector<int>	_vec;
		
		bool isValidNumber(const std::string& str);
		void fillContainers(std::vector<std::string>& args);
		void mergeInsertionSortV(std::vector<int>& container);
		void mergeInsertionSortD(std::deque<int>& container);

		template <typename T>
		void printContainer(const std::string label, const T& container);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(std::vector<std::string>& args);
};

#endif