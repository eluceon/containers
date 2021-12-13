#include "vector_tests.hpp"

void	capacity() {
	ft::vector<int> v0;
	ft::vector<int> printVector;

	printVector.push_back(v0.size());
	printVector.push_back(v0.max_size());
	printVector.push_back(v0.capacity());
	printVector.push_back(v0.empty());

	ft::vector<int>::iterator it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	v0.reserve(100);
	printVector.push_back(v0.size());
	printVector.push_back(v0.max_size());
	printVector.push_back(v0.capacity());
	printVector.push_back(v0.empty());

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	v0.resize(30);
	printVector.push_back(v0.size());
	printVector.push_back(v0.max_size());
	printVector.push_back(v0.capacity());
	printVector.push_back(v0.empty());

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	ft::vector<int> v1(1000, 5);

	printVector.push_back(v1.size());
	printVector.push_back(v1.max_size());
	printVector.push_back(v1.capacity());
	printVector.push_back(v1.empty());

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	v1.resize(30);
	printVector.push_back(v1.size());
	printVector.push_back(v1.max_size());
	printVector.push_back(v1.capacity());
	printVector.push_back(v1.empty());

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	v1.resize(77777777);
	printVector.push_back(v1.size());
	printVector.push_back(v1.max_size());
	printVector.push_back(v1.capacity());
	printVector.push_back(v1.empty());

	it = printVector.begin();
	for (; it != printVector.end(); ++it) {
		std::cout << *it << ' ';
	}
}