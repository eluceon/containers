#include "map_tests.hpp"

void	runMapTests(bool isTimerOn) {
	std::cout << GREEN_COLOR << "********** MAP TESTS **********"
		<< RESTORE_COLOR << std::endl;
	runTest(constructors_map, isTimerOn, "constructors and operator=");
	runTest(element_access_map, isTimerOn, "element access: operator[], at");
	runTest(iterators_map, isTimerOn, "iterators: begin, end, rbegin, rend");
	runTest(capacity_map, isTimerOn, "capacity: emtpy, size");
	runTest(modifiers_map, isTimerOn, "modifiers: insert, erase, swap, clear");
	runTest(lookup_map, isTimerOn, "lookup: count, find, equal_range, lower_bound, upper_bound");
	runTest(observers_map, isTimerOn, "observers: key_comp, value_comp");
	runTest(non_member_functions, isTimerOn,
		"non member functions: ==, !=, <, >, <=, >=, ft::swap(ft::map)");
}