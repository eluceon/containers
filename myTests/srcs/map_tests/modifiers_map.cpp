#include "map_tests.hpp"

void	modifiers_map() {
	ft::map<char, char> mp;
	for (char i = 'a'; i <= 'z'; ++i)
		mp.insert(ft::make_pair(i, i));
	
	mp.erase('x');

	ft::map<char, char>::iterator it = mp.begin();
	mp.erase(++it);
	it = mp.begin();
	ft::map<char, char>::iterator ite = mp.begin();
	++ ++ ++it;
	++ ++ ++ ++ ++ ++ ++ite;
	mp.erase(it, ite);

	ft::map<char, char> mp2;
	for (char i = 'A'; i <= 'F'; ++i)
		mp2.insert(ft::make_pair(i, i));
	mp.swap(mp2);
	for (it = mp.begin(); it != mp.end(); ++it)
		std::cout << it->first << it->second;
	for (it = mp2.begin(); it != mp2.end(); ++it)
		std::cout << it->first << it->second;
	mp.clear();
	std::cout << mp.size();
}