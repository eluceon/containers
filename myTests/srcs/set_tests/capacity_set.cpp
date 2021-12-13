#include "set_tests.hpp"

void	capacity_set() {
	ft::set<int> m0;
	ft::vector<int> printVector;

	printVector.push_back(m0.empty());
	printVector.push_back(m0.size());

	ft::vector<int>::iterator it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	for (char i = 1; i <= 10; ++i) {
		m0.insert(i);
		printVector.push_back(m0.empty());
		printVector.push_back(m0.size());
	}

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}