#include "set_tests.hpp"

void	non_member_functions_set() {
	ft::set<char> s;
	for (char i = 'a'; i <= 'z'; ++i)
		s.insert(i);

	ft::set<char> s2;
	for (char i = 'A'; i <= 'Z'; ++i)
		s.insert(i);
	

	ft::set<char> s3;
	for (char i = 'a'; i <= 'z'; ++i)
		s.insert(i);

	ft::swap(s, s2);

	std::cout << (s < s2) << (s < s3) << (s < s)
			<< (s <= s2) << (s <= s3) << (s <= s)
			<< (s > s2) << (s > s3) << (s > s)
			<< (s >= s2) << (s >= s3) << (s >= s)
			<< (s == s2) << (s == s3) << (s == s)
			<< (s != s2) << (s != s3) << (s != s)
			<< (s2 < s) << (s2 < s3) << (s2 < s2)
			<< (s2 <= s) << (s2 <= s3) << (s2 <= s2)
			<< (s2 > s) << (s2 > s3) << (s2 > s2)
			<< (s2 >= s) << (s2 >= s3) << (s2 >= s2)
			<< (s2 == s) << (s2 == s3) << (s2 == s2)
			<< (s2 != s) << (s2 != s3) << (s2 != s2)
			<< (s3 < s) << (s3 < s2) << (s3 < s2)
			<< (s3 <= s) << (s3 <= s2) << (s3 <= s2)
			<< (s3 > s) << (s3 > s2) << (s3 > s2)
			<< (s3 >= s) << (s3 >= s2) << (s3 >= s2)
			<< (s3 == s) << (s3 == s2) << (s3 == s2)
			<< (s3 != s) << (s3 != s2) << (s3 != s2);
	ft::set<char>::iterator it = s.begin();
	while(it != s.end()) {
		std::cout << *it;
		++it;
	}
	it = s2.begin();
	while(it != s2.end()) {
		std::cout << *it;
		++it;
	}
}
