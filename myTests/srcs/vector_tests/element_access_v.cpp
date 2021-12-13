#include "vector_tests.hpp"

void	elementAccess() {
	ft::vector<char> v0;
	ft::vector<char> printVector;

	for (char i = 97; i <= 122; ++i)
		v0.push_back(i);
	
	int	i = v0.size();
	while (--i >= 0) {
		printVector.push_back(v0[i]);
		printVector.push_back(v0.at(i));
	}
	printVector.push_back(v0.front());
	printVector.push_back(v0.back());
	try {
		printVector.at(printVector.size());
	} catch (std::exception& e) {
		printVector.push_back('E');
	}
	
	i = printVector.size();
	while (--i >= 0)
		std::cout << printVector[i];
}