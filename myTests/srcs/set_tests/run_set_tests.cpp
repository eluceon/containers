#include "set_tests.hpp"

void	runSetTests(bool isTimerOn) {
	std::cout << GREEN_COLOR << "********** SET TESTS **********"
		<< RESTORE_COLOR << std::endl;
	runTest(constructors_set, isTimerOn, "constructors and operator=");
	runTest(iterators_set, isTimerOn, "iterators: begin, end, rbegin, rend");
	runTest(capacity_set, isTimerOn, "capacity: emtpy, size");
	runTest(modifiers_set, isTimerOn, "modifiers: insert, erase, swap, clear");
	runTest(lookup_set, isTimerOn, "lookup: count, find, equal_range, lower_bound, upper_bound");
	runTest(observers_set, isTimerOn, "observers: key_comp, value_comp");
	runTest(non_member_functions_set, isTimerOn,
		"non member functions: ==, !=, <, >, <=, >=, ft::swap(ft::set)");
}