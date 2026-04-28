#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseInput(int argc, char **argv);
	void sort();
	void display() const;

private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	std::vector<int> _unsorted;
	double _vecTime;
	double _deqTime;

	void fordJohnsonSort(std::vector<int> &arr);
	void fordJohnsonSort(std::deque<int> &arr);

	std::vector<size_t> generateJacobsthalSequence(size_t n);

	void binaryInsert(std::vector<int> &sorted, int value);
	void binaryInsert(std::deque<int> &sorted, int value);
};

#endif
