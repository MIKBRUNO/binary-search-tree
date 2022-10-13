#pragma once
#include <memory>

using std::shared_ptr;

namespace BinSearchTree {

	class BSTree {
	public:
		class iterator;

		BSTree() : root(nullptr) {};
		~BSTree();
		iterator begin();
		iterator end();
		void insert(int);
		inline bool IsEmpty() { return nullptr == root; }

		class Node {
		public:
			int value;
			Node(int);
			~Node();
		private:
			friend class iterator;
			friend class BSTree;
			shared_ptr<Node> link[2];
			shared_ptr<Node> parent;
		};

		class iterator {
		public:
			iterator(BSTree&);
			iterator operator++(int);
			iterator operator--(int);
			iterator& operator++();
			iterator& operator--();
			inline int operator*();
			inline bool operator==(iterator other) { return this->current == other.current; }
			inline bool operator!=(iterator other) { return !(*this == other); }
		private:
			friend class BSTree;
			shared_ptr<Node> current;
			static shared_ptr<Node> deepLeft(shared_ptr<Node>);
			static shared_ptr<Node> deepRight(shared_ptr<Node>);
		};

	private:
		shared_ptr<Node> root;
	};

	inline int BSTree::iterator::operator*() {
		if (nullptr == current)
			throw "Cannot get value by this iterator.";
		return this->current->value;
	}
	inline shared_ptr<BSTree::Node> BSTree::iterator::deepLeft(shared_ptr<BSTree::Node> from) {
		while (nullptr != from->link[0]) {
			from = from->link[0];
		}
		return from;
	}
	inline shared_ptr<BSTree::Node> BSTree::iterator::deepRight(shared_ptr<BSTree::Node> from) {
		while (nullptr != from->link[1]) {
			from = from->link[1];
		}
		return from;
	}
}
