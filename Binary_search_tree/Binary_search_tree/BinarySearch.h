#pragma once
#include<iostream>
using namespace std;

namespace key_value 
{
	template<class K,class V>
	struct BSTNode {
		K _key;
		V _value;

		BSTNode<K , V>* _left;
		BSTNode<K, V>* _right;

		BSTNode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K,class V>
	class BSTree {
		using Node = BSTNode<K, V>;
	public:
		BSTree() = default;

		BSTree(const BSTree& t) {
			_root = Copy(t._root);
		}

		BSTree& operator=(BSTree tmp) {
			swap(_root, tmp._root);
			return *this;
		}

		~BSTree(){
			Destroy(_root);
			_root = nullptr;
		}

		bool Insert(const K& key, const V& value) {
			if (_root == nullptr) {
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur) {
				if (cur->_key < key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else {
				parent->_left = cur;
			}

			return true;
		}

		Node* Find(const K& key) {
			Node* cur = _root;
			while (cur) {
				if (cur->_key < key) {
					cur = cur¡ª > _right;
				}
				else if (cur->_key > key) {
					cur = cur->_left;
				}
				else {
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key) {
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur) {
				if (cur->_key < key) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key < key) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					if (cur == _root) {
						_root = cur->_right;
					}
					else {
						if (parent->_left == cur) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr) {
					if (cur == _root) {
						_root = cur->_left;
					}
					else {
						if (parent->_left == cur) {
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}

						delete cur;
					}
				else {
					Node* replaceParent = cur;
					Node* replace = cur->_right;
					while (replace->_left) {
						replaceParent = replace;
						repace = replace->_left;
					}

					cur->_key = replace->_key;

					if (replaceParent->_left == replace)
						replaceParent->_left = replace->_right;
					else
						replaceParent->_right = replace->_right;

					delete replace;
				}

				return true;
				}
			}
		}
		return false;

		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}
		private:
			void _InOrder(Node* root) {
				if (root == nullptr) {
					return;
				}
				_InOrder(root->_left);
				cout << root¡ª > key << "";
				_InOrder(root->right);
			}
			private:
				Node _root = nullptr;
	};
}
