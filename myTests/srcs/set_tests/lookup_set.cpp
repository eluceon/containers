#include "set_tests.hpp"

void	lookup_set() {
	ft::set<char> s;

	for (char i = 'a'; i <= 'z'; ++i)
		s.insert(i);
	ft::pair<ft::set<char>::iterator, ft::set<char>::iterator> pit = s.equal_range('k');
	ft::set<char>::iterator it = pit.first;
	for (; it != pit.second; ++it)
		std::cout << *it;
	pit = s.equal_range('K');
	std::cout << (pit.first == s.end()) << (pit.second == s.end());
	std::cout << s.count('a') << s.count('A') << *s.find('y') << (s.find('A') == s.end());
	it = s.lower_bound('l');
	std::cout << *it << (s.lower_bound('L') != s.end());
	it = s.upper_bound('l');
	std::cout << *it << (s.upper_bound('L') != s.end());
}