#include "vector_tests.hpp"

void	constructors() {
	ft::vector<int> v0; 
    ft::vector<int> v1(v0);
    ft::vector<int> v2(1000000, 3);
	ft::vector<int> v3(1000000, 7);
	ft::vector<int> printVector;
    v2 = v3;
    ft::vector<int> v4(v2);
    ft::vector<int> v5(v2.begin(), v2.end());

    printVector.push_back(v2[5]);
    printVector.push_back(v4[5]);
    printVector.push_back(v5[5]);
    printVector.push_back(v5.size());
    printVector.push_back(v5.capacity());
    try {
		ft::vector<int> tmp5(-1, 6);
	} catch (std::exception& e) {
		printVector.push_back(1);
	}
	ft::vector<int>::iterator it = printVector.begin();
	for (; it != printVector.end(); ++it)
		std::cout << *it << ' ';
}