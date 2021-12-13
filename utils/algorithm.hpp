#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft {

	/*
	** fill - assigns value to all the elements in the range [first,last).
	*/

	template< class ForwardIt, class T >
	void fill(ForwardIt first, ForwardIt last, const T& value)
	{
		for (; first != last; ++first) {
			*first = value;
		}
	}

	/*
	**  copy - copies the elements in the range, defined by [first, last),
	** to another range beginning at d_first.
	** Returns output iterator to the element in the destination range,
	** one past the last element copied.
	*/

	template<class InputIt, class OutputIt>
	OutputIt copy (InputIt first, InputIt last, OutputIt result) {
		while (first != last) {
			*result = *first;
			++first;
			++result;
		}
		return result;
	}

	/*
	** copy_backward - copies the elements from the range, defined by [first, last),
	** to another range ending at d_last. The elements are copied in reverse order
	** (the last element is copied first), but their relative order is preserved.
	** Returns an iterator to the last element copied.
	*/
	template< class BidirIt1, class BidirIt2 >
	BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
	{
		while (first != last) {
			*(--d_last) = *(--last);
		}
		return d_last;
	}

	/*
	** equal - compares the elements in the range [first1,last1) with those in
	** the range beginning at first2, and returns true if all of the elements
	** in both ranges match.
	*/

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	/*
	**	equal 
	** Elements are compared using the given binary comparison function comp.
	*/

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate comp)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!comp(*first1, *first2))
				return false;
		}
		return true;
	}

	/*
	**			lexicographical_compare
	** Checks if the first range [first1, last1) is lexicographically less than
	** the second range [first2, last2). Elements are compared using operator<.
	*/
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	/*
	**			lexicographical_compare
	** Checks if the first range [first1, last1) is lexicographically less than
	** the second range [first2, last2). Elements are compared using the given
	** binary comparison function comp.
	*/
	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
			if (comp(*first1, *first2))
				return true;
			else if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	/*
	**	swap - exchanges the values of a and b.
	*/
	template <class T>
	void swap (T& a, T& b) {
		T tmp = a;

		a = b;
		b = tmp;
	}
}


#endif