#include "vector_tests.hpp"

void	testSrtings() {
	ft::vector<std::string> strV0;
	ft::vector<std::string> strV1;
	ft::vector<std::string> strV2;
	strV0.push_back("One");
	strV0.push_back("Two");
	strV0.insert(strV0.end(), "Three");
	strV0.insert(strV0.end(), "Four");

	strV1.assign(strV0.begin(), strV0.end() - 1);
	strV2 = strV0;
	strV2.pop_back();
	strV2.push_back("Four2");

	std::cout << "Vector strV0 (size = " << strV0.size() << "):\n";
	ft::vector<std::string>::iterator it = strV0.begin();
	for (; it != strV0.end(); ++it)
		std::cout << *it << ' ';

	std::cout << "\nVector strV1 (size = " << strV1.size() << "):\n";
	it = strV1.begin();
	for (; it != strV1.end(); ++it)
		std::cout << *it << ' ';

	std::cout << "\nVector strV2 (size = " << strV2.size() << "):\n";
	it = strV2.begin();
	for (; it != strV2.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << (strV0 == strV0) << (strV0 == strV1) << (strV0 == strV2)
		<< (strV0 != strV0) << (strV0 != strV1) << (strV0 != strV2)
		<< (strV0 < strV0) << (strV0 < strV1) << (strV0 < strV2)
		<< (strV0 <= strV0) << (strV0 <= strV1) << (strV0 <= strV2)
		<< (strV0 > strV0) << (strV0 > strV1) << (strV0 > strV2)
		<< (strV0 >= strV0) << (strV0 >= strV1) << (strV0 >= strV2);
}

void	testInts() {
	ft::vector<int> intV0;
	ft::vector<int> intV1;
	ft::vector<int> intV2;
	intV0.push_back(1);
	intV0.push_back(2);
	intV0.insert(intV0.end(), 3);
	intV0.insert(intV0.end(), 4);

	intV1.assign(intV0.begin(), intV0.end() - 1);
	intV2 = intV0;
	intV2.pop_back();
	intV2.push_back(5);

	std::cout << "\nVector intV0 (size = " << intV0.size() << "):\n";
	ft::vector<int>::iterator it = intV0.begin();
	for (; it != intV0.end(); ++it)
		std::cout << *it << ' ';

	std::cout << "\nVector intV1 (size = " << intV1.size() << "):\n";
	it = intV1.begin();
	for (; it != intV1.end(); ++it)
		std::cout << *it << ' ';

	std::cout << "\nVector intV2 (size = " << intV2.size() << "):\n";
	it = intV2.begin();
	for (; it != intV2.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	
	std::cout << (intV0 == intV0) << (intV0 == intV1) << (intV0 == intV2)
		<< (intV0 != intV0) << (intV0 != intV1) << (intV0 != intV2)
		<< (intV0 < intV0) << (intV0 < intV1) << (intV0 < intV2)
		<< (intV0 <= intV0) << (intV0 <= intV1) << (intV0 <= intV2)
		<< (intV0 > intV0) << (intV0 > intV1) << (intV0 > intV2)
		<< (intV0 >= intV0) << (intV0 >= intV1) << (intV0 >= intV2);
}

void	relationalOperators() {
	testSrtings();
	testInts();
}