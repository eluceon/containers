#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft {

	/*
	**			binary_functiob
	** binary_function is a base class for creating function objects with two arguments.
	** binary_function does not define operator(); it is expected that derived classes will define this.
	** binary_function provides only three types - first_argument_type,
	** second_argument_type and result_type - defined by the template parameters.
	*/
	template <class Arg1, class Arg2, class Result>
  		struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	/*
	**		template<class T> struct less;
	** Function object for performing comparisons.
	** Unless specialized, invokes operator< on type T.
	*/
	template <class T>
		struct less : binary_function<T, T, bool>
	{
  		bool operator() (const T& lhs, const T& rhs) const {
			return lhs < rhs;
		}
	};
}

#endif