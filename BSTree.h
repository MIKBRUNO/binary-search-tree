#pragma once
#include <stack>

namespace BinSearchTree {

	class BSTree {
	public:
		class iterator;

		BSTree(int);
		~BSTree();
		iterator begin();
		iterator end();
		void insert(int);

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
			unsigned int height;
		};

		class iterator {
		public:
			iterator(BSTree&);
			~iterator();
			iterator operator++(int);
			iterator operator--(int);
			int operator*();
			bool operator==(iterator);
			bool operator!=(iterator);
		private:
			friend class BSTree;
			Node* cur;
			Node* deepLeft(Node*);
			Node* deepRight(Node*);
		};

	private:
		Node* root;
		unsigned int height(Node*);
		void insert(Node*, Node*);
	};

}
