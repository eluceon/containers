#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <stdexcept>
# include "functional.hpp"
# include "utility.hpp"
# include "algorithm.hpp"
# include "../iterators/tree_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/nullptr.hpp"

namespace ft {
	template<class Tr>
	class Tree : public Tr {
		protected:
			enum e_node_color {
				RED,
				BLACK
			};

			struct Node {
				Node*					_left;
				Node*					_right;
				Node*					_parent;
				typename Tr::value_type	_value;
				char					_color;
				bool					_isNil;
			};
		
		public:

			typedef typename Tr::allocator_type					allocator_type;
			typedef typename Tr::key_type						key_type;
			typedef typename Tr::key_compare					key_compare;
			typedef typename Tr::value_type	 					value_type;
			typedef typename Tr::value_compare					value_compare;
			typedef typename allocator_type::size_type 			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::template
				rebind<value_type>::other::pointer				pointer;
			typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer		const_pointer;
			typedef typename allocator_type::template
				rebind<value_type>::other::reference			reference;
			typedef typename allocator_type::template
				rebind<value_type>::other::const_reference		const_reference;
			typedef ft::tree_iterator<Node, value_type,
									pointer, reference>			iterator;
			typedef ft::const_tree_iterator<Node, value_type,
							const_pointer, const_reference>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			Tree(const key_compare& comp, const allocator_type& al)
				: Tr(comp),
				_allocator_val(al),
				_allocator_node(al),
				_allocator_nodePtr(al)
			{
				init();
			}

			Tree(const Tree& other)
				: Tr(other.comp),
				_allocator_val(other.get_allocator()),
				_allocator_node(other.get_allocator()),
				_allocator_nodePtr(other.get_allocator())
			{
				init();
				copy(other);
			}

			~Tree() {
				erase(begin(), end());
				freeNode(_head);
				_head = myNullptr;
				_size = 0;
			}

			Tree& operator=(const Tree& other) {
				if (this != &other) {
					erase(begin(), end());
					this->comp = other.comp;
					copy(other);
				}
				return *this;
			}

			iterator begin() {
				return iterator(_head->_left);
			}

			const_iterator begin() const {
				return const_iterator(_head->_left);
			}

			iterator end() {
				return iterator(_head);
			}

			const_iterator end() const {
				return const_iterator(_head);
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

			size_type size() const {
				return _size;
			}

			size_type max_size() const {
				return _allocator_val.max_size();
			}

			bool empty() const {
				return size() == 0;
			}

			allocator_type get_allocator() const {
				return _allocator_val;
			}

			key_compare key_comp() const {
				return this->comp;
			}

			value_compare value_comp() const {
				return value_compare(key_comp());
			}

			/*
			** return a pair, with its member pair::first set to an iterator
			** pointing to either the newly inserted element or to the
			** equivalent element already in the set. The pair::second element
			** in the pair is set to true if a new element was inserted or
			** false if an equivalent element already existed.
			*/
			ft::pair<iterator, bool> insert(const value_type& val) {
				Node* tmp = root();
				Node* ptr = _head;
				bool isAddLeft = true;

				while (!tmp->_isNil) {
					ptr = tmp;
					isAddLeft = this->comp(this->getKeyFromValue(val), getKey(tmp));
					tmp = isAddLeft ? tmp->_left : tmp->_right;
				}
				iterator it = iterator(ptr);
				if (isAddLeft) {
					if (it == begin())
						return ft::pair<iterator, bool>(insertDo(true, ptr, val), true);
					else
						--it;
				}
				if (this->comp(getKey(it.base()), this->getKeyFromValue(val)))
					return ft::pair<iterator, bool>(insertDo(isAddLeft, ptr, val), true);
				return ft::pair<iterator, bool>(it, false);
			}

			/*
			** Returns an iterator pointing to either the newly inserted
			** element or to the element that already had its same value in the set.
			** position is a hint for the position where the element can be inserted.
			*/
			iterator insert(iterator position, const value_type& val) {
				if (size() == 0) {
					return insertDo(true, _head, val);
				} else if (position == begin()) {
					if (this->comp(this->getKeyFromValue(val), getKey(position.base())))
						return insertDo(true, position.base(), val);
				} else if (position == end()) {
					if (this->comp(getKey(_head->_right), this->getKeyFromValue(val)))
						return insertDo(false, _head->_right, val);
				} else {
					iterator prevPosition = position;
					if (this->comp(getKey((--prevPosition).base()), this->getKeyFromValue(val))
						&& this->comp(this->getKeyFromValue(val), getKey(position.base()))) {
						if (prevPosition.base()->_right->_isNil)
							return insertDo(false, prevPosition.base(), val);
						else
							return insertDo(true, position.base(), val);
					}
				}
				return insert(val).first;
			}

			/*
			**	 Inserts elements from range [first, last)
			*/
			template <class InputIt>
  				void insert(InputIt first, InputIt last) {
					for (; first != last; ++first)
						insert(*first);
				}
			/*
			** Removes the element at position.
			** Returns an iterator following the last removed element.
			*/
			iterator erase(iterator pos) {
				Node* nodeAfterReplacement = myNullptr;
				Node* parentNodeAfterReplacement;
				Node* replacement;
				Node* node;

				if (pos.base()->_isNil)
					throw std::out_of_range("set/map out of range (NIL)");
				node = (pos++).base();
				replacement = findReplacement(node, nodeAfterReplacement);
				replaceNode(node, replacement, nodeAfterReplacement, parentNodeAfterReplacement);
				if (node->_color == BLACK)
					balanceTreeAfterEraising(nodeAfterReplacement, parentNodeAfterReplacement);
				_allocator_val.destroy(&node->_value);
				freeNode(node);
				if (_size > 0)
					--_size;
				return pos;
			}

			/*
			** Removes the elements in the range [first; last),
			** which must be a valid range in *this.
			** Returns an iterator following the last removed element.
			*/
			iterator erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
				return first;
			}
			
