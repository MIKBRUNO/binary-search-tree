#pragma once
#include <memory>
#include <stdexcept>

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
			Node* link[2];
			Node* parent;
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
			Node* current;
			static Node* deepLeft(Node*);
			static Node* deepRight(Node*);
		};

	private:
		Node* root;
	};

	inline int BSTree::iterator::operator*() {
		if (nullptr == current)
			throw std::logic_error("Cannot get value by this iterator.");
		return this->current->value;
	}
	inline BSTree::Node* BSTree::iterator::deepLeft(BSTree::Node* from) {
		while (nullptr != from->link[0]) {
			from = from->link[0];
		}
		return from;
	}
	inline BSTree::Node* BSTree::iterator::deepRight(BSTree::Node* from) {
		while (nullptr != from->link[1]) {
			from = from->link[1];
		}
		return from;
	}
}
