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
	BSTree::iterator iter1 = tree.getBegin();
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

	BSTree::iterator iter2 = tree.getBegin();
	cout << *iter2 << ' ';
	while (!iter2.isLast()) {
		iter2++;
		cout << *iter2 << ' ';
	}
	cout << '\n' << *iter1 << ' ';
	while (!iter1.isLast()) {
		iter1++;
		cout << *iter1 << ' ';
	}
	
	return 0;
}