			/*
			** Removes the element (if one exists) with the key equivalent to key.
			** Returns the number of elements removed (0 or 1).
			*/
			size_type	erase (const key_type& key) {
				ft::pair<iterator, iterator> pos = equal_range(key);
				size_type count = 0;
				count = ft::distance(pos.first, pos.second);
				erase(pos.first, pos.second);
				return count;
			}

			void	clear() {
				erase(begin(), end());
			}

			/*
			** Searches the container for an element with a key and returns an
			** iterator to it if found, otherwise it returns an iterator to end.
			*/
			iterator find (const key_type& key) {
				iterator it = lower_bound(key);

				return it == end() || this->comp(key, getKey(it.base()))
						? end() : it;
			}

			const_iterator find(const key_type& key) const {
				const_iterator it = lower_bound(key);

				return it == end() || this->comp(key, getKey(it.base()))
						? end() : it;
			}

			size_type	count(const key_type& key) const {
				ft::pair<const_iterator, const_iterator> ans = equal_range(key);

				return ft::distance(ans.first, ans.second);
			}

			/*
			** Returns an iterator pointing to the first element in the container
			** which is not considered to go before key (i.e., either it is
			** equivalent or goes after).
			*/
			iterator lower_bound(const key_type& key) {
				Node* ptr = root();
				Node* returnPtr = _head;

				while (!ptr->_isNil) {
					if (this->comp(getKey(ptr), key)) {
						ptr = ptr->_right;
					} else {
						returnPtr = ptr;
						ptr = ptr->_left;
					}
				}
				return iterator(returnPtr);
			}

			const_iterator lower_bound(const key_type& key)  const {
				Node* ptr = root();
				Node* returnPtr = _head;

				while (!ptr->_isNil) {
					if (this->comp(getKey(ptr), key)) {
						ptr = ptr->_right;
					} else {
						returnPtr = ptr;
						ptr = ptr->_left;
					}
				}
				return const_iterator(returnPtr);
			}

			/*
			** Returns an iterator pointing to the first element that
			** is greater than key.
			*/
			iterator upper_bound(const key_type& key) {
				Node*	ptr = root();
				Node*	returnPtr = _head;

				while (!ptr->_isNil) {
					if (this->comp(key, getKey(ptr))) {
						returnPtr = ptr;
						ptr = ptr->_left;
					} else {
						ptr = ptr->_right;
					}
				}
				return iterator(returnPtr);
			}

			const_iterator upper_bound(const key_type& key)  const {
				Node*	ptr = root();
				Node*	returnPtr = _head;

				while (!ptr->_isNil) {
					if (this->comp(key, getKey(ptr))) {
						returnPtr = ptr;
						ptr = ptr->_left;
					} else {
						ptr = ptr->_right;
					}
				}
				return const_iterator(returnPtr);
			}

			/*
			** Returns a range containing all elements with the given key in the
			** container. The range is defined by two iterators, one pointing to
			** the first element that is not less than key and another pointing
			** to the first element greater than key. Alternatively, the first
			** iterator may be obtained with lower_bound(), and the second with
			** upper_bound().
			*/
			ft::pair<iterator, iterator> equal_range (const key_type& key) {
				return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
			}

