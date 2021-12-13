#include "stack_tests.hpp"

void	constructors_st() {
    ft::vector<int> vect1;

	ft::vector<int> printVector;

	for (int i = 0; i < 10; ++i)
		vect1.push_back(i);


    ft::stack<int, ft::vector<int> > stack1(vect1);
	while (stack1.size() > 0) {
		printVector.push_back(stack1.top());
		stack1.pop();
	}
    ft::stack<int> stack2;
	stack2.push(99);
	stack2.push(33);
    ft::stack<int> stack3(stack2);
	ft::stack<int> stack4 = stack3;
	while (stack3.size() > 0) {
		printVector.push_back(stack3.top());
		stack3.pop();
	}
	while (stack4.size() > 0) {
		printVector.push_back(stack4.top());
		stack4.pop();
	}

	ft::vector<int>::iterator it = printVector.begin();
	for (; it != printVector.end(); ++it)
		std::cout << *it << ' ';
}