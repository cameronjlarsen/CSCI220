/*
	Program: LinkedBinaryTreeTest
	Author:	Cameron Larsen
	Course: CSCI 220 - Data Structures
	Date: 11/25/2020
	Description: Program show casing an implementation of a 
	Linked Binary Tree using a Position class to access a Node struct
	and a LinkedBinaryTree class to insert an element at a Position in the tree.
	A list of elements at each position in the tree is print to the console in
	preorder, postorder, and inorder traversals.

	I certify that the following code is my own work.

	Exception(s): N/A
*/
#include <iostream>
#include "LinkedBinaryTree.h"

using Position = LinkedBinaryTree::Position;
int main()
{
	// create tree and position pointer to root
	LinkedBinaryTree tree;
	LinkedBinaryTree::Position p = tree.root();

	// insert element "A" at root
	tree.insert("A", p);

	// insert elements "B" & "C" at root's("A") left and right
	tree.insertLeft("B", p);
	tree.insertRight("C", p);

	// move p to "B"
	p = p.left();
	// insert elements "D" & "E" at "B"'s left and right
	tree.insertLeft("D", p);
	tree.insertRight("E", p);

	// move p to "E"
	p = p.right();
	// insert element "G" at "E"'s left
	tree.insertLeft("G", p);
	
	// move p back to root
	p = tree.root();
	// move p to "C"
	p = p.right();
	// insert element "F" at "C"'s right 
	tree.insertRight("F", p);

	// print tree size and position list by each traversal option
	std::cout << "Tree size: " << tree.size() << "\n";
	std::cout << "Preorder print: "; tree.print("preorder");
	std::cout << "\nPostorder print: "; tree.print("postorder");
	std::cout << "\nInorder print: "; tree.print("inorder");
	
}