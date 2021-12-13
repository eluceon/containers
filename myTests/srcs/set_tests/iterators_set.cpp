#include "set_tests.hpp"

void	iterators_set() {
	ft::set<int> s0;

	for (int i = 0; i < 20; ++i)
		s0.insert(i);

	ft::set<int> s1(s0.begin(), s0.end());
	std::cout << *s1.begin() << ' ' << *(--s1.end()) << ' '
		<< *s1.rbegin() << ' ' << *(--s1.rend());
	
	ft::set<int> ::iterator it = s1.begin();
	ft::set<int> ::iterator ite = s1.end();

	ft::set<int> ::const_iterator cit = s1.begin();
	ft::set<int> ::const_iterator cite = s1.end();

	ft::set<int> ::reverse_iterator rit = s1.rbegin();
	ft::set<int> ::reverse_iterator rite = s1.rend();

	ft::set<int> ::const_reverse_iterator crit = s1.rbegin();
	ft::set<int> ::const_reverse_iterator crite = s1.rend();

	std::cout << std::endl;
	for (; it != ite; ++it) {
		std::cout << *it << *cit << (it == ite) << (it != ite)
			<< (it == it) << (it != it) << (it == it) << (cit != cit)
			<< (rit == rite) << (rit != rite) << (rit == rit)
			<< (crit == crit) << (crit != crit) << (crit == crite) << (crit != crite)
			<< (cit == cit) << (it != it) << (cit != cite) << (cit == cite);
			++rit;
			++crit;
	}

	it = ++s1.begin();
	cit = ++ ++s1.begin();
	it++;
	++it;
	it++;
	++it;
	it--;
	--it;
	cit++;
	++cit;
	cit++;
	++cit;
	cit--;
	--cit;

	rit = s1.rbegin();
	crit = s1.rbegin();
	rit++;
	++rit;
	rit++;
	++rit;
	rit--;
	--rit;
	crit++;
	++crit;
	crit++;
	++crit;
	crit--;
	--crit;


	std::cout << *it << *cit << *rit << *crit;
}