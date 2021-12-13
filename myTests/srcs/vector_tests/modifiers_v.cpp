#include "vector_tests.hpp"

void	modifiers() {
	ft::vector<std::string> v0;
	ft::vector<std::string> v1;

	v0.assign(5, "Hello");

	ft::vector<std::string>::reverse_iterator rit = v0.rbegin();
	ft::vector<std::string>::reverse_iterator rit_end = v0.rend();
	for (; rit != rit_end; ++rit)
		std::cout << *rit << ' ';
	std::cout << std::endl;

	v0.assign(3, "Test");
	v1.assign(v0.begin(), v0.end());
	v1.push_back("push_back_1");
	v1.push_back("push_back_2");
	v1.pop_back();

	v1.insert(v1.begin() + 5, *v1.insert(v1.begin() + 2, "Insert3"));
	v1.insert(v1.begin() + 4, 5, "5_copies");
	v1.insert(v1.begin() + 2, ++v0.begin(), v0.end() - 2);

	v1.erase(v1.begin() + 5);
	v1.erase(v1.begin() + 3, v1.begin() + 5);

	v0.swap(v1);

	rit = v1.rbegin();
	rit_end = v1.rend();
	for (; rit != rit_end; ++rit)
		std::cout << *rit << ' ';
	std::cout << "size = " << v1.size() << '\n';

	rit = v0.rbegin();
	rit_end = v0.rend();
	for (; rit != rit_end; ++rit)
		std::cout << *rit << ' ';
	std::cout << "size = " << v0.size() << '\n';
	
	v1.clear();
		rit = v1.rbegin();
	rit_end = v1.rend();
	for (; rit != rit_end; ++rit)
		std::cout << *rit << ' ';
	std::cout << "size = " << v1.size();
}