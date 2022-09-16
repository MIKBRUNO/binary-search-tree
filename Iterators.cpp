#include "BSTree.h"
#include <stack>

namespace BinSearchTree {

	BSTree::Node* BSTree::Iterator::deepLeft(BSTree::Node* from) {
		while (nullptr != from->link[0]) {
			forwardStack->push(from);
			from = from->link[0];
		}
		return from;
	}
	BSTree::Node* BSTree::Iterator::deepRight(BSTree::Node* from) {
		while (nullptr != from->link[1]) {
			from = from->link[1];
		}
		return from;
	}
	BSTree::Iterator::Iterator(BSTree& tree) {
		cur = tree.root;
		backwardStack = new std::stack<BSTree::Node*>;
		forwardStack = new std::stack<BSTree::Node*>;
	}
	BSTree::Iterator::~Iterator() {
		delete forwardStack;
		delete backwardStack;
	}
	void BSTree::Iterator::operator++() {
		if (nullptr != cur->link[1]) {
			backwardStack->push(cur);
			cur = deepLeft(cur->link[1]);
		}
		else if (!forwardStack->empty()) {
			cur = forwardStack->top();
			forwardStack->pop();
		}
	}
	void BSTree::Iterator::operator--() {
		if (nullptr != cur->link[0]) {
			forwardStack->push(cur);
			cur = deepRight(cur->link[0]);
		}
		else if (!backwardStack->empty()) {
			cur = backwardStack->top();
			backwardStack->pop();
		}
	}
	BSTree::Node& BSTree::Iterator::operator*() const {
		return *cur;
	}
	bool BSTree::Iterator::isLast() {
		return (nullptr == cur->link[1]) && (forwardStack->empty());
	}
	bool BSTree::Iterator::isFirst() {
		return (nullptr == cur->link[0]) && (backwardStack->empty());
	}

}
