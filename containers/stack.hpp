#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template< class T, class Container = ft::vector<T> >
		class stack
	{
		public:
			typedef	Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;

			/*
			**			constructor
			** Copy-constructs the underlying container c with the contents of cont.
			** This is also the default constructor. 
			*/
			explicit stack(const container_type& cont = container_type())
				: c(cont)
			{}

			~stack()
			{}

			/*
			**	Member functions:
			*/

			value_type& top() {
				return c.back();
			}

			const value_type& top() const {
				return c.back();
			}


			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			void push(const value_type& val) {
				c.push_back(val);
			}

			void pop() {
				c.pop_back();
			}

			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

			template <class T1, class Container1>
  			friend bool operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

		protected:
			container_type	c;
	};

	/*
	**	Non-member overloads:
	*/

	template <class T, class Container>
		bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return lhs.c == rhs.c;
		}
	
	template <class T, class Container>
  		bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs == rhs);
		}

	template <class T, class Container>
  		bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return lhs.c < rhs.c;
		}

	template <class T, class Container>
  		bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(rhs < lhs);
		}

	template <class T, class Container>
  		bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return rhs < lhs;
		}
	
	template <class T, class Container>
  		bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs < rhs);
		}
}


#endif