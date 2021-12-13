#include "map_tests.hpp"

void	observers_map() {
	ft::map<int, int> mp;
	ft::map<int, int, std::greater<int> > mp2;
    ft::map<int, int, std::equal_to<int> > mp3;
    std::cout << mp.key_comp()(7, 9) << mp.key_comp()(9, 9) << mp.key_comp()(9, 7)
		<< mp2.key_comp()(7, 9) << mp2.key_comp()(9, 9) << mp2.key_comp()(9, 7)
		<< mp3.key_comp()(7, 9) << mp3.key_comp()(9, 9) << mp3.key_comp()(9, 7) << '\n';

	
    mp.insert(ft::make_pair(1, 101));
	mp.insert(ft::make_pair(2, 102));
	mp.insert(ft::make_pair(3, 103));
	mp.insert(ft::make_pair(4, 104));
	mp.insert(ft::make_pair(5, 105));

    const ft::pair<int, char> val = ft::make_pair(4, 200);
	
	ft::map<int, int>::iterator it = mp.begin();
    for (; it != mp.end(); ++it) {
        bool before = mp.value_comp()(*it, val);
        bool after = mp.value_comp()(val, *it);
 
        std::cout << '(' << it->first << ',' << it->second;
        if (!before && !after)
            std::cout << ") equivalent to key " << val.first << '\n';
        else if (before)
            std::cout << ") goes before key " << val.first << '\n';
        else if (after)
            std::cout << ") goes after key " << val.first << '\n';
        else
            assert(0); // Cannot happen
    }
}