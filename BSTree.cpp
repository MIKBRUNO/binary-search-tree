#include "BSTree.h"

namespace BinSearchTree {

	BSTree::Node::Node(int val) {
		value = val;
		link[0] = nullptr;
		link[1] = nullptr;
		height = 1;

	}

	BSTree::Node::~Node() {
		if (nullptr != link[0])
			delete link[0];
		if (nullptr != link[1])
			delete link[1];
	}

	BSTree::BSTree(int value) {
		root = new Node(value);
		begin = new Iterator(*this);
	}

	BSTree::~BSTree() {
		delete root;
		delete begin;
	}

	const BSTree::Iterator& BSTree::getBegin() {
		return *begin;
	}

	void BSTree::insert(int nwValue) {
		Node* elem = new Node(nwValue);
		insert(elem, &(this->root));
		begin->cur = begin->deepLeft(begin->cur);
	}

	unsigned int BSTree::height(Node* elem) {
		return (nullptr != elem) ? elem->height : 0;
	}

	void BSTree::insert(Node* elem, Node** tree) {
		if (nullptr == elem)
			return;
		if (nullptr == *tree) {
			(*tree) = elem;
			return;
		}
		unsigned int idx = (elem->value >= (*tree)->value);
		insert(elem, &((*tree)->link[idx]));
		unsigned int maxIdx = height((*tree)->link[0]) > height((*tree)->link[1]) ? 0 : 1;
		(*tree)->height = height((*tree)->link[maxIdx]) + 1;
	}

}
