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
	BinarySearchTree(const BinarySearchTree<T> & right) : root{nullptr}, size{0} 
	{
		// Deleting all nodes in the tree that will become a copy (just in case)
		deleteAllNodes(root);
		// Copy all nodes from the original to the copy
		copyAllNodes(right.root);

	} //copy ctor


	// Overriding assignment operator
	BinarySearchTree & operator=(const BinarySearchTree<T> & original)
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
	size_t treeSize()
	{
		return size;
	} //treeSize()


	// Returns the largest value in the BST by reference
	// NOTE: This is just the value of the node furthest to the right in the BST
	T & maxValue(Node * input)
	{
		// Edge case (empty BST)
		if (!input)
		{
			return 0;
		} //if

		// Base case
		if (!input->right)
		{
			return input->datum;
		} //if base case

		// Recursive Call
		return maxValue(input->right);

	} //maxValue()


	// Returns the smallest value in the BST by reference
	// NOTE: This is just the value of the node furthest left in the BST
	T & minValue(Node * input, T input)
	{
		// Edge case (empty BST)
		if (!input)
		{
			return 0;
		} //if

		// Base case
		if (!input->left)
		{
			return input->datum;
		} //if base case


		// Recursive Call
		return minValue(input->left);

	} //minValue()


	// Inserts a node into the BST with the specified input value
	void insertNode(Node * nodeIn, T input)
	{
		// Base case
		if (!nodeIn)
		{
			nodeIn = new Node;
			nodeIn->datum = input;

		} //if
	
		// Insert to the left if the value is less than the current node
		if (input < nodeIn->datum)
		{
			insertNode(nodeIn->left, input);
		} //if
		// Otherwise insert to the right
		else if (input > nodeIn->datum)
		{
			insertNode(nodeIn->right, input);
		} //else if

		// Increment size
		++size;
	} //insertNode()


	// Helper function for copy constructor and assignment operator overload
	void copyAllNodes(Node * input)
	{
		// Edge Case where root is nullptr
		if (!input)
		{
			return;
		} //if

		// Traverse left and add each node
		if (input->left)
		{
			insertNode(input->datum);
			copyAllNodes(input->left);
		} //if

		// Traverse right and add each node
		if (input->right)
		{
			copyAllNodes(input->right);
			insertNode(input->datum);
		}

	} //copyAllNodes()

	// Returns the sum of the tree
	// NOTE: This function is only really useful if the data type 
	//       stored in each node is numerical.
	T treeSum(Node * input)
	{
		// Edge case
		if (!input)
		{
			return 0;
		} //if

		//Base case (found a leaf node)
		if (!input->right && !input->left)
		{
			return input->datum;
		} //if

		// Recursive call to return the sum of the left and 
		// right branches of the root node
		return treeSum(input->left) + treeSum(input->right);
	} //treeSum()


	// Returns the max value of the left side of the BST by reference
	T & maxOfLeft(Node * input)
	{
		// Edge Case
		if (!input)
		{
			return 0;
		} //if

		// Edge Case where only node in BST is the root
		if (!input->left)
		{
			return 0;
		} //if

		// By passing the node to the left of the root node
		// we are finding the max of the subtree where the
		// the first left node from the root is the root of the
		// subtree.
		return maxValue(input->left);
	} //maxOfLeft()


	// Returns the min value of the right side of the BST by reference
	T & minOfRight(Node * input)
	{
		// Edge Case
		if (!input)
		{
			return 0;
		} //if


		// Edge case where only one node is in the BST
		if (!input->right)
		{
			return 0;
		} //if

		// By passing the node to the right of the root node
		// we are finding the min of the subtree where the
		// the first right node from the root is the root of the
		// subtree.
		return minValue(input->right);

	} //minOfRight()


	// Prints the BST in in-order traversal
	// Note: If this function is confusing, see the file
	// 		 BST Recursion Explained.txt
	void printInOrder(Node * input)
	{
		// Base Case
		if (!input)
		{
			return;
		} //if

		// Recurse to the left children
		printInOrder(input->left);

		// Print values
		cout << input->datum << " ";

		// Recurse to right children
		printInOrder(input->right);

	} //printBST()


	// Prints the BST in pre-order traversal
	void printPreOrder(Node * input)
	{
		// Base case
		if (!input)
		{
			return;
		} //if

		// Traversing to the left of the subtree
		if (input->left)
		{
			std::cout << input->datum << " "; 
			printPreOrder(input->left);
		} //if

		// Traversing to the right of the subtree
		if (input->right)
		{
			std::cout << input->datum << " ";
			printInOrder(input->right);
		} //if

		// Flush stream
		std::cout << std::endl;

	} //printPreOrder()


	// Helper function to delete the BST
	void deleteAllNodes(Node * input)
	{
		// Base case
		if (!input)
		{
			return;
		} //if
		
		deleteAllNodes(input->left);
		deleteAllNodes(input->right);
		
		input->left = nullptr;
		input->right = nullptr;
		delete input;

	} //deleteNode()


	// Destructor
	~BinarySearchTree()
	{
		deleteAllNodes(root);
	} //dtor

}; //BinarySearchTree class

