#include "BSTree.h"

namespace BinSearchTree {

	BSTree::iterator::iterator(BSTree& tree) {
		current = tree.root;
		isAfterEnd = (nullptr == current);
	}
	BSTree::iterator& BSTree::iterator::operator++() {
		if (isAfterEnd)
			return *this;
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
			else
				isAfterEnd = true;
		}
		else
			isAfterEnd = true;
		return *this;
	}
	BSTree::iterator& BSTree::iterator::operator--() {
		if (isAfterEnd && (nullptr != current)) {
			isAfterEnd = false;
			return *this;
		}
		if (nullptr == current)
			return *this;
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
		return *this;
	}
	BSTree::iterator BSTree::iterator::operator++(int) {
		iterator res = *this;
		++(*this);
		return res;
	}
	BSTree::iterator BSTree::iterator::operator--(int) {
		iterator res = *this;
		--(*this);
		return res;
	}
}
