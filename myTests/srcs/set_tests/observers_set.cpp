#include "set_tests.hpp"

void	observers_set() {
	ft::set<int> s;
	ft::set<int, std::greater<int> > s2;
    ft::set<int, std::equal_to<int> > s3;
    std::cout << s.key_comp()(7, 9) << s.key_comp()(9, 9) << s.key_comp()(9, 7)
		<< s2.key_comp()(7, 9) << s2.key_comp()(9, 9) << s2.key_comp()(9, 7)
		<< s3.key_comp()(7, 9) << s3.key_comp()(9, 9) << s3.key_comp()(9, 7) << '\n';

	
    s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);

    int val = 4;
	
	ft::set<int>::iterator it = s.begin();
    for (; it != s.end(); ++it) {
        bool before = s.value_comp()(*it, val);
        bool after = s.value_comp()(val, *it);
 
        std::cout << '(' << *it;
        if (!before && !after)
            std::cout << ") equivalent to key " << val << '\n';
        else if (before)
            std::cout << ") goes before key " << val << '\n';
        else if (after)
            std::cout << ") goes after key " << val << '\n';
        else
            assert(0); // Cannot happen
    }
}