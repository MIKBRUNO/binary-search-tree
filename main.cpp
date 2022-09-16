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
	BSTree tree(0);
	BSTree::Iterator* iter = new BSTree::Iterator(tree.getBegin());  // not begin but satcks are empty
	tree.insert(-3);
	tree.insert(-5);
	tree.insert(-1);
	tree.insert(-4);
	tree.insert(-2);
	tree.insert(2);
	tree.insert(1);
	tree.insert(4);
	tree.insert(3);
	tree.insert(5);

	cout << (*(*iter)).value;
	cout << (*tree.getBegin()).value;

	delete iter;
	
	return 0;
}