			ft::pair<const_iterator, const_iterator>
					equal_range (const key_type& key) const
			{
				return ft::pair<const_iterator, const_iterator>
							(lower_bound(key), upper_bound(key));
			}

			void	swap(Tree<Tr>& other) {
				if (get_allocator() != other.get_allocator()) {
					ft::swap(_allocator_val, other._allocator_val);
					ft::swap(_allocator_node, other._allocator_node);
					ft::swap(_allocator_nodePtr, other._allocator_nodePtr);
				}
				ft::swap(this->comp, other.comp);
				ft::swap(_head, other._head);
				ft::swap(_size, other._size);
			}

		protected:
			void init() {
				_head = initNode(myNullptr, BLACK);
				_head->_isNil = true;
				root() = _head;
				_head->_right = _head;
				_head->_left = _head;
				_size = 0;
			}

			void	copy(const Tree<Tr>& other) {
				root() = copy(other.root(), _head);
				_size = other.size();
				if (!root()->_isNil) {
					_head->_left = min(root());
					_head->_right = max(root());
				} else {
					_head->_left = _head;
					_head->_right = _head;
				}

			}
 
			Node* copy(Node* srcNode, Node* parentNode) {
				Node* newHead = _head;

				if (!srcNode->_isNil) {
					Node* dstNode = initNode(parentNode, srcNode->_color);
					try {
						_allocator_val.construct(&dstNode->_value, srcNode->_value);
					} catch (...) {
						freeNode(dstNode);
						eraseDo(newHead);
						throw;
					}
					dstNode->_left = _head;
					dstNode->_right = _head;
					if (newHead->_isNil)
						newHead = dstNode;
					try {
						dstNode->_left = copy(srcNode->_left, dstNode);
						dstNode->_right = copy(srcNode->_right, dstNode);
					} catch (...) {
						eraseDo(newHead);
						throw;
					}
				}
				return newHead;
			}

			void	balanceTreeAfterInsert(Node* currentNode) {
				Node*	uncleNode;

				while (currentNode->_parent->_color == RED) {
					if (currentNode->_parent == currentNode->_parent->_parent->_left) {
						uncleNode = currentNode->_parent->_parent->_right;
						if (uncleNode->_color == RED) {
							currentNode->_parent->_color = BLACK;
							uncleNode->_color = BLACK;
							currentNode->_parent->_parent->_color = RED;
							currentNode = currentNode->_parent->_parent;
						} else {
							if (currentNode == currentNode->_parent->_right) {
								currentNode = currentNode->_parent;
								rotateLeft(currentNode);
							}
							currentNode->_parent->_color = BLACK;
							currentNode->_parent->_parent->_color = RED;
							rotateRight(currentNode->_parent->_parent);

						}
					} else {
						uncleNode = currentNode->_parent->_parent->_left;
						if (uncleNode->_color == RED) {
							currentNode->_parent->_color = BLACK;
							uncleNode->_color = BLACK;
							currentNode->_parent->_parent->_color = RED;
							currentNode = currentNode->_parent->_parent;
						} else {
							if (currentNode == currentNode->_parent->_left) {
								currentNode = currentNode->_parent;
								rotateRight(currentNode);
							}
							currentNode->_parent->_color = BLACK;
							currentNode->_parent->_parent->_color = RED;
							rotateLeft(currentNode->_parent->_parent);
						}
					}
				}
				root()->_color = BLACK;
			}

			iterator insertDo(bool isAddLeft, Node* lastNode, const value_type& val) {
				if (max_size() - 1 <= _size)
					throw std::length_error("set/map length is too long");
				Node* newNode = initNode(lastNode, RED);
				newNode->_left = _head;
				newNode->_right = _head;
				try {
					_allocator_val.construct(&newNode->_value, val);
				} catch (...) {
					freeNode(newNode);
					throw;
				}
				++_size;
				if (lastNode == _head) {
					root() = newNode;
					_head->_left = newNode;
					_head->_right = newNode;
				} else if (isAddLeft) {
					lastNode->_left = newNode;
					if (lastNode == _head->_left)
						_head->_left = newNode;
				} else {
					lastNode->_right = newNode;
					if (lastNode == _head->_right)
						_head->_right = newNode;
				}
				balanceTreeAfterInsert(newNode);
				return iterator(newNode);
			}

