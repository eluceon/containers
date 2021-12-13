#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
	template< class T1, class T2 > struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		/*
		** default constructor
		*/
		pair()
			: first(T1()), second(T2())
		{}

		/*
		** copy constructor
		*/
		template<class U1, class U2>
			pair (const pair<U1, U2>& other)
			: first(other.first), second(other.second)
		{}
		
		/*
		** initialization constructor
		*/
		pair (const first_type& v1, const second_type& v2)
			: first(v1), second(v2)
		{}

		~pair() {}

		pair& operator=(const pair& other) {
			if (this == &other)
				return *this;
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
		
		first_type	first;
		second_type	second;
	};
	/*
	** Template operators
	*/

	template< class T1, class T2 >
		bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
		bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	/*
	**  If lhs.first < rhs.first, returns true. Otherwise, if rhs.first < lhs.first, returns false.
	** Otherwise, if lhs.second < rhs.second, returns true. Otherwise, returns false.
	*/
	template< class T1, class T2 >
		bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template< class T1, class T2 >
		bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template< class T1, class T2 >
		bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
		bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
		ft::pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return ft::pair<T1, T2>(x, y);
	}
}

#endif