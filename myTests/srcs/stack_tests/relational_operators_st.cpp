#include "stack_tests.hpp"

void	testSrtingsStack() {
	ft::stack<std::string> strSt0;
	ft::stack<std::string> strSt1;
	ft::stack<std::string> strSt2;
	strSt0.push("One");
	strSt0.push("Two");
	strSt0.push("Three");
	strSt0.push("Four");

	strSt1 = strSt0;
	strSt1.push("Five");

	strSt2.push("One");
	strSt2.push("Two");
	strSt2.push("Three");
	strSt2.push("Foura");

	std::cout << (strSt0 == strSt0) << (strSt0 == strSt1) << (strSt0 == strSt2)
		<< (strSt0 != strSt0) << (strSt0 != strSt1) << (strSt0 != strSt2)
		<< (strSt0 < strSt0) << (strSt0 < strSt1) << (strSt0 < strSt2)
		<< (strSt0 <= strSt0) << (strSt0 <= strSt1) << (strSt0 <= strSt2)
		<< (strSt0 > strSt0) << (strSt0 > strSt1) << (strSt0 > strSt2)
		<< (strSt0 >= strSt0) << (strSt0 >= strSt1) << (strSt0 >= strSt2);
}

void	testIntsStack() {
	ft::stack<int> intSt0;
	ft::stack<int> intSt1;
	ft::stack<int> intSt2;

	intSt0.push(1);
	intSt0.push(2);
	intSt0.push(3);
	intSt0.push(4);

	intSt1 = intSt0;
	intSt1.push(5);

	intSt2.push(5);
	intSt2.push(7);
	intSt2.push(3);
	intSt2.push(3);
	
	std::cout << (intSt0 == intSt0) << (intSt0 == intSt1) << (intSt0 == intSt2)
		<< (intSt0 != intSt0) << (intSt0 != intSt1) << (intSt0 != intSt2)
		<< (intSt0 < intSt0) << (intSt0 < intSt1) << (intSt0 < intSt2)
		<< (intSt0 <= intSt0) << (intSt0 <= intSt1) << (intSt0 <= intSt2)
		<< (intSt0 > intSt0) << (intSt0 > intSt1) << (intSt0 > intSt2)
		<< (intSt0 >= intSt0) << (intSt0 >= intSt1) << (intSt0 >= intSt2);
}

void	relationalOperatorsStack() {
	testSrtingsStack();
	testIntsStack();
}