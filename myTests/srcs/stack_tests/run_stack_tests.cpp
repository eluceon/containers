#include "stack_tests.hpp"

void	runStackTests(bool isTimerOn) {
	std::cout << '\n' << GREEN_COLOR << "********** STACK TESTS **********"
		<< RESTORE_COLOR << std::endl;
	runTest(constructors_st, isTimerOn, "constructor and operator=");
	runTest(member_functions_st, isTimerOn,
		"member functions: empty, size, top, push, pop");
	runTest(relationalOperatorsStack, isTimerOn, "relational operators");

}