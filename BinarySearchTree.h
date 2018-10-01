#include <iostream>
using namespace std;


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
	size_t size;
public:


	// Constructor
	BinarySearchTree() : root{nullptr}, size{0} {}


	// Copy Constructor (performs a deep copy)
	BinarySearchTree(const BinarySearchTree & right) : root{nullptr}, size{0} 
	{
		// Copy all nodes from the original to the copy
		copyAllNodes(right.root);

	} //copy ctor


	// Overriding assignment operator
	BinarySearchTree & operator=(const BinarySearchTree & original)
	{
		// Delete all nodes in the current tree
		deleteAllNodes(root);

		// Do a deep copy of all nodes from original to this tree
		copyAllNodes(original.root);

	} //operator=()

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
	size_t treeSize(Node * root)
	{
		return size;
	} //treeSize()


	// Returns the largest value in the BST by reference
	// NOTE: This is just the value of the node furthest to the right in the BST
	T & maxValue(Node * root)
	{
		// Edge case (empty BST)
		if (!root)
		{
			return 0;
		} //if

		// Base case
		if (!root->right)
		{
			return root->datum;
		} //if base case

		// Recursive Call
		return maxValue(root->right);

	} //maxValue()


	// Returns the smallest value in the BST by reference
	// NOTE: This is just the value of the node furthest left in the BST
	T & minValue(Node * root, T input)
	{
		// Edge case (empty BST)
		if (!root)
		{
			return 0;
		} //if

		// Base case
		if (!root->left)
		{
			return root->datum;
		} //if base case


		// Recursive Call
		return minValue(root->left);

	} //minValue()


	// Inserts a node into the BST with the specified input value
	void insertNode(Node * root, T input)
	{
		// Base case
		if (!root)
		{
			root = new Node;
			root->datum = input;

		} //if
	
		// Insert to the left if the value is less than the current node
		if (input < root->datum)
		{
			insertNode(root->left, input);
		} //if
		// Otherwise insert to the right
		else if (input > root->datum)
		{
			insertNode(root->right, input);
		} //else if

		// Increment size
		++size;
	} //insertNode()


	// Helper function for copy constructor and assignment operator overload
	void copyAllNodes(Node * root)
	{
		// Edge Case where root is nullptr
		if (!root)
		{
			return;
		} //if

		// Traverse left and add each node
		if (root->left)
		{
			insertNode(root->datum);
			copyAllNodes(root->left);
		} //if

		// Traverse right and add each node
		if (root->right)
		{
			copyAllNodes(root->right);
			insertNode(root->datum);
		}

	} //copyAllNodes()

	// Returns the sum of the tree
	// NOTE: This function is only really useful if the data type 
	//       stored in each node is numerical.
	T treeSum(Node * root)
	{
		// Edge case
		if (!root)
		{
			return 0;
		} //if

		//Base case (found a leaf node)
		if (!root->right && !root->left)
		{
			return root->datum;
		} //if

		// Recursive call to return the sum of the left and 
		// right branches of the root node
		return treeSum(root->left) + treeSum(root->right);
	} //treeSum()


	// Returns the max value of the left side of the BST by reference
	T & maxOfLeft(Node * root)
	{
		// Edge Case
		if (!root)
		{
			return 0;
		} //if

		// Edge Case where only node in BST is the root
		if (!root->left)
		{
			return 0;
		} //if

		// By passing the node to the left of the root node
		// we are finding the max of the subtree where the
		// the first left node from the root is the root of the
		// subtree.
		return maxValue(root->left);
	} //maxOfLeft()


	// Returns the min value of the right side of the BST by reference
	T & minOfRight(Node * root)
	{
		// Edge Case
		if (!root)
		{
			return 0;
		} //if


		// Edge case where only one node is in the BST
		if (!root->right)
		{
			return 0;
		} //if

		// By passing the node to the right of the root node
		// we are finding the min of the subtree where the
		// the first right node from the root is the root of the
		// subtree.
		return minValue(root->right);

	} //minOfRight()


	// Prints the BST in in-order traversal
	// Note: If this function is confusing, see the file
	// 		 BST Recursion Explained.txt
	void printInOrder(Node * root)
	{
		// Base Case
		if (!root)
		{
			return;
		} //if

		// Recurse to the left children
		printInOrder(root->left);

		// Print values
		cout << root->datum << " ";

		// Recurse to right children
		printInOrder(root->right);

	} //printBST()


	// Prints the BST in pre-order traversal
	void printPreOrder(Node * root)
	{
		// Base case
		if (!root)
		{
			return;
		} //if

		// Traversing to the left of the subtree
		if (root->left)
		{
			std::cout << root->datum << " "; 
			printPreOrder(root->left);
		} //if

		// Traversing to the right of the subtree
		if (root->right)
		{
			std::cout << root->datum << " ";
			printInOrder(root->right);
		} //if

		// Flush stream
		std::cout << std::endl;

	} //printPreOrder()


	// Helper function to delete the BST
	void deleteAllNodes(Node * root)
	{
		// Base case
		if (!root)
		{
			return;
		} //if
		
		deleteAllNodes(root->left);
		deleteAllNodes(root->right);
		
		root->left = nullptr;
		root->right = nullptr;
		delete root;

	} //deleteNode()


	// Destructor
	~BinarySearchTree()
	{
		deleteAllNodes(root);
	} //dtor

}; //BinarySearchTree class

