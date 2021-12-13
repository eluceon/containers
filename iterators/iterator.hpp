#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft {

	/*
	** Iterator tags
	** The iterator categories. Defines the category of an iterator.
	** Each tag is an empty type. 
	** Iterator category tags carry information that can be used to select the most
	** efficient algorithms for the specific requirement set that is implied by the category.
	*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/*
	** Iterator base class.
	** This is a base class template that can be used to derive iterator classes from it.
	** It is not an iterator class and does not provide any of the functionality an
	** iterator is expected to have.
	*/

	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
		};

	/*
	** Itarator_traits. Template class.
	** Traits class defining properties of iterators.
	** Standard algorithms determine certain properties of the iterators passed to
	** them and the range they represent by using the members of the corresponding
	** iterator_traits instantiation.
	*/

	template<class Iter>
		struct iterator_traits {
			typedef typename Iter::iterator_category	iterator_category;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
		};

	template<class T>
		struct iterator_traits<T*> {
			typedef ft::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T*									pointer;
			typedef T&									reference;
		};

	template<class T>
		struct iterator_traits<const T*> {
			typedef ft::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const T*							pointer;
			typedef const T&							reference;
		};

	/*
	**		Template function distance.
	** Calculates the number of elements between first and last iterator.
	** If it is a random-access iterator, the function uses operator- to calculate this.
	** Otherwise, the function uses the increase operator (operator++) repeatedly.
	*/

	template <class InIt>
	typename ft::iterator_traits<InIt>::difference_type
		distance (InIt first, InIt last)
	{
		typename ft::iterator_traits<InIt>::difference_type result = 0;
		distanceHelper(first, last, result, typename ft::iterator_traits<InIt>::iterator_category());
		return result;
	}

	template <class InIt, class Distance>
	void	distanceHelper(InIt first, InIt last, Distance& result,
				ft::input_iterator_tag) {
		for(; first != last; ++first)
			++result;
	}

	template <class RanIt, class Distance>
	void	distanceHelper(RanIt first, RanIt last, Distance& result,
				ft::random_access_iterator_tag) {
		result = last - first;
	}

	/*
	**			void advance(It& it, Distance n)		
	** Increments given iterator it by n elements.
	** If n is negative, the iterator is decremented. In this case, InputIt must meet the requirements 
	** of LegacyBidirectionalIterator, otherwise the behavior is undefined.
	*/

	template<class InIt>
	void advanceHelper(InIt& it, typename ft::iterator_traits<InIt>::difference_type n,
					ft::input_iterator_tag)
	{
		while (n > 0) {
			--n;
			++it;
		}
	}
	
	template<class BidIt>
	void advanceHelper(BidIt& it, typename ft::iterator_traits<BidIt>::difference_type n,
					ft::bidirectional_iterator_tag)
	{
		while (n > 0) {
			--n;
			++it;
		}
		while (n < 0) {
			++n;
			--it;
		}
	}
	
	template<class RanIt>
	void advanceHelper(RanIt& it, typename ft::iterator_traits<RanIt>::difference_type n,
					ft::random_access_iterator_tag)
	{
		it += n;
	}
	
	template<class It, class Distance>
	void advance(It& it, Distance n)
	{
		advanceHelper(it, typename ft::iterator_traits<It>::difference_type(n),
						typename ft::iterator_traits<It>::iterator_category());
	}

}

#endif