/*
 * Title:  LinkedList.h
 * Author:  April Crockett, modified by Rus Hoffman
 * Date:  2/4/2018
 * Purpose:  A template class which implements a singly-linked list.
 */
namespace qLib {
#if !defined(LINKEDLIST_HPP)
#define LINKEDLIST_HPP

#include <iostream>
#if __cplusplus >= 201103L
#include <chrono>
#include <random>
#else
#include <cstdlib>
#endif
	using namespace std;

	template<typename T> class LinkedListPlus {
		private:
			struct ListNode {
					T value;
					struct ListNode *next;
			};
			ListNode *head;
			ListNode *tail;
			size_t numNodes;

		public:
			LinkedListPlus() {
				head = NULL;
				tail = NULL;
				numNodes = 0;
			}

			LinkedListPlus(T* array, size_t size) {
				head = NULL;
				tail = NULL;
				numNodes = 0;
				for(size_t i = 0; i < size; i++){
					this->appendNode(array[i]);
				}
			}

			~LinkedListPlus();

			size_t getLength();

			T getNodeValue(size_t);

			void setNodeValue(size_t, T);

			void appendNode(T);

			void insertNode(T, size_t);

			void deleteNode(size_t);

			void swapNodes(size_t, size_t);

			void shuffle();
	};

	template<typename T> size_t LinkedListPlus<T>::getLength() {
		return numNodes;
	}

//returns the node value at a given position
	template<typename T>
	T LinkedListPlus<T>::getNodeValue(size_t position) {
		ListNode *nodePtr;
		nodePtr = head;
		size_t currentPos = 0;

		while (position >= currentPos) {
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;
		}
	}
	
	template<typename T>
	void LinkedListPlus<T>::setNodeValue(size_t position, T newValue) {
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
	template<typename T> void LinkedListPlus<T>::appendNode(T nodeValue) {
		ListNode *newNode;     // To point to a new node
		ListNode *nodePtr;     // To move through the list
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
		else     // Otherwise, insert newNode at end.
		{
			//set the current last node's next pointer to the new node
			tail->next = newNode;

			//now the tail is the new node
			tail = newNode;
		}
	}

	template<typename T> void LinkedListPlus<T>::insertNode(T nodeValue, size_t iPos) {
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
	void LinkedListPlus<T>::deleteNode(size_t position) {
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
	template<typename T> LinkedListPlus<T>::~LinkedListPlus() {
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

	template<typename T> void LinkedListPlus<T>::swapNodes(size_t nodeA, size_t nodeB) {
		T buf = this->getNodeValue(nodeA);
		this->setNodeValue(nodeA, this->getNodeValue(nodeB));
		this->setNodeValue(nodeA, buf);
	}

	template<typename T> void LinkedListPlus<T>::shuffle() {
		T* shuffledOrderArray = new T[this->numNodes];
		size_t remainingIndexs = this->numNodes;
		size_t* indexPossibles = new size_t[remainingIndexs];
		for (size_t i = 0; i < remainingIndexs; i++) {
			indexPossibles[i] = i;
		}
#if __cplusplus >= 201103L
		random_device realRandom;
		mt19937 randomGenerator(realRandom.entropy() == 0 ? std::chrono::system_clock::now().time_since_epoch().count() : realRandom());
#else
		srand(time(NULL));
#endif
size_t indexToClear;
		for (size_t i = 0; i < this->numNodes; i++) {
#if __cplusplus >= 201103L
			indexToClear = randomGenerator() % remainingIndexs--;
#else
			indexToClear = rand() % remainingIndexs--;
#endif
			shuffledOrderArray[indexPossibles[i]] = this->getNodeValue(this->numNodes - i);
			this->deleteNode(this->numNodes - i);
			for(size_t r = indexToClear; r < this->numNodes - 1; r++){
				indexPossibles[r] = indexPossibles[r+1];
			}
		}
		for(size_t i = indexToClear; i < this->numNodes; i++){
			this->appendNode(shuffledOrderArray[i]);
		}
		delete[] shuffledOrderArray;
		delete[] indexPossibles;
	}

#endif
}
