#include "set_tests.hpp"

void	modifiers_set() {
	ft::set<char> s;
	for (char i = 'a'; i <= 'z'; ++i)
		s.insert(i);
	
	s.erase('x');

	ft::set<char>::iterator it = s.begin();
	s.erase(++it);
	it = s.begin();
	ft::set<char>::iterator ite = s.begin();
	++ ++ ++it;
	++ ++ ++ ++ ++ ++ ++ite;
	s.erase(it, ite);

	ft::set<char> s2;
	for (char i = 'A'; i <= 'F'; ++i)
		s2.insert(i);
	s.swap(s2);
	for (it = s.begin(); it != s.end(); ++it)
		std::cout << *it;
	for (it = s2.begin(); it != s2.end(); ++it)
		std::cout << *it;
	s.clear();
	std::cout << s.size();
}