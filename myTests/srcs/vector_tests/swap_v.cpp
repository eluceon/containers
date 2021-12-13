#include "vector_tests.hpp"

void	testSwap() {
	ft::vector<char> v0(10, 'A');
	ft::vector<char> v1(5, 'Z');

	std::cout << "\nBefore swap\n";
	ft::vector<char>::iterator it = v0.begin();
	for (; it != v0.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	it = v1.begin();
	for (; it != v1.end(); ++it)
		std::cout << *it;

	ft::swap(v0, v1);
	std::cout << "\nAfter swap\n";
	it = v0.begin();
	for (; it != v0.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	it = v1.begin();
	for (; it != v1.end(); ++it)
		std::cout << *it;
}