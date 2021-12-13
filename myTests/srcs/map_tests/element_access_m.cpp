#include "map_tests.hpp"

void	element_access_map() {
	ft::map<char, char> m0;
	ft::vector<char> printVector;

	for (char i = 97; i <= 122; ++i)
		m0.insert(ft::make_pair(i, i));

	for (char i = 97; i <= 122; ++i) {
		printVector.push_back(m0[i]);
		printVector.push_back(m0.at(i));
	}
	try {
		printVector.at(printVector.size());
	} catch (std::exception& e) {
		printVector.push_back('E');
	}
	
	int i = printVector.size();
	while (--i >= 0)
		std::cout << printVector[i];
}