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
			explicit iterator(BSTree&);
			iterator operator++(int);
			iterator operator--(int);
			iterator& operator++();
			iterator& operator--();
			inline int operator*();
			inline bool operator==(iterator other) {
				return (this->isAfterEnd == other.isAfterEnd) && (this->current == other.current);
			}
			inline bool operator!=(iterator other) { return !(*this == other); }
		private:
			Node* current;
			bool isAfterEnd;
			static Node* deepLeft(Node*);
			static Node* deepRight(Node*);
			friend class BSTree;
		};

	private:
		Node* root;
	};

	inline int BSTree::iterator::operator*() {
		if (isAfterEnd)
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
