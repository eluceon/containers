#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
	
	/*
	**				integral_constant
	** This template is designed to provide compile-time constants as types.
	** It is used by several parts of the standard library as the base class for trait types.
	*/
	template<class T, T Val>
		struct integral_constant
	{
		static const T value = Val;
		typedef const T value_type;
		typedef integral_constant<T, Val> type;

		// Overloading conversion operators
		operator value_type() const {
			return (value);
		}

		value_type operator()() const {
			return (value);
		}
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class>
		struct is_integral_type : public false_type {};
	template<>
		struct is_integral_type<bool> : public true_type {};

	template<>
		struct is_integral_type<char> : public true_type {};

	template<>
		struct is_integral_type<signed char> : public true_type {};

	template<>
		struct is_integral_type<short int> : public true_type {};

	template<>
		struct is_integral_type<int> : public true_type {};

	template<>
		struct is_integral_type<long int> : public true_type {};

	template<>
		struct is_integral_type<long long int> : public true_type {};

	template<>
		struct is_integral_type<unsigned char> : public true_type {};

	template<>
		struct is_integral_type<unsigned short int> : public true_type {};

	template<>
		struct is_integral_type<wchar_t> : public true_type {};

	template<>
		struct is_integral_type<char16_t> : public true_type {};

	template<>
		struct is_integral_type<unsigned int> : public true_type {};

	template<>
		struct is_integral_type<unsigned long int> : public true_type {};

	template<>
		struct is_integral_type<unsigned long long int> : public true_type {};

	/*
	**			is_integeral
	** Trait class that identifies whether T is an integral type.
	** It inherits from integral_constant as being either true_type or false_type,
	** depending on whether T is an integral type:
	*/
	template <class T>
		struct is_integral : public is_integral_type<T> {};


	/*
	** The type T is enabled as member type enable_if::type if Cond is true.
	** Otherwise, enable_if::type is not defined.
	** This is useful to hide signatures on compile time when a particular
	** condition is not met, since in this case, the member enable_if::type will
	** not be defined and attempting to compile using it should fail.
	*/
	template<bool B, class T = void>
		struct enable_if {};
	
	template<class T>
		struct enable_if<true, T>
	{
		typedef T type;
	};

	/*
	**					template <class T, class U> struct is_same;
	** If T and U name the same type (taking into account const/volatile qualifications),
	** provides the member constant value equal to true. Otherwise value is false.
	*/
	template<class T, class U>
		struct is_same : ft::false_type {};
	
	template<class T>
		struct is_same<T, T> : ft::true_type {};
}

#endif