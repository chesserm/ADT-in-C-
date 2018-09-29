// Doubly Linked List Class Implementation
// Created by Matthew Chesser (github: chesserm)
// Note: This class works best for numerical data types.
//       Take caution when not using numerical data types.


template <typename T>
class DoublyLinkedList
{
private:
	struct Node
	{	
		// Data to be held in each node
		T datum;
		
		// Pointer to next node
		Node* next;

		// Pointer to prev node
		Node* prev;	
	}; //struct Node

	// Head (first) node in the doubly linked list
	Node * head;

	// Tail (last) node in the doubly linked list
	Node * tail;

	// Counter variable to track size of list
	// Without this,  returning the size would 
	// be O(n) time complexity
	int size;

public:

	// Constructor
	DoublyLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}


	// Copy constructor 
	DoublyLinkedList(const DoublyLinkedList<T> & right) : head{nullptr}, tail{nullptr}, size{0}
	{
		// Delete all nodes that exist in the copy
		deleteAll();

		// Copy all nodes from original to copy
		copyAll(right);
	} //copy ctor


	// Overloading assignment operator
	DoublyLinkedList & operator=(const DoublyLinkedList<T> & right)
	{
		// Check if we're trying to self-assign
		if (this == &right)
		{
			return *this;
		} //if

		deleteAll();
		copyAll(right);

		return *this;
	} //operator=()
	

	// Adds a node to the doubly linked list
	// Adds to the end by default
	void addNode(T input)
	{
		Node * temp = new Node;
		temp->datum = input;
		temp->next = nullptr;

		// Checking if list is empty
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			temp->prev = nullptr;
		} //if
		else
		{
			// There is at least one Node in the list
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		} //else

		++size;
	} //addNode()
	

	// Helper function to copy all nodes from original
	// list to copy list
	void copyAll(const List<T> & original)
	{
		// Deep copy all nodes from the original
		for (Node * it = original.head; it; it = it->next)
		{
			addNode(it->datum);
		} //for

	} //copyAll()


	// Inserts a Node after the specified Node
	// REQUIRES: the Node: insertNodeAfter, must be a valid Node and belong to a linked list
	void insertNodeAfter(Node * insertNodeAfter, T input)
	{
		Node * temp = new Node;
		temp->datum = input;

		temp->prev = insertNodeAfter;
		temp->next = insertNodeAfter->next;
		insertNodeAfter->next = temp;

		++size;

	} //insertNodeAfter()


	// Returns the size of the list
	// This is made much easier by the included size variable
	int getSize()
	{
		return size;
	} //getSize()


	// Returns a Node pointer to the Head node
	// Will return nullptr if the list is empty
	Node * getHead()
	{
		return head;
	} //getHead()


	// Returns a Node poitner to the tail node
	// Will return nullptr if the list is empty
	Node * getTail()
	{
		return tail;
	} //getTail()


	// Returns true if the list is empty
	// and false if the list is not empty
	bool isEmpty()
	{
		return head == nullptr;
	} //isEmpty()


	// Returns the max value in the list
	// Note: Does not return a pointer to the node containing
	//       the max value, but just the value itself
	T & maxValue()
	{
		// This process is the same for single or doubly linked lists
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

		// Iterate through and find the max value
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


	// Returns the min value in the list
	// Note: Does not return a pointer to the node containing
	//       the min value, but just the value itself
	T & minValue()
	{
		// This process is the same for single or doubly linked lists
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

		// Iterate through and find the max value
		while (it != nullptr)
		{
			if (it->datum < minValue)
			{
				minValue = it->datum;
			} //if

			it = it->next;
		} //while

		return minValue;
	} //minValue()


	// Prints the list
	void printList()
	{
		Node * it = head;

		std::cout << "NULL <--> ";
		while (it != nullptr)
		{
			std::cout << it->datum << " <--> ";
		} //while

		std::cout << " NULL\n"; 
	} //printList()


	// Deletes the specified node from the list
	// REQUIRED: nodeToDelete is a valid node in the list
	void deleteNode(Node * nodeToDelete)
	{

		// Edge case where nodeToDelete is only node in the list
		if (nodeToDelete == head && nodeToDelete == tail)
		{
			delete nodeToDelete;
			head = nullptr;
			tail = nullptr;
		} //if

		// Case where nodeToDelete is the head node
		if (nodeToDelete == head)
		{
			// Node to delete is the head node

			head = head->next;
			head->prev = nullptr;

			nodeToDelete->next = nullptr;
			delete nodeToDelete;
		} //if
		else if (nodeToDelete == tail)
		{
			// Node to delete is the tail node

			tail = tail->prev;
			tail->next = nullptr;

			nodeToDelete->prev = nullptr;
			delete nodeToDelete;
		} //else if
		else
		{
			// All other cases
			nodeToDelete->prev->next = nodeToDelete->next;
			nodeToDelete->next->prev = nodeToDelete->prev;

			nodeToDelete->next = nullptr;
			nodeToDelete->prev = nullptr;

			delete nodeToDelete;
		} //else

		--size;

	} //nodeToDelete()


	// Deletes all nodes in the list
	void deleteAll()
	{
		// Deletes all nodes in the list
		while (!isEmpty())
		{
			deleteNode(front);
		} //while

	} //deleteAll()


	// Destructor
	~DoublyLinkedList()
	{
		deleteAll();
	} //dtor

}; //DoublyLinkedList class