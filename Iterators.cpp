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
	BSTree::iterator::~iterator() {

	}
	void BSTree::iterator::operator++() {
		if (nullptr != cur->link[1])
			cur = deepLeft(cur->link[1]);
		else if (nullptr != cur->parent) {
			Node* previous = cur;
			cur = cur->parent;
			while (nullptr != cur->parent && cur->link[1] == previous)
				cur = cur->parent;
		}
	}
	void BSTree::iterator::operator--() {
		if (nullptr != cur->link[0])
			cur = deepRight(cur->link[0]);
		else while (nullptr != cur->parent && cur->parent->link[0] != cur)
			cur = cur->parent;
	}
	BSTree::Node& BSTree::iterator::operator*() const {
		return *cur;
	}
	bool BSTree::iterator::isLast() {
		return (nullptr == cur->link[1]) && (nullptr == cur->parent);
	}
	bool BSTree::iterator::isFirst() {
		return (nullptr == cur->link[0]) && (nullptr == cur->parent);
	}

}
