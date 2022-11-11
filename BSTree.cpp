#include "BSTree.h"

namespace BinSearchTree {

	BSTree::Node::Node(int val) {
		value = val;
		link[0] = nullptr;
		link[1] = nullptr;
		parent = nullptr;
	}
	BSTree::Node::~Node() {
		delete link[0];
		delete link[1];
	}

	BSTree::~BSTree() {
		delete root;
	}
	BSTree::iterator BSTree::begin() {
		iterator begin(*this);
		if (!IsEmpty())
			begin.current = begin.deepLeft(begin.current);
		return begin;
	}
	BSTree::iterator BSTree::end() {
		iterator end(*this);
		if (!IsEmpty())
			end.current = end.deepRight(end.current);
		end.isAfterEnd = true;
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
