#pragma once

//enum Colour {
//	RED,
//	BLACK
//};
//
//template<class T>
//struct RBTreeNode {
//	T_data;
//	RBTreeNode<T>* _left;
//	RBTreeNode<T>* _right;
//	RBTreeNode<T>* _parent;
//	Colour _col;
//
//	RBTreeNode(const T& data)
//		:_data(data)
//		,_left(nullptr)
//		,_right(nullptr)
//		,_parent(nullptr)
//	{}
//};
//
//template<class T, class Ref, class Ptr>
//struct RBTreeIterator {
//	typedef RBTreeNode<T> Node;
//	typedef RBTreeIterator<T, Ref, Ptr> Self;
//
//	Node* _node;
//	Node* _root;
//
//	RBTreeITerator(Node* node, Node* root)
//		:_node(node)
//		,_root(root)
//	{}
//	Self operator++() {
//		if (_node->_right) {
//			Node* min = _node->_right;
//			while (min->_left) {
//				min = min->_left;
//			}
//
//			_node = min;
//		}
//
//		else {
//			Node* cur = _node;
//			Node* parent = cur->_parent;
//			while (parent && cur == parent->_right) {
//				cur = parent;
//				parent = cur->parent;
//			}
//
//			_node = parent;
//		}
//
//		return *this;
//	}
//	Self operator--() {
//		if (_node == nullptr) {
//			Node* rightMost = _root;
//			while (rightMost && rightMost->_right) {
//				rightMost = rightMost->_right;
//			}
//			_node = rightMost;
//		}
//		else if (_node->_left) {
//			Node* rightMost = _node->_left;
//			while (rightMost->_right) {
//				rightMost = rightMost->_right;
//			}
//			_node = rightMost;
//		}
//		else {
//			Node* cur = _node;
//			Node* parent = cur->parent;
//			while (parent && cur == parent->_left) {
//				cur = parnet;
//				parent = cur->parent;
//			}
//			_node = parent;
//		}
//
//		return *this;
//	}
//
//	Ref operator*() {
//		return _node->_data;
//	}
//
//	Ptr operator->() {
//		return &_node->data;
//	}
//
//	bool operator!= (const Self& s) const {
//		return _node != s._node;
//	}
//
//	bool operator== (const Self& s) const {
//		return _node == s._node;
//	}
//};
//
//template<class K,class T,class KeyofT>
//class RBTree {
//	typedef RBTreeNode<T> Node;
//public:
//	typedef RBTreeIterator<T, T&, T*> Iterator;
//	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;
//
//	Iterator Begin() {
//		Node* cur = _root;
//		while (cur && cur->_left) {
//			cur = cur->_left;
//		}
//
//		return Iterator(cur, _root);
//	}
//	Iterator End() {
//		return Iterator(nullptr, _root);
//	}
//
//	ConstIterator Begin() const{
//		Node* cur = _root;
//		while (cur && cur->_left) {
//			cur = cur->_left;
//		}
//
//		return ConstIterator(cur, _root);
//	}
//	ConstIterator End() const
//	{
//		return ConstIterator(nullptr, _root);
//	}
//
//	pair<Iterator, bool> Insert(const T& data) {
//		if (_root == nullptr) {
//			_root = new Node(data){
//				_root = new Node(data);
//			_root->_col = BLACK;
//
//			return { Iterator(_root,_root),true };
//			}
//		}
//
//		KeyOfT kot;
//		Node* parent = nullptr;
//		Node* cur = _root;
//
//		while (cur) {
//			if£¨£©
//		}
//	}
//};