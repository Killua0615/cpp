#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <cstdlib>

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vec(other._vec), _deq(other._deq), _unsorted(other._unsorted),
	  _vecTime(other._vecTime), _deqTime(other._deqTime) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
		_unsorted = other._unsorted;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < arg.length(); j++) {
			if (arg[j] < '0' || arg[j] > '9')
				throw std::runtime_error("Error");
		}
		long num = std::strtol(arg.c_str(), NULL, 10);
		if (num <= 0 || num > 2147483647)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
	_unsorted = _vec;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
	std::vector<size_t> jacob;
	if (n == 0)
		return jacob;
	jacob.push_back(0);
	if (n == 1)
		return jacob;
	jacob.push_back(1);
	while (true) {
		size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= n)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

void PmergeMe::binaryInsert(std::vector<int> &sorted, int value, std::vector<int>::iterator bound) {
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), bound, value);
	sorted.insert(pos, value);
}

void PmergeMe::binaryInsert(std::deque<int> &sorted, int value, std::deque<int>::iterator bound) {
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), bound, value);
	sorted.insert(pos, value);
}

void PmergeMe::fordJohnsonSort(std::vector<int> &arr) {
	if (arr.size() <= 1)
		return;

	// Step 1: Create pairs and sort each pair (larger element first)
	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	if (arr.size() % 2 != 0) {
		hasStraggler = true;
		straggler = arr.back();
	}

	// Step 2: Recursively sort the larger elements
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	fordJohnsonSort(largers);

	// Reorder pairs based on sorted largers
	std::vector<int> smallers;
	for (size_t i = 0; i < largers.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == largers[i]) {
				smallers.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	// Step 3: Build the sorted sequence
	// Start with the sorted larger elements as the main chain
	std::vector<int> result(largers);

	// Insert the first smaller element at the beginning (it's always smaller than its pair)
	if (!smallers.empty())
		result.insert(result.begin(), smallers[0]);

	// Step 4: Use Jacobsthal sequence to determine insertion order for remaining smallers
	std::vector<size_t> jacob = generateJacobsthalSequence(smallers.size());

	std::vector<bool> inserted(smallers.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacob.size(); i++) {
		size_t idx = jacob[i];
		if (idx < smallers.size() && !inserted[idx]) {
			std::vector<int>::iterator bound = std::lower_bound(
				result.begin(), result.end(), largers[idx]);
			binaryInsert(result, smallers[idx], bound);
			inserted[idx] = true;
		}
		for (size_t j = jacob[i] - 1; j > jacob[i - 1]; j--) {
			if (j < smallers.size() && !inserted[j]) {
				std::vector<int>::iterator bound = std::lower_bound(
					result.begin(), result.end(), largers[j]);
				binaryInsert(result, smallers[j], bound);
				inserted[j] = true;
			}
		}
	}

	size_t lastJacob = jacob.empty() ? 0 : jacob.back();
	for (size_t i = smallers.size(); i > lastJacob; i--) {
		if (i - 1 < smallers.size() && !inserted[i - 1]) {
			size_t idx = i - 1;
			std::vector<int>::iterator bound = std::lower_bound(
				result.begin(), result.end(), largers[idx]);
			binaryInsert(result, smallers[idx], bound);
			inserted[idx] = true;
		}
	}

	if (hasStraggler)
		binaryInsert(result, straggler, result.end());

	arr = result;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &arr) {
	if (arr.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	if (arr.size() % 2 != 0) {
		hasStraggler = true;
		straggler = arr.back();
	}

	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	fordJohnsonSort(largers);

	std::deque<int> smallers;
	for (size_t i = 0; i < largers.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == largers[i]) {
				smallers.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	std::deque<int> result(largers.begin(), largers.end());

	if (!smallers.empty())
		result.insert(result.begin(), smallers[0]);

	std::vector<size_t> jacob = generateJacobsthalSequence(smallers.size());

	std::vector<bool> inserted(smallers.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacob.size(); i++) {
		size_t idx = jacob[i];
		if (idx < smallers.size() && !inserted[idx]) {
			std::deque<int>::iterator bound = std::lower_bound(
				result.begin(), result.end(), largers[idx]);
			binaryInsert(result, smallers[idx], bound);
			inserted[idx] = true;
		}
		for (size_t j = jacob[i] - 1; j > jacob[i - 1]; j--) {
			if (j < smallers.size() && !inserted[j]) {
				std::deque<int>::iterator bound = std::lower_bound(
					result.begin(), result.end(), largers[j]);
				binaryInsert(result, smallers[j], bound);
				inserted[j] = true;
			}
		}
	}

	size_t lastJacob = jacob.empty() ? 0 : jacob.back();
	for (size_t i = smallers.size(); i > lastJacob; i--) {
		if (i - 1 < smallers.size() && !inserted[i - 1]) {
			size_t idx = i - 1;
			std::deque<int>::iterator bound = std::lower_bound(
				result.begin(), result.end(), largers[idx]);
			binaryInsert(result, smallers[idx], bound);
			inserted[idx] = true;
		}
	}

	if (hasStraggler)
		binaryInsert(result, straggler, result.end());

	arr = result;
}

void PmergeMe::sort() {
	clock_t start, end;

	std::vector<int> vecCopy = _vec;
	start = clock();
	fordJohnsonSort(vecCopy);
	end = clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	_vec = vecCopy;

	std::deque<int> deqCopy = _deq;
	start = clock();
	fordJohnsonSort(deqCopy);
	end = clock();
	_deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	_deq = deqCopy;
}

void PmergeMe::display() const {
	std::cout << "Before:\t";
	for (size_t i = 0; i < _unsorted.size(); i++) {
		std::cout << _unsorted[i];
		if (i + 1 < _unsorted.size())
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "After:\t";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i];
		if (i + 1 < _vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << _deqTime << " us" << std::endl;
}
