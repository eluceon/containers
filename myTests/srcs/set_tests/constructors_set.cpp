#include "set_tests.hpp"

void	constructors_set() {

    ft::vector<int> v;
	ft::set<int> s1;
	for (int i = 0; i < 20; ++i)
		s1.insert(i);

	ft::set<int> s2(s1);
	ft::set<int> s3(++s1.begin(), --s1.end());

	ft::set<int> s4;
	s4 = s3;

	ft::set<int>::iterator it1 = s1.begin();
	ft::set<int>::iterator it2 = s2.begin();
	ft::set<int>::iterator it3 = s3.begin();
	ft::set<int>::iterator it4 = s4.begin();

	while (it1 != s1.end()) {
		std::cout << *it1;
		++it1;
	}

	while (it2 != s2.end()) {
		std::cout << *it2;
		++it2;
	}

	while (it3 != s3.end()) {
		std::cout << *it3;
		++it3;
	}

	while (it4 != s4.end()) {
		std::cout << *it4;
		++it4;
	}
}