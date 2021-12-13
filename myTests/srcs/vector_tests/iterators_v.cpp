#include "vector_tests.hpp"

void	iterators() {
	ft::vector<char> v0;

	v0.push_back('a');
	v0.push_back('b');
	v0.push_back('c');
	v0.push_back('d');
	ft::vector<char> v1(v0.begin(), v0.end());
	std::cout << *v1.begin() << ' ' << *--v1.end() << ' ' << *v1.rbegin()
		<< ' ' << *--v1.rend();
	
	ft::vector<char>::iterator it = v1.begin();
	ft::vector<char>::iterator ite = v1.end();

	ft::vector<char>::const_iterator cit = v1.begin();
	ft::vector<char>::const_iterator cite = v1.end();

	ft::vector<char>::reverse_iterator rit = v1.rbegin();
	ft::vector<char>::reverse_iterator rite = v1.rend();

	ft::vector<char>::const_reverse_iterator crit = v1.rbegin();
	ft::vector<char>::const_reverse_iterator crite = v1.rend();

	std::cout << std::endl;
	for (; it != ite; it++) {
		std::cout << *(it) << *(cit) << (it == ite) << (it < ite)
			<< (it > ite) << (it <= ite) << (it >= ite) << (it != ite)
			<< (it == it) << (it < it) << (it > it) << (it <= it) << '\n'
			<< (it >= it) << (it != it) << (it == cit++) << (it < cit)
			<< (it > cit) << (it <= cit) << (it >= cit) << (it != cit)
			<< (rit <= rite) << (rit >= rite) << (rit != rite) << '\n'
			<< (rit == rit) << (rit < rit) << (rit > rit) << (rit <= rit)
			<< (rit >= rit) << (rit != rit) << (rit == crit) << (rit < crit) 
			<< (rit > crit) << (rit <= crit) << (rit >= crit) << '\n'
			<< (rit != crit) << (crit <= crite) << (crit >= crite)
			<< (crit != crite) << (crit == crit) << (crit < crit) << (crit > crit)
			<< (crit <= crit) << (cit >= it) << (cit != it) << '\n'
			<< (cit != cite) << (cit == cite) << (cit < cite)
			<< (cit > cite) << (cit <= cite) << (cit >= cite);
			++rit;
			++crit;
	}

	it = v1.begin() + 2;
	cit = v1.begin() + 2;

	bool a = (it == cit);
	std::cout << a;
	// *cit = 'y';		// We can't change const_iterator!!!!!!!!!
}