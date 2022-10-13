/*
			6									0
		  -	  -								  -	  -		
		-		8							-		2	
	  -		  -   -						  -		  -   -		
	3		7		10					-3		1		4	
  -	  -			  -	  -				  -	  -			  -	  -	
1		5		9	   11			-5		-1		3	   5
 -     -							 -      -				
  2	  4								 -4	   -2			
*/
#include <iostream>
#include "BSTree.h"

using std::cout;
using BinSearchTree::BSTree;

int main() {
	{
		BSTree tree;
	}

	BSTree tree;
	auto null_iter = tree.begin();
	null_iter = tree.end();
	++null_iter;
	--null_iter;
	tree.insert(0);
	BSTree::iterator iter3 = tree.begin();
	++iter3;
	--iter3;
	tree.insert(-3);
	tree.insert(-5);
	cout << *(--tree.end()) << std::endl;
	tree.insert(-1);
	tree.insert(-4);
	tree.insert(-2);
	cout << *(--tree.end()) << std::endl;
	tree.insert(2);
	tree.insert(1);
	tree.insert(4);
	cout << *(--tree.end()) << std::endl;
	tree.insert(3);
	tree.insert(5);
	BSTree::iterator begin = tree.begin();

	BSTree::iterator iter2 = tree.begin();
	while (iter2 != tree.end()) {
		cout << *iter2 << ' ';
		iter2++;
	}
	cout << '\n';
	do {
		iter2--;
		cout << *iter2 << ' ';
	} while (iter2 != tree.begin());
	cout << '\n';
	while (iter3 != tree.end()) {
		cout << *iter3 << ' ';
		iter3++;
	}
	
	return 0;
}