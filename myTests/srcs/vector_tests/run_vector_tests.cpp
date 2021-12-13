#include "vector_tests.hpp"

void	runVectorTests(bool isTimerOn) {
	std::cout << GREEN_COLOR << "********** VECTOR TESTS **********"
		<< RESTORE_COLOR << std::endl;
	runTest(constructors, isTimerOn, "constructors and operator=");
	runTest(iterators, isTimerOn, "iterators: begin, end, rbegin, rend");
	runTest(capacity, isTimerOn,
		"capacity: size, max_size, resize, capacity, empty, reserve");
	runTest(elementAccess, isTimerOn,
		"element access: operator[], at, front, back");
	runTest(modifiers, isTimerOn,
		"modifiers: assign, push_back, pop_back, insert, erase, swap, clear");
	runTest(getAllocator, isTimerOn, "get_allocator");
	runTest(relationalOperators, isTimerOn, "relational operators");
	runTest(testSwap, isTimerOn, "swap");
}