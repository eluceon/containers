#include "stack_tests.hpp"

void	member_functions_st() {
	ft::stack<char> myStack;

	std::cout << myStack.size();
	std::cout << myStack.empty();
	for (char i = 97; i < 114; ++i)
		myStack.push(i);
	std::cout << myStack.empty();
	std::cout << myStack.size();
	std::cout << myStack.top();
	std::cout << myStack.top();
	while (myStack.size() > 0) {
		std::cout << myStack.top();
		myStack.pop();
	}
}