			void eraseDo(Node* node) {
				for (Node* tmp = node; !tmp->_isNil; node = tmp) {
					eraseDo(tmp->_right);
					tmp = tmp->_left;
					_allocator_val.destroy(&node->_value);
					freeNode(node);
				}
			}

			static Node* max(Node* ptr) {
				while (!ptr->_right->_isNil)
					ptr = ptr->_right;
				return ptr;
			}

			static Node* min(Node* ptr) {
				while (!ptr->_left->_isNil)
					ptr = ptr->_left;
				return ptr;
			}

			void	rotateRight(Node* node) {
				Node* pivot = node->_left;

				node->_left = pivot->_right;
				if (!pivot->_right->_isNil)
					pivot->_right->_parent = node;
				pivot->_parent = node->_parent;

				if (node == root())
					root() = pivot;
				else if (node == node->_parent->_right)
					node->_parent->_right = pivot;
				else
					node->_parent->_left = pivot;
					
				pivot->_right = node;
				node->_parent = pivot;
			}

			void	rotateLeft(Node* node) {
				Node* pivot = node->_right;

				node->_right = pivot->_left;
				if (!pivot->_left->_isNil)
					pivot->_left->_parent = node;

				pivot->_parent = node->_parent;
				if (node == root())
					root() =  pivot;
				else if (node == node->_parent->_left)
					node->_parent->_left = pivot;
				else
					node->_parent->_right = pivot;

				pivot->_left = node;
				node->_parent = pivot;
			}

			Node*& root() {
				return _head->_parent;
			}

			Node*& root() const {
				return _head->_parent;
			}

			void freeNode(Node* node) {
				_allocator_nodePtr.destroy(&node->_parent);
				_allocator_nodePtr.destroy(&node->_right);
				_allocator_nodePtr.destroy(&node->_left);
				_allocator_node.deallocate(node, 1);
			}

			const key_type& getKey (Node* ptr) const {
				return (this->getKeyFromValue(ptr->_value));
			}

			Node* initNode(Node* parentNode, char color) {
				Node* newNode = _allocator_node.allocate(1);
				_allocator_nodePtr.construct(&newNode->_left, myNullptr);
				_allocator_nodePtr.construct(&newNode->_right, myNullptr);
				_allocator_nodePtr.construct(&newNode->_parent, parentNode);
				newNode->_color = color;
				newNode->_isNil = false;
				return newNode;
			}

			Node* findReplacement(Node* replacement, Node*& nodeAfterReplacement) {
				if (replacement->_left->_isNil) {
					nodeAfterReplacement = replacement->_right;
				} else if (replacement->_right->_isNil) {
					nodeAfterReplacement = replacement->_left;
				} else {
					replacement = min(replacement->_right);
					nodeAfterReplacement = replacement->_right;
				}
				return replacement;
			}

			void replaceNode(Node* node, Node* replacement,
				Node* nodeAfterReplacement, Node*& parentNodeAfterReplacement)
			{
				if (replacement == node) {
					parentNodeAfterReplacement = node->_parent;
					if (!nodeAfterReplacement->_isNil)
						nodeAfterReplacement->_parent = parentNodeAfterReplacement;
					if (root() == node)
						root() = nodeAfterReplacement;
					else if (parentNodeAfterReplacement->_left == node)
						parentNodeAfterReplacement->_left = nodeAfterReplacement;
					else
						parentNodeAfterReplacement->_right = nodeAfterReplacement;
					if (_head->_left == node) {
						if (node->_right->_isNil)
							_head->_left = parentNodeAfterReplacement;
						else
							_head->_left = min(nodeAfterReplacement);
					}
					if (_head->_right == node) {
						if (node->_left->_isNil)
							_head->_right = parentNodeAfterReplacement;
						else
							_head->_right = max(nodeAfterReplacement);
					}
				} else {								// node has left and right children
					node->_left->_parent = replacement;
					replacement->_left = node->_left;
					if (replacement == node->_right)
						parentNodeAfterReplacement = replacement;
					else {
						parentNodeAfterReplacement = replacement->_parent;
						if (!nodeAfterReplacement->_isNil)
							nodeAfterReplacement->_parent = parentNodeAfterReplacement;
						parentNodeAfterReplacement->_left = nodeAfterReplacement;
						replacement->_right = node->_right;
						node->_right->_parent = replacement;
					}
					if (root() == node)
						root() = replacement;
					else if (node->_parent->_left == node)
						node->_parent->_left = replacement;
					else
						node->_parent->_right = replacement;
					replacement->_parent = node->_parent;
					ft::swap(replacement->_color, node->_color);
				}
			}

