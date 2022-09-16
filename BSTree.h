#pragma once
#include <stack>

namespace BinSearchTree {

	class BSTree {
	public:
		class Iterator;

		BSTree(int);
		~BSTree();
		const Iterator& getBegin();
		void insert(int);

		class Node {
		public:
			int value;
			Node(int);
			~Node();
		private:
			friend class BSTree;
			friend class Iterator;
			Node* link[2];
			unsigned int height;
		};

		class Iterator {
		public:
			Iterator(BSTree&);
			~Iterator();
			void operator++();
			void operator--();
			Node& operator*() const;
			bool isLast();
			bool isFirst();
		private:
			friend class BSTree;
			Node* cur;
			std::stack<Node*>* forwardStack;
			std::stack<Node*>* backwardStack;
			Node* deepLeft(Node*);
			Node* deepRight(Node*);
		};

	private:
		friend class Iterator;
		Node* root;
		Iterator* begin;
		unsigned int height(Node*);
		void insert(Node*, Node**);
	};

}
