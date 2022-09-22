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
			bool isLast() ;
			bool isFirst();
		private:
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
