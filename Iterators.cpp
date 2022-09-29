#include "BSTree.h"
#include <stack>

namespace BinSearchTree {

	BSTree::iterator::iterator(BSTree& tree) {
		current = tree.root;
		if (!tree.IsEmpty())
			current = deepLeft(current);
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
			else
				current = nullptr;
		}
		return res;
	}
}
