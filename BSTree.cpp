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
		if (!IsEmpty())
			end.current = end.deepRight(end.current);
		return end;
	}
	void BSTree::insert(int nwValue) {
		Node* elem = new Node(nwValue);
		if (nullptr == root) {
			root = elem;
			Node* after_end = new Node(666);
			after_end->parent = root;
			root->link[1] = after_end;
		}
		else {
			Node* after_end = iterator::deepRight(root);
			after_end->parent->link[1] = nullptr;

			Node* cur = root;
			unsigned int idx = (elem->value >= cur->value);
			while (nullptr != cur->link[idx]) {
				cur = cur->link[idx];
				idx = (elem->value >= cur->value);
			}
			cur->link[idx] = elem;
			elem->parent = cur;

			Node* nwEnd = after_end->parent->link[1];
			Node* oldEnd = after_end->parent;
			delete after_end;
			after_end = new Node(666);
			if (nullptr != nwEnd) {
				nwEnd->link[1] = after_end;
				after_end->parent = nwEnd;
			}
			else {
				oldEnd->link[1] = after_end;
				after_end->parent = oldEnd;
			}
		}
	}

}
