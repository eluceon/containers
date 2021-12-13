#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "../utils/tree.hpp"

namespace ft {
	/*
	**	Template class Tmap_traits
	*/
	template<class Key, class T, class Compare, class Alloc>
		class Tmap_traits {
	public:
		typedef Key 												key_type;
		typedef ft::pair<const Key, T>								value_type;
		typedef Compare												key_compare;
		typedef typename Alloc::template rebind<value_type>::other	allocator_type;
		Tmap_traits()
			: comp()
		{}
		Tmap_traits(Compare cmp)
			: comp(cmp)
		{}

		class value_compare : public binary_function<value_type, value_type, bool> {
			public:
				value_compare(key_compare compare) : comp(compare) {}

				bool operator()(const value_type& x, const value_type& y) const {
					return (comp(x.first, y.first));
				}
			protected:
				key_compare	comp;
		};

	protected:
		const Key& getKeyFromValue(const value_type& pair) const {
			return pair.first;
		}
		Compare comp;
		};
		

	/*
	** 	Template class map
	*/
	template<class Key, class T, class Compare = ft::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map : public Tree<Tmap_traits<Key, T, Compare, Alloc> > {
	public:
		typedef Tree<Tmap_traits< Key, T, Compare, Alloc> >	TreeBase;
		typedef Key 										key_type;
		typedef T											mapped_type;
		typedef T											referent_type;
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

		explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: TreeBase(comp, alloc)
		{}

		template <class InputIt>
		map (InputIt first, InputIt last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: TreeBase(comp, alloc)
		{
			for (; first != last; ++first)
				this->insert(*first);
		}

		map (const map& other)
			: TreeBase(other.comp, other._allocator_val)
		{
			this->insert(other.begin(), other.end());
		}

		/*
		**		operaotr[]
		** If k matches the key of an element in the container, the function returns
		** a reference to its mapped value.
		** If k does not match the key of any element in the container, the function
		** inserts a new element with that key and returns a reference to its mapped value. 
		*/
		mapped_type& operator[] (const key_type& key) {
			iterator pos = this->insert(value_type(key, mapped_type())).first;
			return (*pos).second;
		}

		mapped_type& at(const key_type& key) {
			iterator pos = this->find(key);
			if (pos == this->end())
				throw std::out_of_range("map<T> out-of-range error");
			return (*pos).second;
			}

		const mapped_type at(const key_type& key) const {
			iterator pos = this->find(key);
			if (pos == this->end())
				throw std::out_of_range("map<T> out-of-range error");
			return (*pos).second;
		}
	};
}
#endif