#include <iostream>
using namespace std;

// Node struct
template <typename T>
struct Node {
	Node * left;
	Node * right;
	T datum;
}; // struct Node


// Returns true if the BST is empty
bool isEmpty (Node * root)
{
	if (root == nullptr)
	{
		return true;
	} //if

	return false;
} //isEmpty()


// Returns the size of the BST 
// NOTE: If root is a nullptr, returns 0
int treeSize(Node * root)
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
T maxValue(Node * root)
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
T minValue(Node * root)
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
template <typename T>
void insertNode(Node * root, T input)
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
template <typename T>
T treeSum(Node * root)
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
template <typename T>
T maxOfLeft(Node * root)
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
template <typename T>
T minOfRight(Node * root)
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
void printInOrder(Node * root)
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

/*
	Why/how does this Inorder print work?

	   The trick/key is to remember that since this is not tail recursion, every 
	recursive call creates a new stack frame/activation record on top of the stack. Additionally,
	remember that the stack is First In Last Out. 

		So, intially there is only one printInOrder() stack frame on the stack (this is 
	the stack frame made when the function is first called and root points to the root node). 
	The function is then stepped through as any non-recursive function would. However, as soon 
	as a recursive call is made (such as on line 187), another stack frame is created
	and put on top of the initial frame (for this stack frame, "root" actually points to
	root->left, the node to the left of root). This process will repeat, until eventually,
	a stack frame is added to the top of the stack where root actually points to "nullptr"
	(this is because the leftmost node's "left" pointer is equal to nullptr). 

		As this stack frame's instance of printInOrder() is stepped through, the first piece of 
	code it hits is the base case (which returns from the function). Since a return statement
	has been met, this function is done, and the stack frame is collapsed/thrown away/
	deleted. The stack frame that is now on the top of the stack, is the stack frame where 
	root points to the leftmost node of the BST. Remember that this function was being stepped
	through line-by-line, and it "paused" - so to speak - when the recursive call was made. 
	This "pause" happened when the recusive call was made (on line 187), and a new stack frame
	was created for the latest function call and that instance of the function began to be
	stepped through. Since that stack frame collapsed/was thrown away/deleted, the stack frame
	underneath it (the one that points to the leftmost node in the BST, in this case) picks up
	where it left off before it "paused." It continues through the function, printing its value, 
	and then it hits line 193 , which is another recursive call. Therefore, this same stack frame
	that was "paused" earlier (when the printInOrder(root->left) recursive call was made), gets
	"paused" again. Now, another stack frame is created on top of it. In this new stack frame,
	the "root" pointer actually points to nullptr (because it was the "right" pointer of the
	leftmost node in the BST, which points to nullptr). Since it points to nullptr, the first
	bit of code it hits when it steps through that instance of printInOrder() is the base
	case, which returns from the function, and collapses that stack frame. 

		Now, once again, we are back to the stack frame that was paused twice already 
	(the stack frame where root points to the leftmost node). It was last paused on line 
	193, when the printInOrder(root->right) recursive call was made. Therefore, it "unpauses"
	on the following line (194) and continues through the function. In this case, it unpauses at the 
	end of the function, and since this is a void function, there doesn't need to be a return
	statement. So, this stack frame is collapsed/thrown away/deleted. Now the stack frame 
	below it (the one whose "root" pointer points to the node whose "left" pointer points to the
	leftmost node) is the one whose function gets "unpaused." That instance of the function then
	continues to be stepped through line-by-line, printing its value and then "pausing" for a second
	time when the second recursive call: printInOrder(root->right) is made.
		
		This process then repeats until all of the stack frames for each of the printInOrder() function
	calls are collapsed.

*/