#include <iostream>
using namespace std;

// Node struct
template <typename T>
class BinarySearchTree
{
private:
	struct Node {
		Node * left;
		Node * right;
		T datum;
	}; // struct Node

	Node * root;
public:


	// Constructor
	BinarySearchTree() : root(nullptr) {}


	// Returns true if the BST is empty
	bool isEmpty ()
	{
		if (root == nullptr)
		{
			return true;
		} //if

		return false;
	} //isEmpty()


	// Returns the size of the BST 
	// NOTE: If root is a nullptr, returns 0
	int treeSize()
	{
		// Edge case
		if (root == nullptr)
		{
			return 0;
		} //if

		// Base case
		if (root->left == nullptr && root->right == nullptr)
		{
			return 1;
		} //if

		// Recursive call
		return treeSize(root->left) + treeSize(root->right);
	} //treeSize()


	// Returns the largest value in the BST
	// NOTE: This is just the value of the node furthest to the right in the BST
	T maxValue()
	{
		// Edge case (empty BST)
		if (root == nullptr)
		{
			return 0;
		} //if

		// Base case
		if (root->right == nullptr)
		{
			return root->datum;
		} //if base case

		// Recursive Call
		return maxValue(root->right);

	} //maxValue()


	// Returns the smallest value in the BST
	// NOTE: This is just the value of the node furthest left in the BST
	T minValue()
	{
		// Edge case (empty BST)
		if (root == nullptr)
		{
			return 0;
		} //if

		// Base case
		if (root->left == nullptr)
		{
			return root->datum;
		} //if base case


		// Recursive Case
		return minValue(root->left);

	} //minValue()


	// Inserts a node into the BST with the specified input value
	void insertNode(T input)
	{
		// Base case
		if (root == nullptr)
		{
			root = new Node;
			root->datum = input;

		} //if
	
		if (input < root->datum)
		{
			insertNode(root->left, input);
		} //if
	
		insertNode(root->right, input);

	} //insertNode()


	// Returns the sum of the tree
	// NOTE: This function is only really useful if the data type 
	//       stored in each node is numerical.
	T treeSum()
	{
		// Edge case
		if (root == nullptr)
		{
			return 0;
		} //if

		//Base case
		if (root->right == nullptr && root->left == nullptr)
		{
			return root->datum;
		} //if

		return treeSum(root->left) + treeSum(root->right);
	} //treeSum()


	// Returns the max value of the left side of the BST
	T maxOfLeft()
	{
		// Edge Case
		if (root == nullptr)
		{
			return 0;
		} //if

		// Edge Case where only node in BST is the root
		if (root->left == nullptr)
		{
			return 0;
		} //if

		return maxValue(root->left);
	} //maxOfLeft()


	// Returns the min value of the right side of the BST
	T minOfRight()
	{
		// Edge Case
		if (root == nullptr)
		{
			return 0;
		} //if


		if (root->right == nullptr)
		{
			return 0;
		} //if


		return minValue(root->right);

	} //minOfRight()


	// Prints the BST
	// Note: If this function is confusing, see the file
	// 		 BST Recursion Explained.txt
	void printInOrder()
	{
		// Base Case
		if (root == nullptr)
		{
			return;
		} //if

		// Recurse to the left children
		printInOrder(root->left);

		// Print values
		cout << root->datum << "  \n";

		// Recurse to right children
		printInOrder(root->right);

	} //printBST()

}; //BinarySearchTree class

