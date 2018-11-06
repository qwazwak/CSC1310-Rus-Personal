/*
 * Title:  LinkedList.h
 * Author:  April Crockett, modified by Rus Hoffman
 * Date:  2/4/2018
 * Purpose:  A template class which implements a singly-linked list.
 */

#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template<typename T> class LinkedList {
	private:
		struct ListNode {
				T value;
				struct ListNode *next;
		};
		ListNode *head;
		ListNode *tail;
		size_t numNodes;

	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			numNodes = 0;
		}

		~LinkedList();

		size_t getLength();

		T getNodeValue(size_t);

		void setNodeValue(size_t, T);

		void appendNode(T);

		void insertNode(T, size_t);

		void deleteNode(size_t);

		void swapNodes(size_t, size_t);

		void shuffleNodes();
};

template<typename T> size_t LinkedList<T>::getLength() {
	return numNodes;
}

//returns the node value at a given position
template<typename T>
T LinkedList<T>::getNodeValue(size_t position) {
	ListNode *nodePtr;
	nodePtr = head;
	size_t currentPos = 0;
	while (position >= currentPos) {
		if(position == currentPos) {
			return nodePtr->value;
		}
		currentPos++;
		nodePtr = nodePtr->next;
	}
	return NULL;
}

template<typename T>
void LinkedList<T>::setNodeValue(size_t position, T newValue) {
	ListNode* nodePtr = head;
	size_t currentPos = 0;
	while (position >= currentPos) {
		if(position == currentPos) {
			nodePtr->value = newValue;
			return;
		}
		currentPos++;
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// appendNode appends a node containing the        *
// value passed into nodeValue, to the end of the list.   *
//**************************************************
template<typename T> void LinkedList<T>::appendNode(T nodeValue) {
	ListNode *newNode;     // To point to a new node
	//ListNode *nodePtr;     // To move through the list
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if(!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		// Otherwise, insert newNode at end.
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

template<typename T> void LinkedList<T>::insertNode(T nodeValue, size_t iPos) {
	ListNode *newNode;     // To point to a new node
	ListNode *nodePtr;     // To move through the list
	ListNode *previousNode;
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if(!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		// Otherwise, insert newNode at position.
		size_t pos = 0;
		nodePtr = head;
		
		if(iPos == 0) {
			//insert at beginning of list
			newNode->next = head;
			head = newNode;
			return;
		}
		if(iPos >= this->getLength() - 1) {
			//insert at end
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			return;
		}
		while (iPos != pos) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			pos++;
		}
		
		newNode->next = nodePtr;
		previousNode->next = newNode;
	}
}
//**************************************************
// The deleteNode function finds the node with the argument position & deletes it
//**************************************************
template<typename T>
void LinkedList<T>::deleteNode(size_t position) {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;     // To point to the previous node

	// Determine if the first node is the one.
	if(position == 0) {
		nodePtr = head->next;
		delete head;
		--numNodes;
		head = nodePtr;
	}
	else {
		// Initialize nodePtr to head of list
		nodePtr = head;
		size_t ptrPosition = 0;

		// Skip all nodes whose value member is not equal to the sent position.
		while (ptrPosition != position) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			ptrPosition++;
		}

		// If nodePtr is not at the end of the list, link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if(nodePtr == tail)
			tail = previousNode;
		
		previousNode->next = nodePtr->next;
		delete nodePtr;
		--numNodes;
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
template<typename T> LinkedList<T>::~LinkedList() {
	ListNode *nodePtr;     // To traverse the list
	ListNode *nextNode;     // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;
		--numNodes;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

template<typename T> void LinkedList<T>::swapNodes(size_t nodeA, size_t nodeB) {
	T buf = this->getNodeValue(nodeA);
	this->setNodeValue(nodeA, this->getNodeValue(nodeB));
	this->setNodeValue(nodeA, buf);
}

template<typename T> void LinkedList<T>::shuffleNodes() {
	srand(time(NULL));
	size_t randBuffer;
	size_t sizeLimit = this->getLength();
	for (int i = sizeLimit - 1; i > 0; i--) {
		// Pick a random index from 0 to i
		randBuffer = rand() % (i + 1);

		// Swap arr[i] with the element at random index
		this->swapNodes(i, randBuffer);
	}

	/*
	 size_t indexPossibilitiesLeft = this->getLength();
	 size_t* indexPossibilitiesGenerator = new size_t[this->getLength()];
	 for (size_t i = 0; i < this->getLength(); i++) {
	 indexPossibilitiesGenerator[i] = i;
	 }

	 #if defined(DEBUG)
	 clog << "Filled Buffer Array" << endl;
	 #endif
	 size_t* indexToPlace_A = new size_t[this->getLength()];
	 size_t* indexToPlace_B = new size_t[this->getLength()];




	 for (size_t i = 0; i < this->getLength(); i++) {
	 #if defined(DEBUG)
	 clog << "rand() loop" << endl;
	 #endif
	 randBuffer = rand();
	 indexToPlace_A[i] = indexPossibilitiesGenerator[randBuffer % indexPossibilitiesLeft];
	 indexToPlace_B[i == 0 ? this->getLength() - 1 : i - 1] = indexToPlace_A[i];
	 for (size_t randRemover = randBuffer; randRemover + 1 < indexPossibilitiesLeft; randRemover++) {
	 indexPossibilitiesGenerator[randRemover] = indexPossibilitiesGenerator[randRemover + 1];
	 }
	 --indexPossibilitiesGenerator;
	 }
	 delete[] indexPossibilitiesGenerator;


	 for (size_t i = 0; i < this->getLength(); i++) {
	 #if defined(DEBUG)
	 clog << "swap" << endl;
	 clog << long(indexToPlace_A[i]) << "," << long(indexToPlace_A[i] == 0 ? this->getLength() - 1 : indexToPlace_A[i] - 1) << endl;
	 #endif
	 this->swapNodes(indexToPlace_A[i], indexToPlace_A[i] == 0 ? this->getLength() - 1 : indexToPlace_A[i] - 1);
	 }
	 delete[] indexToPlace_A;
	 delete[] indexToPlace_B;
	 */
}

#endif
