#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "../utils/nullptr.hpp"

namespace ft {
/*
**		Template class random_access_iterator
*/
template<class T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;

/*
**		Constructors
*/
	random_access_iterator()
		: _current(myNullptr)
	{}
	explicit random_access_iterator(pointer ptr)
		: _current(ptr)
	{}

	// Copy constructor
	random_access_iterator(const random_access_iterator<T>& other)
		: _current(other._current)
	{}

	~random_access_iterator()
	{}

	random_access_iterator<T>& operator=(const random_access_iterator<T>& other) {
		if (this == &other)
			return *this;
		this->_current = other._current;
		return *this;
	}

	// Overloading conversion operators to const
	operator random_access_iterator<const T>() const {
		return random_access_iterator<const T>(_current);
    }

	reference operator*() const {
		return *_current;
	}

	pointer	operator->() const {
		return &**this;
	}

	random_access_iterator<T>& operator++() {
		++_current;
		return *this;
	}

	random_access_iterator<T> operator++(int) {
		random_access_iterator<T>	tmp = *this;
		++_current;
		return tmp;
	}

		random_access_iterator<T>& operator--() {
		--_current;
		return *this;
	}

	random_access_iterator<T> operator--(int) {
		random_access_iterator<T>	tmp = *this;
		--_current;
		return tmp;
	}

	random_access_iterator<T>& operator+=(difference_type n) {
		_current += n;
		return *this;
	}

    random_access_iterator<T> operator+(difference_type n) const {
		return random_access_iterator<T>(_current + n);
	}
	
	random_access_iterator<T>& operator-=(difference_type n) {
		_current -= n;
		return *this;
	}

	random_access_iterator<T> operator-(difference_type n) const {
		return (random_access_iterator<T>(_current - n));
	}

	reference operator[](difference_type idx) const {
		return *(*this + idx);
	}

	difference_type operator-(const random_access_iterator<T>& other) const {
		return (this->_current - other._current);
	}

	pointer	base() const {
		return _current;
	}

protected:
	pointer	_current;
	};

	template<class T>
	ft::random_access_iterator<T>  operator+(
		typename ft::random_access_iterator<T>::difference_type n,
		const ft::random_access_iterator<T>& it)
	{
			return it + n;
	}

	template <class T_L, class T_R>
	bool operator==(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class T_L, class T_R>
	bool operator!=(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return !(lhs == rhs);
	}

   	template <class T_L, class T_R>
	bool operator<(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class T_L, class T_R>
	bool operator>(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return rhs < lhs;
	}

	template <class T_L, class T_R>
	bool operator<=(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return !(rhs < lhs);
	}

	template <class T_L, class T_R>
	bool operator>=(const random_access_iterator<T_L>& lhs,
			const random_access_iterator<T_R>& rhs) {
		return !(lhs < rhs);
	}
}

#endif
