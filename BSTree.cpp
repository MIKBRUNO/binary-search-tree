#include "BSTree.h"

namespace BinSearchTree {

	BSTree::Node::Node(int val) {
		value = val;
		link[0] = nullptr;
		link[1] = nullptr;
		parent = nullptr;
		height = 1;

	}
	BSTree::Node::~Node() {
		if (nullptr != link[0])
			delete link[0];
		if (nullptr != link[1])
			delete link[1];
	}

	BSTree::~BSTree() {
		if (nullptr != root)
			delete root;
	}
	BSTree::iterator BSTree::begin() {
		return iterator(*this);
	}
	BSTree::iterator BSTree::end() {
		iterator end(*this);
		end.current = nullptr;
		return end;
	}
	void BSTree::insert(int nwValue) {
		Node* elem = new Node(nwValue);
		if (nullptr == root)
			root = elem;
		else {
			Node* cur = root;
			unsigned int idx = (elem->value >= cur->value);
			while (nullptr != cur->link[idx]) {
				cur = cur->link[idx];
				idx = (elem->value >= cur->value);
			}
			cur->link[idx] = elem;
			elem->parent = cur;
		}
	}

}
