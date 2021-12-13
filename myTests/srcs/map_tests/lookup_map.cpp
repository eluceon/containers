#include "map_tests.hpp"

void	lookup_map() {
	ft::map<char, char> mp;

	for (char i = 'a'; i <= 'z'; ++i)
		mp.insert(ft::make_pair(i, i));
	ft::pair<ft::map<char, char>::iterator, ft::map<char, char>::iterator> pit = mp.equal_range('k');
	ft::map<char, char>::iterator it = pit.first;
	for (; it != pit.second; ++it)
		std::cout << it->first << it->second;
	pit = mp.equal_range('K');
	std::cout << (pit.first == mp.end()) << (pit.second == mp.end());
	std::cout << mp.count('a') << mp.count('A') << mp.find('y')->first << (mp.find('A') == mp.end());
	it = mp.lower_bound('l');
	std::cout << it->first << it->second << (mp.lower_bound('L') != mp.end());
	it = mp.upper_bound('l');
	std::cout << it->first << it->second << (mp.upper_bound('L') != mp.end());
}