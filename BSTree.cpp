#include "BSTree.h"

namespace BinSearchTree {

	using std::shared_ptr;
	using std::make_shared;

	BSTree::Node::Node(int val) {
		value = val;
		link[0] = nullptr;
		link[1] = nullptr;
		parent = nullptr;
	}
	BSTree::Node::~Node() {
		link[0].reset();
		link[1].reset();
	}

	BSTree::~BSTree() {
		if (nullptr != root)
			root.reset();
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
		shared_ptr<Node> elem = make_shared<Node>(nwValue);
		if (nullptr == root) {
			root = elem;
			shared_ptr<Node> after_end = make_shared<Node>(666);
			after_end->parent = root;
			root->link[1] = after_end;
		}
		else {
			shared_ptr<Node> after_end = iterator::deepRight(root);
			after_end->parent->link[1] = nullptr;

			shared_ptr<Node> cur = root;
			unsigned int idx = (elem->value >= cur->value);
			while (nullptr != cur->link[idx]) {
				cur = cur->link[idx];
				idx = (elem->value >= cur->value);
			}
			cur->link[idx] = elem;
			elem->parent = cur;

			shared_ptr<Node> nwEnd = after_end->parent->link[1];
			shared_ptr<Node> oldEnd = after_end->parent;
			after_end = make_shared<Node>(666);
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