			void	balanceTreeAfterEraising(Node*& nodeAfterReplacement, Node*& parentNodeAfterReplacement) {
				for (; nodeAfterReplacement != root() && nodeAfterReplacement->_color == BLACK;
					parentNodeAfterReplacement = nodeAfterReplacement->_parent)
				{
					if (nodeAfterReplacement == parentNodeAfterReplacement->_left) {
						Node* brotherNodeAfterReplacement = parentNodeAfterReplacement->_right;
						if (brotherNodeAfterReplacement->_color == RED) {
							brotherNodeAfterReplacement->_color = BLACK;
							parentNodeAfterReplacement->_color = RED;
							rotateLeft(parentNodeAfterReplacement);
							brotherNodeAfterReplacement = parentNodeAfterReplacement->_right;
						}
						if (brotherNodeAfterReplacement->_isNil) {
							nodeAfterReplacement = parentNodeAfterReplacement; 			 //should't happen
						} else if (brotherNodeAfterReplacement->_left->_color == BLACK
									&& brotherNodeAfterReplacement->_right->_color == BLACK) {
							brotherNodeAfterReplacement->_color = RED;
							nodeAfterReplacement = parentNodeAfterReplacement;
						} else {
							if (brotherNodeAfterReplacement->_right->_color == BLACK) {
								brotherNodeAfterReplacement->_left->_color = BLACK;
								brotherNodeAfterReplacement->_color = RED;
								rotateRight(brotherNodeAfterReplacement);
								brotherNodeAfterReplacement = parentNodeAfterReplacement->_right;
							}
							brotherNodeAfterReplacement->_color = parentNodeAfterReplacement->_color;
							parentNodeAfterReplacement->_color = BLACK;
							brotherNodeAfterReplacement->_right->_color = BLACK;
							rotateLeft(parentNodeAfterReplacement);
							break;
						}
					} else {
						Node* brotherNodeAfterReplacement = parentNodeAfterReplacement->_left;
						if (brotherNodeAfterReplacement->_color == RED) {
							brotherNodeAfterReplacement->_color = BLACK;
							parentNodeAfterReplacement->_color = RED;
							rotateRight(parentNodeAfterReplacement);
							brotherNodeAfterReplacement = parentNodeAfterReplacement->_left;
						}
						if (brotherNodeAfterReplacement->_isNil) {
							nodeAfterReplacement = parentNodeAfterReplacement; 			 //should't happen
						} else if (brotherNodeAfterReplacement->_right->_color == BLACK
									&& brotherNodeAfterReplacement->_left->_color == BLACK) {
							brotherNodeAfterReplacement->_color = RED;
							nodeAfterReplacement = parentNodeAfterReplacement;
						} else {
							if (brotherNodeAfterReplacement->_left->_color == BLACK) {
								brotherNodeAfterReplacement->_right->_color = BLACK;
								brotherNodeAfterReplacement->_color = RED;
								rotateLeft(brotherNodeAfterReplacement);
								brotherNodeAfterReplacement = parentNodeAfterReplacement->_left;
							}
							brotherNodeAfterReplacement->_color = parentNodeAfterReplacement->_color;
							parentNodeAfterReplacement->_color = BLACK;
							brotherNodeAfterReplacement->_left->_color = BLACK;
							rotateRight(parentNodeAfterReplacement);
							break;
						}
					}
				}
				nodeAfterReplacement->_color = BLACK;
			}

			Node*								_head;
			size_type							_size;
			allocator_type						_allocator_val;
			typename allocator_type::template
				rebind<Node>::other				_allocator_node;
			typename allocator_type::template
				rebind<Node *>::other			_allocator_nodePtr;
	};

	/*
	** Non-member functions
	*/
	template <class Tr>
  	bool operator==(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return lhs.size() == rhs.size()
		  	&& ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Tr>
  	bool operator!=(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return !(lhs == rhs);
	}

	template <class Tr>
  	bool operator<(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end());
	}

	template <class Tr>
  	bool operator>(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return rhs < lhs;
	}

	template <class Tr>
  	bool operator<=(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return !(rhs < lhs);
	}

	template <class Tr>
  	bool operator>=(const Tree<Tr>& lhs, const Tree<Tr>& rhs) {
		return !(lhs < rhs);
	}

	template<class Tr>
		void swap(Tree<Tr>& x, Tree<Tr>& y) {
			x.swap(y);
		}
}
#endif