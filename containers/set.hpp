#ifndef SET_HPP
# define SET_HPP

# include "../utils/tree.hpp"
# include <iostream>

namespace ft {
	/*
	**	Template class Tset_traits
	*/
	template<class Key, class Compare, class Alloc>
		class Tset_traits {
	public:
		typedef Key key_type;
		typedef Key value_type;
		typedef Compare key_compare;
		typedef typename Alloc::template rebind<value_type>::other
			allocator_type;
		Tset_traits()
			: comp()
		{}
		Tset_traits(Compare cmp)
			: comp(cmp)
		{}
		typedef key_compare value_compare;
	protected:
		const Key& getKeyFromValue(const value_type& val) const {
			return val;
		}
		Compare comp;
		};
		

	/*
	** 	Template class set
	*/
	template<class Key, class Compare = ft::less<Key>, class Alloc = std::allocator<Key> >
		class set : public Tree<Tset_traits<Key, Compare, Alloc> > {
	public:
		typedef Tree<Tset_traits< Key, Compare, Alloc> >	TreeBase;
		typedef Key											key_type;
		typedef Compare										key_compare;
		typedef typename TreeBase::value_compare			value_compare;
		typedef typename TreeBase::allocator_type			allocator_type;
		typedef typename TreeBase::size_type				size_type;
		typedef typename TreeBase::difference_type			difference_type;
		typedef typename TreeBase::pointer					pointer;
		typedef typename TreeBase::const_pointer			const_pointer;
		typedef typename TreeBase::reference				reference;
		typedef typename TreeBase::const_reference			const_reference;
		typedef typename TreeBase::iterator					iterator;
		typedef typename TreeBase::const_iterator			const_iterator;
		typedef typename TreeBase::reverse_iterator			reverse_iterator;
		typedef typename TreeBase::const_reverse_iterator	const_reverse_iterator;
		typedef typename TreeBase::value_type				value_type;

		explicit set (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: TreeBase(comp, alloc)
		{}

		template <class InputIt>
		set (InputIt first, InputIt last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: TreeBase(comp, alloc)
		{
			for (; first != last; ++first)
				this->insert(*first);
		}

		set (const set& other)
			: TreeBase(other.comp, other._allocator_val)
		{
			this->insert(other.begin(), other.end());
		}
	};
}
#endif