#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterator.hpp"
# include "../utils/tree.hpp"
# include "../utils/nullptr.hpp"

#include <iostream>

class Tree;

namespace ft {
	template<class Node, class Value_Type, class Ptr, class Ref>
	class tree_iterator : public ft::iterator<bidirectional_iterator_tag, Node>
	{
		public:
			typedef Value_Type																				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		
			tree_iterator()
				: _ptrNode(myNullptr)
			{}


			tree_iterator(Node* ptrNode)
				: _ptrNode(ptrNode)
			{}

				// Copy constructor
			tree_iterator(const tree_iterator& other)
				: _ptrNode(other.base())
			{}


			~tree_iterator()
			{}

			tree_iterator&	operator=(const tree_iterator& other) {
				if (this == &other)
					return *this;
				_ptrNode = other.base();
				return *this;
			}

			reference	operator*() const {
				return _ptrNode->_value;
			}

			pointer	operator->() const {
				return (&**this);
			}

			tree_iterator&	operator++() {
				increment();
				return *this;
			}

			tree_iterator	operator++(int) {
				tree_iterator tmp = *this;;
				++*this;
				return tmp;
			}

			tree_iterator&	operator--() {
				decrement();
				return *this;
			}

			tree_iterator	operator--(int) {
				tree_iterator tmp = *this;;
				--*this;
				return tmp;
			}

			bool	operator==(const tree_iterator& other) {
				return _ptrNode == other.base();
			}

			bool	operator!=(const tree_iterator& other) {
				return !(*this == other);
			}


			Node*	base()	const {
				return _ptrNode;
			}
			
		protected:
			Node*	_ptrNode;

			static Node*	max(Node* ptr) {
				while (!ptr->_right->_isNil)
					ptr = ptr->_right;
				return ptr;
			}

			static Node*	min(Node* ptr) {
				while (!ptr->_left->_isNil)
					ptr = ptr->_left;
				return ptr;
			}
			
			void	decrement() {
				if (_ptrNode->_isNil)
					_ptrNode = _ptrNode->_right;
				else if (!_ptrNode->_left->_isNil)
					_ptrNode = max(_ptrNode->_left);
				else {
					Node*	ptr;
					while (!((ptr = _ptrNode->_parent)->_isNil) && _ptrNode == ptr->_left)
						_ptrNode = ptr;
					if (!ptr->_isNil)
						_ptrNode = ptr;
				}
			}

			void	increment() {
				if (_ptrNode->_isNil)
					;
				else if (!_ptrNode->_right->_isNil)
					_ptrNode = min(_ptrNode->_right);
				else {
					Node*	ptr;
					while (!((ptr = _ptrNode->_parent)->_isNil) && _ptrNode == ptr->_right)
						_ptrNode = ptr;
					_ptrNode = ptr;
				}
			}
	};

	template<class Node, class Value_Type, class Ptr, class Ref>
	class const_tree_iterator : public ft::iterator<bidirectional_iterator_tag, Node>
	{
		public:
			typedef Value_Type																				value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

			const_tree_iterator()
				: _ptrNode(myNullptr)
			{}

			const_tree_iterator(Node* ptrNode)
				: _ptrNode(ptrNode)
			{}

				// Copy constructor
			const_tree_iterator(const tree_iterator<Node, value_type, value_type*, value_type&>& other)
				: _ptrNode(other.base())
			{}

			const_tree_iterator(const const_tree_iterator& other)
				: _ptrNode(other.base())
			{}

			~const_tree_iterator()
			{}

			const_tree_iterator&	operator=(const const_tree_iterator& other) {
				if (this == &other)
					return *this;
				this->_ptrNode = other.base();
				return *this;
			}

			reference	operator*() const {
				return _ptrNode->_value;
			}

			pointer	operator->() const {
				return (&**this);
			}

			const_tree_iterator&	operator++() {
				increment();
				return *this;
			}

			const_tree_iterator	operator++(int) {
				const_tree_iterator tmp = *this;
				++*this;
				return tmp;
			}

			const_tree_iterator&	operator--() {
				decrement();
				return *this;
			}

			const_tree_iterator operator--(int) {
				const_tree_iterator tmp = *this;
				--*this;
				return tmp;
			}

			bool	operator==(const const_tree_iterator& other) {
				return _ptrNode == other.base();
			}

			bool	operator!=(const const_tree_iterator& other) {
				return !(*this == other);
			}


			Node*	base()	const {
				return _ptrNode;
			}
		protected:
			Node*	_ptrNode;

			static Node*	max(Node* ptr) {
				while (!ptr->_right->_isNil)
					ptr = ptr->_right;
				return ptr;
			}

			static Node*	min(Node* ptr) {
				while (!ptr->_left->_isNil)
					ptr = ptr->_left;
				return ptr;
			}

			void	decrement() {
				if (_ptrNode->_isNil)
					_ptrNode = _ptrNode->_right;
				else if (!_ptrNode->_left->_isNil)
					_ptrNode = max(_ptrNode->_left);
				else {
					Node*	ptr;
					while (!((ptr = _ptrNode->_parent)->_isNil) && _ptrNode == ptr->_left)
						_ptrNode = ptr;
					if (!ptr->_isNil)
						_ptrNode = ptr;
				}
			}

			void	increment() {
				if (_ptrNode->_isNil)
					;
				else if (!_ptrNode->_right->_isNil)
					_ptrNode = min(_ptrNode->_right);
				else {
					Node*	ptr;
					while (!((ptr = _ptrNode->_parent)->_isNil) && _ptrNode == ptr->_right)
						_ptrNode = ptr;
					_ptrNode = ptr;
				}
			}
	};
}

#endif