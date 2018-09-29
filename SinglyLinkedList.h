// Linked List class
// Created by Matthew Chesser (github: chesserm)
// Note: This linked list does not have a representation
//		 invariant that it must be sorted.

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		// Template variable to hold the value
		T datum;

		// Pointer to point to the next node in the list
		Node * next;
	}; // struct Node
	
	// Pointer to head (first) node
	Node* head; 
	// Pointer to tail (last) node
	Node *tail;

	// Variable to hold size of linked list
	// Without this variable, finding size
	// would take O(n) time complexity
	int size;

public:

	// Constructor
	LinkedList() : head{nullptr}, tail{nullptr}, size{0} {}


	//Copy Constructor
	LinkedList(const List<T> & right) : head{nullptr}, tail{nullptr}, size{0}
	{
		// Delete every node that in the list that will become a copy
		deleteAll();

		// Copy all nodes over to the new copy list
		copyAll(right);

	} //copy ctor


	// Overloading the assignment operator
	LinkedList &operator=(const LinkedList<T> &right)
	{
		// Check to see if we're trying to do a self assignment
		if (this == &right)
		{
			return *this;
		} //if

		// Delete nodes
		deleteAll();

		// Copy all nodes over to the copy
		copyAll(right);

		return *this;
	} //&operator=()


	// Helper function to copy all nodes from the original list
	// to the new list (used for operator=() and copy ctor)
	void copyAll(const LinkedList<T> & original)
	{
		// Copy all the nodes from the original to the copy		
		for (Node * it = original.head; it; it = it->next)
		{
			addNode(it->datum);
		} //for

	} //copyAll()


	// Adds a node to the linked list
	// By default, the node is added to the back of the list
	void addNode(T input)
	{
		Node * temp = new Node;
		temp->datum = input;
		temp->next = nullptr; 
		
		// Case where Linked List is empty
		if (!head)
		{
			head = temp;
			tail = temp;
		} //if
		else
		{
			tail->next = temp;
			tail = temp;
		} //else

		++size;
	} //addNode()


	// Inserts a new Node after the specified Node
	//REQUIRES: afterThisNode is a valid Node in a linked list
	void insertNode(Node * afterThisNode, T input)
	{
		Node * temp = new Node;
		temp->datum = input;

		temp->next = afterThisNode->next;
		afterThisNode->next = temp;

		// Case where the node to insert after is the tail node
		if (tail == afterThisNode)
		{
			tail = temp;
		} //if

		++size;
	} //insertNode()


	// Prints the linked list
	void printList()
	{
		Node * temp = head;

		// Print all nodes in the list
		while (temp)
		{
			std::cout << temp->datum << " ---> ";
			temp = temp->next;
		} //while

		std::cout << "NULL" << std::endl;

	} //printList()


	// Checks to see if the linked list is empty
	bool isEmpty()
	{
		return head == nullptr;
	} //isEmpty()


	// Returns the size of the linked list
	// By keeping a member variable, size, this is much easier than iteration/recusion
	int getSize()
	{
		return size;
	} //getSize()


	// Returns a pointer to the head Node of the linked list
	Node * getHead()
	{
		return head;
	} //getHead()


	// Returns a pointer to the tail Node of the list
	Node * getTail()
	{
		return tail;
	} //getTail()


	// Deletes a specified Node from the linked list
	void deleteNode(Node * nodeToDelete)
	{

		// Edge case where node to delete points to a nullptr
		if (!nodeToDelete)
		{
			return;
		} //if

		// Edge case, where node to delete is the only node in the list
		if (nodeToDelete == head && nodeToDelete == tail)
		{
			delete nodeToDelete;
			head = nullptr;
			tail = nullptr;
		} //if

		// If the node to delete is the head node
		if(nodeToDelete == head)
		{
			// The nodeToDelete is the head node
			// If the linked list only contains one node, head will now point to nullptr
			head = head->next;
			nodeToDelete->next = nullptr;
			delete nodeToDelete;

		} //if 
		// The node to delete is the tail node
		else if (nodeToDelete == tail)
		{
			// traverse LL to find node before tail
			Node * it = head;
			while (it->next != tail)
			{
				it = it->next;
			}

			//it should now point to the Node before tail
			it->next = nullptr;

			//Move tail one node back
			tail = it;

			delete nodeToDelete;


		} //else node is not the tail or head node
		else
		{
			// Traverse LL to make it point to the node before nodeToDelete
			Node *it = head;
			while (it->next != nodeToDelete)
			{
				it = it->next;
			}

			// it should now point to the node before nodeToDelete
			it->next = nodeToDelete->next;

			nodeToDelete->next = nullptr;

			delete nodeToDelete;

		} //else

		// Decrement size by one
		--size;
	} //deleteNode()


	// Delete all the nodes in the list
	void deleteAll()
	{
		// While the list isn't empty delete the head node
		while(!isEmpty())
		{
			deleteNode(head);
		} //while

	} //deleteAll()


	// Returns the max value in the linked list
	// Note: This does not return a pointer to the node with the max value,
	//      just the value itself. Additionally, this works best for numerical
	//      data types
	T & maxValue()
	{
		Node * it = head;
		T maxValue;

		// Checking the edge case where the list is empty
		if (it == nullptr)
		{
			// This is the value I am choosing to return when the list is 
			// empty. Since, this class will mostly be used for numerical 
			// data types it should be fine. If need be, I will come back
			// and change it to a more suitable value.
			maxValue = -9999999;
		} //if
		else
		{
			maxValue = it->datum;
		} //else

		// Iterate through and find max value
		while (it != nullptr)
		{
			if (it->datum > maxValue)
			{
				maxValue = it->datum;
			} //if

			it = it->next;
		} //while

		return maxValue;
	} //maxValue()


	// Returns the min value in the linked list
	// Note: This does not return a pointer to the node with the min value,
	//      just the value itself. Additionally, this works best for numerical
	//      data types
	T & minValue()
	{
		Node * it = head;
		T minValue;

		// Checking the edge case where the list is empty
		if (it == nullptr)
		{
			// This is the value I am choosing to return when the list is 
			// empty. Since, this class will mostly be used for numerical 
			// data types it should be fine. If need be, I will come back
			// and change it to a more suitable value.
			minValue = -9999999;
		} //if
		else
		{
			minValue = it->datum;
		} //else

		// Iterating through to find min value
		while (it != nullptr)
		{
			if (it->datum < minValue)
			{
				minValue = it->datum;
			} //if

			it = it->next;
		} //while
	} //minValue()


	// Linked list destructor
	~LinkedList()
	{
		deleteAll();
	} //dtor

}; //LinkedList class

