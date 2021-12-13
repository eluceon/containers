#include "vector_tests.hpp"
#define	QTY 10

struct Struct {
	int			_i;
	float		_f;
	double		_d;
	std::string _str;
	
	Struct(int i = 7, float f = 0.78f, double d = 1.78, std::string str = "Noname")
		: _i(i), _f(f), _d(d), _str(str)
	{}
};

void	getAllocator() {
	Struct MyStr(11, 11.11, 111.11, "Constructed");

	ft::vector<Struct> structVector;

	// allocate an array with space for 5 structs using vector's allocator:
	Struct* structPtr = structVector.get_allocator().allocate(QTY);
	for (int i = 0; i < QTY; ++i)
		structVector.get_allocator().construct(&structPtr[i], MyStr);
	
	structVector.assign(3, structPtr[4]);

	std::cout << "Vector of structs contains:\n";
	ft::vector<Struct>::iterator it = structVector.begin();
	for (; it != structVector.end(); ++it)
		std::cout << (*it)._i << ' ' << (*it)._f << ' '
			<< (*it)._d << ' ' << (*it)._str << ' ';
	std::cout << std::endl;

	std::cout << "The allocated array of structs contains:\n";
	for (int i = 0; i < QTY; ++i)
		std::cout << ' ' << structPtr[i]._i << ' ' << structPtr[i]._f << ' '
			<< structPtr[i]._d << ' ' << structPtr[i]._str << ' ';

	// destroy and deallocate:
	for (int i = 0; i < QTY; ++i)
		structVector.get_allocator().destroy(&structPtr[i]);
	structVector.get_allocator().deallocate(structPtr, QTY);

}
