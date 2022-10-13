#include "BSTree.h"
#include <stack>

namespace BinSearchTree {

	BSTree::iterator::iterator(BSTree& tree) {
		current = tree.root;
	}
	BSTree::iterator BSTree::iterator::operator++(int) {
		BSTree::iterator res = *this;
		if (nullptr == current)
			return res;
		if (nullptr != current->link[1])
			current = deepLeft(current->link[1]);
		else if (nullptr != current->parent) {
			Node* previous = current;
			Node* upper = current;
			do {
				previous = upper;
				upper = upper->parent;
			} while (nullptr != upper->parent && upper->link[1] == previous);
			if (upper->link[1] != previous)
				current = upper;
		}
		return res;
	}
	BSTree::iterator BSTree::iterator::operator--(int) {
		BSTree::iterator res = *this;
		if (nullptr == current)
			return res;
		if (nullptr != current->link[0])
			current = deepRight(current->link[0]);
		else if (nullptr != current->parent) {
			Node* previous = current;
			Node* upper = current;
			do {
				previous = upper;
				upper = upper->parent;
			} while (nullptr != upper->parent && upper->link[0] == previous);
			if (upper->link[0] != previous)
				current = upper;
		}
		return res;
	}
}
