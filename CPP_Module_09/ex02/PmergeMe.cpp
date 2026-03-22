#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _deq(other._deq), _vec(other._vec) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ========================= */
/*        PARSING            */
/* ========================= */

bool PmergeMe::isValidNumber(const std::string& str)
{
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

void PmergeMe::fillContainers(std::vector<std::string>& args)
{
	_vec.clear();
	_deq.clear();

	for (size_t i = 0; i < args.size(); ++i)
	{
		if (!isValidNumber(args[i]))
			throw std::runtime_error("Error");

		long value = std::strtol(args[i].c_str(), NULL, 10);
		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
}

/* ========================= */
/*     JACOBSTHAL SEQUENCE   */
/* ========================= */

static std::vector<size_t> generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	while (jacob.back() < n)
		jacob.push_back(jacob[jacob.size() - 1]
			+ 2 * jacob[jacob.size() - 2]);

	std::vector<bool> used(n, false);

	for (size_t k = 1; k < jacob.size(); ++k)
	{
		size_t start = std::min(jacob[k], n);
		size_t end = std::min((k + 1 < jacob.size()) ? jacob[k + 1] : n, n);

		for (size_t i = start; i > jacob[k - 1]; --i)
		{
			if (i <= end && !used[i - 1])
			{
				order.push_back(i - 1);
				used[i - 1] = true;
			}
		}
	}
	return order;
}

/* ========================= */
/*   MERGE-INSERTION SORT    */
/* ========================= */

void PmergeMe::mergeInsertionSortV(std::vector<int>& container)
{
	if (container.size() <= 1)
		return;

	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];
		if (a > b)
			std::swap(a, b);
		mainChain.push_back(b);
		pending.push_back(a);
	}

	if (container.size() % 2)
		pending.push_back(container.back());

	mergeInsertionSortV(mainChain);

	std::vector<size_t> order = generateJacobsthalSequence(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int value = pending[order[i]];
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(pos, value);
	}

	container.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::mergeInsertionSortD(std::deque<int>& container)
{
	if (container.size() <= 1)
		return;

	std::deque<int> mainChain;
	std::deque<int> pending;

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];
		if (a > b)
			std::swap(a, b);
		mainChain.push_back(b);
		pending.push_back(a);
	}

	if (container.size() % 2)
		pending.push_back(container.back());

	mergeInsertionSortD(mainChain);

	std::vector<size_t> order = generateJacobsthalSequence(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int value = pending[order[i]];
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(pos, value);
	}

	container.assign(mainChain.begin(), mainChain.end());
}

/* ========================= */
/*         DISPLAY           */
/* ========================= */

template <typename T>
void PmergeMe::printContainer(const std::string label, const T& container)
{
	std::cout << label;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

/* ========================= */
/*            RUN            */
/* ========================= */

void PmergeMe::run(std::vector<std::string>& args)
{
	fillContainers(args);

	printContainer("Before:", _vec);

	clock_t startVec = clock();
	mergeInsertionSortV(_vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	mergeInsertionSortD(_deq);
	clock_t endDeq = clock();

	printContainer("After:", _vec);

	double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << vecTime << " s" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << deqTime << " s" << std::endl;
}