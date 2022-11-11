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
#include <gtest/gtest.h>
#include "BSTree.h"

using BinSearchTree::BSTree;

TEST(TestBSTree, EmptyTreeTest) {
	BSTree tree;
	auto null_iter = tree.begin();
	ASSERT_THROW(*null_iter, std::logic_error);
	null_iter = tree.end();
	ASSERT_THROW(*null_iter, std::logic_error);
	ASSERT_TRUE(++null_iter == null_iter);
	ASSERT_TRUE(--null_iter == null_iter);
}

TEST(TestBSTree, BeginEndTest) {
	BSTree tree;
	tree.insert(0);
	BSTree::iterator iter3 = tree.begin();
	ASSERT_EQ(*iter3, 0);
	BSTree::iterator end = tree.end();
	ASSERT_THROW(*end, std::logic_error);
	++iter3;
	ASSERT_TRUE(iter3 == end);
	--iter3;	// return from after_end
	ASSERT_EQ(*iter3, 0);
	--iter3;	// tries to -- from only Node
	ASSERT_EQ(*iter3, 0);
	tree.insert(-3);
	ASSERT_EQ(*(--(tree.begin())), -3);
	ASSERT_EQ(*tree.begin(), -3);
	ASSERT_EQ(*(--tree.end()), 0);
	tree.insert(-5);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 0);
	tree.insert(-1);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 0);
	tree.insert(-4);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 0);
	tree.insert(-2);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 0);
	tree.insert(2);

	ASSERT_EQ(*(--end), 0);
	
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 2);
	tree.insert(1);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 2);
	tree.insert(4);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 4);
	tree.insert(3);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 4);
	tree.insert(5);
	ASSERT_EQ(*tree.begin(), -5);
	ASSERT_EQ(*(--tree.end()), 5);
}

TEST(TestBSTree, TraversalTest) {
	BSTree tree;
	tree.insert(0);
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

	BSTree::iterator iter2 = tree.begin();
	unsigned int i = *iter2;
	while (iter2 != tree.end()) {
		ASSERT_EQ(*iter2, i);
		iter2++;
		++i;
	}
	do {
		--i;
		iter2--;
		ASSERT_EQ(*iter2, i);
	} while (iter2 != tree.begin());
	i = *iter3;
	while (iter3 != tree.end()) {
		ASSERT_EQ(*iter3, i);
		iter3++;
		++i;
	}
	do {
		--i;
		iter3--;
		ASSERT_EQ(*iter3, i);
	} while (iter3 != tree.begin());
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}