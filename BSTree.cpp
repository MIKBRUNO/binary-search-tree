#include "BSTree.h"

namespace BinSearchTree {

	BSTree::Node::Node(int val) {
		value = val;
		link[0] = nullptr;
		link[1] = nullptr;
		parent = nullptr;
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
		iterator begin(*this);
		if (!IsEmpty())
			begin.current = begin.deepLeft(begin.current);
		return begin;
	}
	BSTree::iterator BSTree::end() {
		iterator end(*this);
		end.current = afterEnd;
		return end;
	}
	void BSTree::insert(int nwValue) {
		Node* elem = new Node(nwValue);
		if (nullptr == root) {
			root = elem;
			afterEnd = new Node(0);
			afterEnd->parent = root;
			root->link[1] = afterEnd;
		}
		else {
			afterEnd->parent->link[1] = nullptr;

			Node* cur = root;
			unsigned int idx = (elem->value >= cur->value);
			while (nullptr != cur->link[idx]) {
				cur = cur->link[idx];
				idx = (elem->value >= cur->value);
			}
			cur->link[idx] = elem;
			elem->parent = cur;

			Node* nwEnd = afterEnd->parent->link[1];
			if (nullptr != nwEnd) {
				nwEnd->link[1] = afterEnd;
				afterEnd->parent = nwEnd;
			}
			else
				afterEnd->parent->link[1] = afterEnd;
		}
	}

}
