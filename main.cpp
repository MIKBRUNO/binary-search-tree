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
	BSTree::iterator iter1 = tree.begin();
	BSTree::iterator iter3 = tree.begin();
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
	BSTree::iterator begin = tree.begin();
	BSTree::iterator end = tree.end();

	BSTree::iterator iter2 = tree.begin();
	cout << *iter2 << ' ';
	while (iter2 != end) {
		iter2++;
		cout << *iter2 << ' ';
	}
	cout << '\n' << *iter1 << ' ';
	while (iter1 != end) {
		iter1++;
		cout << *iter1 << ' ';
	}
	cout << '\n' << *iter3 << ' ';
	while (iter3 != begin) {
		iter3--;
		cout << *iter3 << ' ';
	}
	cout << '\n' << *iter2 << ' ';
	while (iter2 != begin) {
		iter2--;
		cout << *iter2 << ' ';
	}
	
	return 0;
}