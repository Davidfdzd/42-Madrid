#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}

	std::vector<std::string> args;
	for (int i = 1; i < argc; ++i)
		args.push_back(argv[i]);

	try
	{
		PmergeMe pm;
		pm.run(args);
	}
	catch (const std::exception&)
	{
		std::cerr << "Error\n";
		return 1;
	}

	return 0;
}