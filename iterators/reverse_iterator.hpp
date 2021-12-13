#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {
	/*
	**		Template class reverse_iterator
	*/
	template <class Iter>
	class reverse_iterator {

	public:
		typedef	Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename ft::iterator_traits<Iter>::reference			reference;

		reverse_iterator()
		{}
		
		// construct from original iterator
		explicit reverse_iterator(iterator_type it)
			: _current(it)
		{}

		// construct from other reverse iterator
		template <class U>
			reverse_iterator(const U& other)
				: _current(other.base())
			{}
			
		~reverse_iterator()
		{}

		reverse_iterator& operator=(const reverse_iterator& other) {
			if (this == &other)
				return *this;
			this->_current = other.base();
			return *this;
		}

		iterator_type	base() const {
			return _current;
		}

		reference	operator*() const {
			iterator_type	tmp = _current;
			return *--tmp;
		}

		pointer	operator->() const {
			return &**this;
		}

		reverse_iterator<Iter>& operator++() {
			--_current;
			return *this;
		}

		reverse_iterator<Iter> operator++(int) {
			reverse_iterator<Iter>	tmp = *this;
			--_current;
			return tmp;
		}

		reverse_iterator<Iter>& operator--() {
			++_current;
			return *this;
		}

		reverse_iterator<Iter> operator--(int) {
			reverse_iterator<Iter>	tmp = *this;
			++_current;
			return tmp;
		}

		// Bellow only for random access iterator
		reverse_iterator<Iter>& operator+=(difference_type n) {
			_current -= n;
			return *this;
		}

		reverse_iterator<Iter> operator+(difference_type n) const {
			return reverse_iterator<Iter>(_current - n);
		}

		reverse_iterator<Iter>& operator-=(difference_type n) {
			_current += n;
			return *this; 
		}

		reverse_iterator<Iter> operator-(difference_type n) const {
			return reverse_iterator<Iter>(_current + n);
		}

		reference operator[](difference_type n) {
			return *(*this + n);
		}

	protected:
		iterator_type	_current;
	};

	/*
	** reverse_iterator template operators
	*/
	template< class Iter >
	reverse_iterator<Iter> operator+(
				typename reverse_iterator<Iter>::difference_type n,
               	const reverse_iterator<Iter>& it) {
		return it + n;
	}

	// Returns the distance between lhs and rhs.
	template <class Iter>
  		typename reverse_iterator<Iter>::difference_type operator-(
   			const reverse_iterator<Iter>& lhs,
    		const reverse_iterator<Iter>& rhs) {
			return lhs.base() - rhs.base();
	}

	template <class Iter_L, class Iter_R>
  	bool operator==(const reverse_iterator<Iter_L>& lhs,
                   const reverse_iterator<Iter_R>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class Iter_L, class Iter_R>
	bool operator!=(const reverse_iterator<Iter_L>& lhs,
    		const reverse_iterator<Iter_R>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template <class Iter_L, class Iter_R>
	bool operator<(const reverse_iterator<Iter_L>& lhs,
        	const reverse_iterator<Iter_R>& rhs) {
		return lhs.base() > rhs.base();
	}

	template <class Iter_L, class Iter_R>
  	bool operator>(const reverse_iterator<Iter_L>& lhs,
                   const reverse_iterator<Iter_R>& rhs) {
		return rhs < lhs;
	}

	template <class Iter_L, class Iter_R>
  	bool operator<=(const reverse_iterator<Iter_L>& lhs,
                   const reverse_iterator<Iter_R>& rhs) {
		return !(rhs < lhs);
	}

	template <class Iter_L, class Iter_R>
  	bool operator>=(const reverse_iterator<Iter_L>& lhs,
                   const reverse_iterator<Iter_R>& rhs) {
		return !(lhs < rhs);
	}
}

#endif