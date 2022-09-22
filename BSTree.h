#pragma once
#include <stack>

namespace BinSearchTree {

	class BSTree {
	public:
		class iterator;

		BSTree(int);
		~BSTree();
		iterator getBegin();
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
#if 0
			iterator operator--(int);
#endif
			int operator*();
			bool operator==(iterator);
			bool operator!=(iterator);
			bool isLast() ;
			bool isFirst();
		private:
			friend class BSTree;
			iterator();
			Node* cur;
			Node* deepLeft(Node*);
			Node* deepRight(Node*);
		};

	private:
		Node* root;
		iterator begin;
		unsigned int height(Node*);
		void insert(Node*, Node*);
	};

}
