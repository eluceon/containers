#include "map_tests.hpp"

void	iterators_map() {
	ft::map<int, char> m0;

	for (int i = 0; i < 20; ++i)
		m0.insert(ft::make_pair(i, i + 97));

	ft::map<int, char> m1(m0.begin(), m0.end());
	std::cout << m1.begin()->second << ' ' << (--m1.end())->first << ' '
		<< m1.rbegin()->second << ' ' << (--m1.rend())->second;
	
	ft::map<int, char> ::iterator it = m1.begin();
	ft::map<int, char> ::iterator ite = m1.end();

	ft::map<int, char> ::const_iterator cit = m1.begin();
	ft::map<int, char> ::const_iterator cite = m1.end();

	ft::map<int, char> ::reverse_iterator rit = m1.rbegin();
	ft::map<int, char> ::reverse_iterator rite = m1.rend();

	ft::map<int, char> ::const_reverse_iterator crit = m1.rbegin();
	ft::map<int, char> ::const_reverse_iterator crite = m1.rend();

	std::cout << std::endl;
	for (; it != ite; ++it) {
		std::cout << it->first << cit->second << (it == ite) << (it != ite)
			<< (it == it) << (it != it) << (it == it) << (cit != cit)
			<< (rit == rite) << (rit != rite) << (rit == rit)
			<< (crit == crit) << (crit != crit) << (crit == crite) << (crit != crite)
			<< (cit == cit) << (it != it) << (cit != cite) << (cit == cite);
			++rit;
			++crit;
	}

	it = ++m1.begin();
	cit = ++ ++m1.begin();
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
	
	rit = m1.rbegin();
	crit = m1.rbegin();
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


	std::cout << it->first << it->second << cit->first << cit->second
		<< rit->first << rit->second << crit->first << crit->second;
}