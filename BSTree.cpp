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
	BSTree::BSTree(int value) {
		root = new Node(value);
	}
	BSTree::~BSTree() {
		delete root;
	}
	BSTree::iterator BSTree::begin() {
		iterator begin(*this);
		begin.cur = begin.deepLeft(begin.cur);
		return begin;
	}
	BSTree::iterator BSTree::end() {
		iterator end(*this);
		end.cur = end.deepRight(end.cur);
		return end;
	}
	void BSTree::insert(int nwValue) {
		Node* elem = new Node(nwValue);
		insert(elem, this->root);
	}
	unsigned int BSTree::height(Node* elem) {
		return (nullptr != elem) ? elem->height : 0;
	}
	void BSTree::insert(Node* elem, Node* root) {
		unsigned int idx = (elem->value >= root->value);
		if (nullptr == root->link[idx]) {
			root->link[idx] = elem;
			elem->parent = root;
		}
		else
			insert(elem, root->link[idx]);
		unsigned int maxIdx = height(root->link[0]) > height(root->link[1]) ? 0 : 1;
		root->height = height(root->link[maxIdx]) + 1;
	}

}
