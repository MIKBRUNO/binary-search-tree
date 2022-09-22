#include "BSTree.h"
#include <stack>

namespace BinSearchTree {

	BSTree::Node* BSTree::iterator::deepLeft(BSTree::Node* from) {
		while (nullptr != from->link[0]) {
			from = from->link[0];
		}
		return from;
	}
	BSTree::Node* BSTree::iterator::deepRight(BSTree::Node* from) {
		while (nullptr != from->link[1]) {
			from = from->link[1];
		}
		return from;
	}
	BSTree::iterator::iterator(BSTree& tree) {
		cur = tree.root;
	}
	BSTree::iterator::iterator() {
		cur = nullptr;
	}
	BSTree::iterator::~iterator() {}
	BSTree::iterator BSTree::iterator::operator++(int) {
		BSTree::iterator res = *this;
		if (nullptr != cur->link[1])
			cur = deepLeft(cur->link[1]);
		else if (nullptr != cur->parent) {
			Node* previous = cur;
			Node* upper = cur;
			do {
				previous = upper;
				upper = upper->parent;
			} while (nullptr != upper->parent && upper->link[1] == previous);
			if (upper->link[1] != previous)
				cur = upper;
		}
		return res;
	}
#if 0
	BSTree::iterator BSTree::iterator::operator--(int) {
		if (nullptr != cur->link[0])
			cur = deepRight(cur->link[0]);
		else while (nullptr != cur->parent && cur->parent->link[0] != cur)
			cur = cur->parent;
	}
#endif
	int BSTree::iterator::operator*() {
		return cur->value;
	}
	bool BSTree::iterator::operator==(iterator other) {
		return this->cur == other.cur;
	}
	bool BSTree::iterator::operator!=(iterator other) {
		return this->cur == other.cur;
	}
	bool BSTree::iterator::isLast() {
		iterator prev = *this;
		prev++;
		return prev == *this;
	}
	bool BSTree::iterator::isFirst() {
		return (nullptr == cur->link[0]) && (nullptr == cur->parent);
	}

}
