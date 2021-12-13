#include "map_tests.hpp"

void	constructors_map() {

    ft::vector<int> v;
	ft::map<int, char> m1;
	for (int i = 0; i < 20; ++i)
		m1.insert(ft::make_pair(i, i + 97));

	ft::map<int, char> m2(m1);
	ft::map<int, char> m3(++m1.begin(), --m1.end());

	ft::map<int, char> m4;
	m4 = m3;

	ft::map<int, char>::iterator it1 = m1.begin();
	ft::map<int, char>::iterator it2 = m2.begin();
	ft::map<int, char>::iterator it3 = m3.begin();
	ft::map<int, char>::iterator it4 = m4.begin();

	while (it1 != m1.end()) {
		std::cout << it1->first << it1->second;
		++it1;
	}

	while (it2 != m2.end()) {
		std::cout << it2->first << it2->second;
		++it2;
	}

	while (it3 != m3.end()) {
		std::cout << it3->first << it3->second;
		++it3;
	}

	while (it4 != m4.end()) {
		std::cout << it4->first << it4->second;
		++it4;
	}
}