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
		T datum;
		Node * next;
	}; // struct Node
	
	Node* head; 
	Node *tail;
	int size;

public:

	// Constructor
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	} //LinkedList() ctor


	//Copy Constructor
	LinkedList()
	{

	} //copy ctor

	// Adds a node to the linked list
	// By default, the node is added to the back of the list
	void addNode(T input)
	{
		Node * temp = new Node;
		temp->datum = input;
		temp->next = nullptr; 
		
		// Case where Linked List is empty
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		} //if
		else
		{
			this->tail->next = temp;
			this->tail = temp;
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
		if (this->tail == afterThisNode)
		{
			this->tail = temp;
		} //if

		++size;
	} //insertNode()


	// Prints the linked list
	void printList()
	{
		Node * temp = this->head;

		
		while (temp != nullptr)
		{
			std::cout << temp->datum << " ---> ";
			temp = temp->next;
		} //while

		std::cout << "NULL\n";

	} //printList()


	// Checks to see if the linked list is empty
	bool isEmpty()
	{
		return this->head == nullptr;
	} //isEmpty()


	// Returns the size of the linked list
	// By keeping a member variable, size, this is much easier than iteration/recusion
	int getSize()
	{
		return this->size;
	} //getSize()


	// Returns a pointer to the head Node of the linked list
	Node * getHead()
	{
		return this->head;
	} //getHead()


	// Deletes a specified Node from the linked list
	// REQUIRED: nodeToDelete points to a Node within the linked list
	void deleteNode(Node * nodeToDelete)
	{
		if(nodeToDelete == this->head)
		{
			// The nodeToDelete is the head node
			// If the linked list only contains one node, head will now point to nullptr
			this->head = this->head->next;
			nodeToDelete->next = nullptr;
			delete nodeToDelete;

		} //if 
		else if (nodeToDelete == this->tail)
		{
			// The node to delete is the tail node

			// traverse LL to find node before tail
			Node * it = this->head;
			while (it->next != this->tail)
			{
				it = it->next;
			}

			//it should now point to the Node before tail
			it->next = nullptr;

			//Move tail one node back
			this->tail = it;

			delete nodeToDelete;


		} //else if (nodeToDelete == tail)
		else
		{
			// All other cases, where the nodeToDelete isn't the head or tail

			// Traverse LL to make it point to the node before nodeToDelete
			Node *it = this->head;
			while (it->next != nodeToDelete)
			{
				it = it->next;
			}

			// it should now point to the node before nodeToDelete
			it->next = nodeToDelete->next;

			nodeToDelete->next = nullptr;

			delete nodeToDelete;

		} //else

		--size;
	} //deleteNode()


	// Returns the max value in the linked list
	// Note: This does not return a pointer to the node with the max value,
	//      just the value itself. Additionally, this works best for numerical
	//      data types
	T maxValue()
	{
		Node * it = this->head;
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
	T minValue()
	{
		Node * it = this->head;
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
		// Two pointers act as iterators through the linked list
		// Two are used to avoid losing our position after each delete
		Node * temp = this->head;
		node * current = this->head;

		this->head = nullptr;
		this->tail = nullptr;

		// Iterate through and delete all nodes
		while (temp != nullptr)
		{
			temp = current->next;
			current->next = nullptr;
			delete current;
			current = temp;
		} //while

	} //dtor

}; //LinkedList class

