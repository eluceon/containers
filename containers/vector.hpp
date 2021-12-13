#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/type_traits.hpp"
# include "../utils/algorithm.hpp"
# include "../utils/nullptr.hpp"


namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			/*
			** Type alias
			*/		
			typedef	T	 											value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef	ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename allocator_type::size_type      		size_type;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			/*
			** Constructors
			*/
			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _first(0), _last(0), _end(0)
			{
			}

			explicit vector(size_type count, const T& value = value_type(),
                 const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				if (getMemory(count))
					_last = safeFill(_first, count, value);
			}

			vector(const vector& other) : _alloc(other._alloc) {
				if (getMemory(other.size()))
					_last = safeCopy(other.begin(), other.end(), _first);
			}

			template<class InputIt>
				vector(InputIt first, InputIt last, const allocator_type& alloc = Alloc()) 
					: _alloc(alloc)
				{
					construct(first, last);
				}

			~vector() {
				clear();
			}

			vector<T, Alloc>& operator=(const vector<T, Alloc>& other) {
				if (this == &other) {
					return *this;
				} else if (other.size() == 0) {
					clear();
				} else if (other.size() <= size()) {
					pointer ptr = ft::copy(other.begin(), other.end(), _first);
					destroy(ptr, _last);
					_last = _first + other.size();
				} else if (other.size() <= capacity()) {
					const_iterator tmpIt = other.begin() + size();
					ft::copy(other.begin(), tmpIt, _first);
					_last = safeCopy(tmpIt, other.end(), _last);
				} else {
					destroy(_first, _last);
					_alloc.deallocate(_first, _end - _first);
					if (getMemory(other.size()))
						_last = safeCopy(other.begin(), other.end(), _first);
				}
				return *this;
			}

			/*
			**					void reserve( size_type new_cap );
			** Increase the capacity of the vector to a value that's greater or equal to new_cap.
			** If new_cap is greater than the current capacity(), new storage is allocated,
			** otherwise the function does nothing.
			*/

			void reserve(size_type new_cap) {
				if (max_size() < new_cap) {
					exceptionLen();
				} else if (capacity() < new_cap) {
					pointer ptrToNewMemory = _alloc.allocate(new_cap);
					try {
						safeCopy(begin(), end(), ptrToNewMemory);
					} catch (...) {
						_alloc.deallocate(ptrToNewMemory, new_cap);
						throw;
					}
					if (_first != myNullptr) {
						destroy(_first, _last);
						_alloc.deallocate(_first, _end - _first);
					}
					_end = ptrToNewMemory + new_cap;
					_last = ptrToNewMemory + size();
					_first = ptrToNewMemory;
				}
			}

			size_type	capacity() const {
				return !_first ? 0 : _end - _first;
			}

			iterator begin() {
				return iterator(_first);
			}

			const_iterator begin() const {
				return const_iterator(_first);
			}

			iterator end() {
				return iterator(_last);
			}

			const_iterator end() const {
				return const_iterator(_last);
			}

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}
			
			/*
			** 		resize
			** Resizes the container so that it contains n elements.
			** If n is smaller than the current container size, the content is
			** reduced to its first n elements, removing those beyond (and
			** destroying them).
			** If n is greater than the current container size, the content is
			** expanded by inserting at the end as many elements as needed
			** to reach a size of n. If val is specified, the new elements are
			** initialized as copies of val, otherwise, they are value-initialized.
			** if n is also greater than the current container capacity,
			** an automatic reallocation of the allocated storage space takes place.
			*/

			void	resize (size_type n, value_type val = value_type()) {
				if (size() < n)
					insert (end(), n - size(), val);
				else if (n < size())
					erase (begin() + n, end());
			}

			size_type	size() const {
				return !_first ? 0 : _last - _first;
			}

			size_type   max_size(void) const {
				return _alloc.max_size();
			}

			bool empty() const {
				return size() == 0;
			}

			allocator_type get_allocator() const {
				return allocator_type();
			}

			/*
			** at - Returns a reference to the element at specified location pos,
			**  with bounds checking. If pos is not within the range of the
			** container, an exception of type std::out_of_range is thrown.
			*/

			reference at(size_type n) {
				if (size() <= n)
					exceptionRan();
				return *(begin() + n);
			}

			const_reference at(size_type n) const {
				if (size() <= n)
					exceptionRan();
				return *(begin() + n);
			}

			reference operator[](size_type n) {
				return *(begin() + n);
			}

			const_reference operator[](size_type n) const {
				return *(begin() + n);
			}

			reference front() {
				return *begin();
			}

			const_reference front() const {
				return *begin();
			}

			reference back() {
				return *(end() - 1);
			}

			const_reference back() const {
				return *(end() - 1);
			}

			pointer	data() {
				return _first;
			}

			const_pointer	data() const {
				return _first;
			}

			void	push_back(const value_type& val) {
				insert(end(), val);
			}

			void pop_back() {
				erase (end() - 1);
			}

			/*
			*	Replaces the contents with n copies of value value
			*/
			void assign(size_type n, const value_type& val) {
				value_type value = val;
				erase(begin(), end());
				insert(begin(), n, value);
			}

			/*
			** This overload has the same effect as overload above if InputIt is an integral type.
			*/
			template <class InputIt>
  				void assign (InputIt first, InputIt last,
						typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type* = 0)
				{
					assign(static_cast<size_type>(first), static_cast<value_type>(last));
				}

			/*
			** Replaces the contents with copies of thosein the range [first, last).
			** The behavior is undefined if either argument is an iterator into *this.
			*/
			template <class InputIt>
  				void assign (InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0)
				{
					erase(begin(), end());
					insert(begin(), first, last);
				}

			/*
			** void clear() - destroys and deallocate the entire memory-allocated
			** array and removes three pointers to member objects
			*/
			void	clear() {
				if (_first != myNullptr) {
					destroy(_first, _last);
					_alloc.deallocate(_first, _end - _first);
					_first = myNullptr;
					_last = myNullptr;
					_end = myNullptr;
				}
			}

			/*
			**	erase - removes from the vector either a single element (position)
			** or a range of elements ([first,last)).
			** Returns an iterator pointing to the new location of the element
			** that followed the last element erased by the function call
			*/
			iterator erase(iterator position) {
				ft::copy(position + 1, end(), position);
				destroy(_last - 1, _last);
				--_last;
				return (position);
			}

			iterator erase(iterator first, iterator last) {
				if (first == last)
					return first;
				pointer	newLastPtr = ft::copy(last, end(), first.base());
				destroy(newLastPtr, _last);
				_last = newLastPtr;
				return first;
			}

			/*
			** inserts value before pos
			** Returns an iterator pointing to the inserted value
			*/
			iterator insert(iterator position, const value_type& val) {
				size_type	offset = size() == 0 ? 0 : position - begin();
				insert(position, static_cast<size_type>(1), val);
				return begin() + offset;
			}

			/*
			** inserts count copies of the value val before pos
			*/
			void insert(iterator position, size_type count, const value_type& val) {
				value_type tmpVal = val;
				size_type cap = capacity();

				if (count == 0) {
					;
				} else if (size() + count > max_size()) {
					exceptionLen(); 
				} else if (cap < size() + count) {
					cap = 2 * cap > max_size() ? 0 : 2 * cap;
					if (cap < size() + count)
						cap = size() + count;
					pointer ptrToNewMemory = _alloc.allocate(cap);
					pointer ptr;
					try {
						ptr = safeCopy(begin(), position, ptrToNewMemory);
						ptr = safeFill(ptr, count, tmpVal);
						safeCopy(position, end(), ptr);
					} catch (...) {
						destroy(ptrToNewMemory, ptr);
						_alloc.deallocate(ptrToNewMemory, cap);
						throw;
					}
					if (_first != 0) {
						destroy(_first, _last);
						_alloc.deallocate(_first, _end - _first);
					}
					_end = ptrToNewMemory + cap;
					_last = ptrToNewMemory + size() + count;
					_first = ptrToNewMemory;			
				} else if (static_cast<size_type>(end() - position) < count) {
					safeCopy(position, end(), position.base() + count);
					try {
						safeFill(_last, count - (end() - position), tmpVal);
					} catch (...) {
						destroy(position.base() + count, _last + count);
						throw;
					}
					ft::fill(position, end(), tmpVal);
					_last += count;
				} else {
					iterator	itEnd = end();
					_last = safeCopy(itEnd - count, itEnd, _last);
					ft::copy_backward(position, itEnd - count, itEnd);
					ft::fill(position, position + count, tmpVal);
				}
			}

			/*
			** if InputIt is an integral type this overload has the same effect as overload previous 
			** Inserts copies (first) of the value (last) before pos
			*/
			template <class InputIt>
    			void insert(iterator position, InputIt first, InputIt last,
							typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type* = 0) {
					insert(position, static_cast<size_type>(first), static_cast<value_type>(last));
				}

			template <class InputIt> 
			void insert(iterator position, InputIt first, InputIt last,
							typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt>::type* = 0) {
				insertDo(position, first, last, typename ft::iterator_traits<InputIt>::iterator_category());
			}

			/*
			** swap - exchanges the content of the container by the content of other,
			** which is another vector object of the same type.
			*/
			

			void swap (vector& other) {
				if (_alloc != other._alloc) {
					ft::swap(_alloc, other._alloc);
				}
				ft::swap(_first, other._first);
				ft::swap(_last, other._last);
				ft::swap(_end, other._end);
			}

			

		protected:
			/*
			**	Atributes
			*/
			allocator_type	_alloc;
			pointer			_first;			// pointer to the first element of the array
			pointer			_last;			// pointer to the position following the last active element of the array
			pointer			_end;			// pointer to the position following the last element of the array
			

			/*
			** construct function for contructors
			*/
			template<class Iter>
				void construct(Iter first, Iter last, typename ft::enable_if<ft::is_integral<Iter>::value, Iter>::type* = 0) {
					size_type n = (size_type)first;
					if (getMemory(n))
						_last = safeFill(this->_first, n, (T)last);	
				}
			
			template<class Iter>
				void construct(Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = 0) {
					getMemory(0);
					insert(begin(), first, last);
				}

			/*
			** getMemory - allocates n-size memory and initializes pointers _first, _last and _end
			*/
			bool	getMemory(size_type n) {
				_first = myNullptr;
				_last = myNullptr;
				_end = myNullptr;
				if (n == 0) {
					return(false);
				} else {
					_first = _alloc.allocate(n);
					_last = _first;
					_end = _first + n;
					return true;
				}
			}

			/*
			** Destroys an array of elements in the range (ptrFirst, ptrLast)
			*/
			void	destroy(pointer ptrFirst, pointer ptrLast) {
				for (; ptrFirst != ptrLast; ++ptrFirst)
					_alloc.destroy(ptrFirst);
			}

			template<class Iter>
				pointer safeCopy(Iter first, Iter last, pointer ptr) {
					pointer ptrBegin = ptr;
					try {
						for(; first != last; ++ptr, ++first)
						 	_alloc.construct(ptr, *first);
					} catch (...) {
						destroy(ptrBegin, ptr);
						throw;
					}
					return ptr;
				}

			pointer safeFill(pointer ptr, size_type count, const T& value) {
				pointer ptrBegin = ptr;
				try {
					for (; 0 < count; --count, ++ptr)
						_alloc.construct(ptr, value);
				}	catch (...) {
					destroy(ptrBegin, ptr);
					throw;
				}
				return ptr;
			}

			void exceptionLen() const {
				throw std::length_error("vector<T> too long");
			}

			void exceptionRan() const {
				throw std::out_of_range("vector<T> out-of-range error");
			}

			template <class InputIt> 
			void insertDo(iterator position, InputIt first, InputIt last, ft::input_iterator_tag) {
				for (; first != last; ++first, ++position)
					position = insert(position, *first);
			}

			template <class InputIt> 
			void insertDo(iterator position, InputIt first, InputIt last, ft::forward_iterator_tag) {
				size_type	count = ft::distance(first, last);
				size_type cap = capacity();
				if (count == 0)
					;
				else if (size() + count > max_size())
					exceptionLen();
				else if (cap < size() + count) {
					cap = 2 * cap > max_size() ? 0 : 2 * cap;
					if (cap < size() + count)
						cap = size() + count;
					pointer ptrToNewMemory = _alloc.allocate(cap);
					pointer ptr;
					try {
						ptr = safeCopy(begin(), position, ptrToNewMemory);
						ptr = safeCopy(first, last, ptr);
						safeCopy(position, end(), ptr);
					} catch (...) {
						destroy(ptrToNewMemory, ptr);
						_alloc.deallocate(ptrToNewMemory, cap);
						throw;
					}
					if (_first != 0) {
						destroy(_first, _last);
						_alloc.deallocate(_first, _end - _first);
					}
					_end = ptrToNewMemory + cap;
					_last = ptrToNewMemory + size() + count;
					_first = ptrToNewMemory;
				} else if (static_cast<size_type>(end() - position) < count) {
					safeCopy(position, end(), position.base() + count);
					InputIt mid = first;
					ft::advance(mid, end() - position);
					try {
						safeCopy(mid, last, _last);
					} catch (...) {
						destroy (position.base() + count, _last + count);
						throw;
					}
					_last += count;
					ft::copy(first, mid, position);
				} else if (count > 0) {
					iterator itEnd = end();
					_last = safeCopy(itEnd - count, itEnd, _last);
					ft::copy_backward(position, itEnd - count, itEnd);
					ft::copy(first, last, position);
				}
			}
	};

	/*
	**	Non-member overloads. Template functions.
	*/

	template <class T, class Alloc>
		bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class T, class Alloc>
		bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
			return !(lhs == rhs);
		}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& lhs, vector<T,Alloc>&rhs)
	{
		lhs.swap(rhs);
	}

}	/* namespace ft */

#endif