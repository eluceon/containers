#include "map_tests.hpp"

void	non_member_functions() {
	ft::map<char, char> mp;
	for (char i = 'a'; i <= 'z'; ++i)
		mp.insert(ft::make_pair(i, i));

	ft::map<char, char> mp2;
	for (char i = 'A'; i <= 'Z'; ++i)
		mp.insert(ft::make_pair(i, i));
	

	ft::map<char, char> mp3;
	for (char i = 'a'; i <= 'z'; ++i)
		mp.insert(ft::make_pair(i, i + 1));

	ft::swap(mp, mp2);

	std::cout << (mp < mp2) << (mp < mp3) << (mp < mp)
			<< (mp <= mp2) << (mp <= mp3) << (mp <= mp)
			<< (mp > mp2) << (mp > mp3) << (mp > mp)
			<< (mp >= mp2) << (mp >= mp3) << (mp >= mp)
			<< (mp == mp2) << (mp == mp3) << (mp == mp)
			<< (mp != mp2) << (mp != mp3) << (mp != mp)
			<< (mp2 < mp) << (mp2 < mp3) << (mp2 < mp2)
			<< (mp2 <= mp) << (mp2 <= mp3) << (mp2 <= mp2)
			<< (mp2 > mp) << (mp2 > mp3) << (mp2 > mp2)
			<< (mp2 >= mp) << (mp2 >= mp3) << (mp2 >= mp2)
			<< (mp2 == mp) << (mp2 == mp3) << (mp2 == mp2)
			<< (mp2 != mp) << (mp2 != mp3) << (mp2 != mp2)
			<< (mp3 < mp) << (mp3 < mp2) << (mp3 < mp2)
			<< (mp3 <= mp) << (mp3 <= mp2) << (mp3 <= mp2)
			<< (mp3 > mp) << (mp3 > mp2) << (mp3 > mp2)
			<< (mp3 >= mp) << (mp3 >= mp2) << (mp3 >= mp2)
			<< (mp3 == mp) << (mp3 == mp2) << (mp3 == mp2)
			<< (mp3 != mp) << (mp3 != mp2) << (mp3 != mp2);
	ft::map<char, char>::iterator it = mp.begin();
	while(it != mp.end()) {
		std::cout << it->first << it->second;
		++it;
	}
	it = mp2.begin();
	while(it != mp2.end()) {
		std::cout << it->first << it->second;
		++it;
	}
}
