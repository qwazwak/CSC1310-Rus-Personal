/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Rus Hoffman                                                      *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#if !defined(BINARYTREE_KK_H)
#define BINARYTREE_KK_H

#include <iostream>
#include <string>
#include <string.h>
#include <utility>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Left is <
//right is >=

class BinaryTree_kk {
	private:
		string name;
		long long eaten;

		BinaryTree_kk* rightNode;
		BinaryTree_kk* leftNode;

		string to_lower(string str) {   // return string converted to lower case
			string returnMe = "";
			for (size_t i = 0; i < str.length(); i++) {
				returnMe += tolower(str.at(i));
			}
			return str;
		}

		void destroySubTree() {
			if(this->hasLeft()) {
				delete this->getLeft();
				this->leftNode = nullptr;
			}
			if(this->hasRight()) {
				delete this->getRight();
				this->rightNode = nullptr;
			}
			this->name = "";
			this->eaten = 0;
		}

		void insert(BinaryTree_kk* insertMe) {
			if(insertMe->hasLeft()) {
				this->insertNode(insertMe->getLeft());
				insertMe->destroyEntireLeft();
				insertMe->setLeft(nullptr);
			}
			if(insertMe->hasRight()) {
				this->insertNode(insertMe->getRight());
				insertMe->destroyEntireRight();
				insertMe->setRight(nullptr);
			}

			if(insertMe->getEaten() >= this->getEaten()) {
				//if(to_lower(insertMe->getName()) >= to_lower(this->getName())) {
				if(this->hasRight() == false) {
					this->rightNode = insertMe;
				}
				else {
					this->rightNode->insertNode(insertMe);
				}
			}
			else {
				if(this->hasLeft() == false) {
					this->leftNode = insertMe;
				}
				else {
					this->leftNode->insertNode(insertMe);
				}
			}
		}

		unsigned long long getTotal() {
			return this->getEaten() + (this->hasLeft() ? this->getLeft()->getTotal() : 0) + (this->hasRight() ? this->getRight()->getTotal() : 0);
		}
		void leastPatties(string *nameOfMin, long long *eatenOfMin) {
			if(this->hasLeft()) {
				this->getLeft()->getLeastNumPatties(nameOfMin, eatenOfMin);
			}
			else {
				nameOfMin = this->getName();
				eatenOfMin = this->getEaten();
			}
		}
		void mostPatties(string *nameOfMax, long long *eatenOfMax) {
			if(this->hasRight()) {
				this->getRight()->getMaxNumPatties(nameOfMax, eatenOfMax);
			}
			else {
				nameOfMax = this->getName();
				eatenOfMax = this->getEaten();
			}
		}

		void streamOutInorder(ostream& stream = cout) {
			if(this->leftNode != nullptr) {
				this->leftNode->streamOutInorder(stream);
			}
			stream << this->name << " -    " << this->eaten << "\n";
			if(this->rightNode != nullptr) {
				this->rightNode->streamOutInorder(stream);
			}
		}
		long long getEatenByName(string nameKey) {
			if(string(to_lower(nameKey)).compare(to_lower(this->getName()))) {
				return this->getEaten();
			}
			long long buffer;
			if(this->hasLeft()) {
				buffer = this->getLeft()->searchNode(nameKey);
				return (buffer != -1 ? buffer : -1);
			}
			if(this->hasRight()) {
				buffer = this->getRight()->searchNode(nameKey);
				return (buffer != -1 ? buffer : -1);
			}
			return -1;
		}

	public:

		BinaryTree_kk(string inputName, long long inputEaten) {
			this->name = inputName;
			this->eaten = inputEaten;
			this->rightNode = nullptr;
			this->leftNode = nullptr;
		}

		~BinaryTree_kk() {
			this->destroySubTree();
		}

//Getters and Setters

		void setEaten(long long input) {
			this->eaten = input;
		}
		void setName(string input) {
			this->name = input;
		}
		long long getEaten() {
			return this->eaten;
		}
		string getName() {
			return this->name;
		}

		void setLeft(BinaryTree_kk* nodeToSet) {
			this->leftNode = nodeToSet;
		}
		void setRight(BinaryTree_kk* nodeToSet) {
			this->rightNode = nodeToSet;
		}
		BinaryTree_kk* getLeft() {
			return this->leftNode;
		}
		BinaryTree_kk* getRight() {
			return this->rightNode;
		}

//Node helping
		int getNumChildren() {
			return (this->hasLeft() ? 1 : 0) + (this->hasRight() ? 1 : 0);
		}
		BinaryTree_kk* getOnlyChild() {
			if(this->getNumChildren() > 1) {
				string errorString = "ERROR TRYING TO GET SINGLE CHILD WHEN TWO EXIST";
				throw(errorString);
				return nullptr;
			}
			return (this->hasRight() ? this->getRight() : this->getLeft());
		}
		bool hasLeft() {
			return this->getLeft() != nullptr;
		}
		bool hasRight() {
			return this->getRight() != nullptr;
		}

		void destroyEntireRight() {
			delete this->getRight();
			this->setRight(nullptr);
		}
		void destroyEntireLeft() {
			delete this->getLeft();
			this->setLeft(nullptr);
		}

//Node adding
		void createAndAddNode(string inputName, long long inputEaten) {
			this->insertNode(new BinaryTree_kk(inputName, inputEaten));
		}
		void insertNode(BinaryTree_kk* insertMe) {
			this->insert(insertMe);
		}

//Stats:
		unsigned long long getTotalEaten() {
			return this->getTotal();
		}
		void getLeastNumPatties(string *nameOfMin, long long *eatenOfMin) {
			this->leastPatties(nameOfMin, eatenOfMin);
		}
		void getMaxNumPatties(string *nameOfMax, long long *eatenOfMax) {
			this->mostPatties(nameOfMax, eatenOfMax);
		}
//Tools:

		void displayInOrder(ostream& stream = cout) {
			this->streamOutInorder(stream);
		}

		long long searchNode(string nameKey) {
			return getEatenByName(nameKey);
		}

		BinaryTree_kk* getSecondSmallestNode() {
			if(this->hasLeft()){
				if(this->getLeft()->hasLeft()){
					return this->getLeft()->getSecondSmallestNode();
				}
				return this;
			}
			clog << "ERROR IN GETTING SECOND SMALLEST NODE, CANNOT DO IT" << endl;
			return nullptr;
		}
		BinaryTree_kk* getSecondLargestNode() {
			if(this->hasRight()){
				if(this->getRight()->hasRight()){
					return this->getRight()->getSecondLargestNode();
				}
				return this;
			}
			clog << "ERROR IN GETTING SECOND LARGEST NODE, CANNOT DO IT" << endl;
			return nullptr;
		}

		/*
		 You will also need a destructor, which will call a private function named destroySubTree.
		 The destroySubTree function should delete all nodes in the tree since they were dynamically allocated.
		 BINARY TREE OPERATIONS:
		 1. Insert a new node (requires two functions)
		 a. The public function (insertNode) should accept a new customer’s name and the number of Krabby Patties they ate.
		 This function should create a new TreeNode and fill it with these new values and then call the private function (insert).
		 b. The insert function (recursive function) inserts the node in the correct position.




		 2. Delete a node (requires three functions) a. The public function (remove) accepts a customer’s name in order to identify the node that should be removed.  This function prints, “You are trying to delete [name].”  This function will call the private deleteNode function (a recursive function). b. The deleteNode function tries to find the node that needs deleted.  If deleteNode finds the node, it calls the private makeDeletion function.  If deleteNode does not find the node, it should print “I’m sorry.  That customer can’t be found in the Krusty Krab.” c. The makeDeletion function removes the node and reattaches the branches of the tree below the node.




		 3. Display names of customers (requires two functions)
		 a. The public function (displayInOrder) will call the private overloaded function also called displayInOrder.
		 b. The private displayInOrder accepts a TreeNode as an argument and it is a recursive function which traverses the nodes using the inorder method and prints the customer’s name from each node.

		 4. Search for a customer
		 a. The searchNode function accepts the customer’s name as an argument and then it will look at each node (traverse the tree) to find the node with that name.
		 If the name is found, the function returns the number of Krabby Patties that customer ate.  If not, then it will return -1 instead.

		 5. Find the lowest number of Krabby Patties eaten by any customer (requires two functions) a. The public function (getLeastNumPatties) accepts two arguments – a string that will eventually hold the customer’s name that has the least number of eaten Krabby Patties and an integer that will eventually hold the customer’s # of eaten Krabby Patties.  This function sets the integer parameter (leastPatties) to the root node’s # of patties and then calls the private function (getLeast). b. The getLeast function is a recursive function that traverses the nodes like the displayInOrder function except instead of printing out the customer’s name, it will check to see if the current node has a smaller number then the one saved in the leastPatties variable.  If so, then save this node’s customer name & number of patties as the new least.

		 6. Find the highest number of Krabby Patties eaten by any customer (requires two functions) a. Follow the instructions for finding the lowest except find the highest instead

		 7. Find the total number of Krabby Patties eaten by ALL customers (requires two functions)
		 a. The public function (getTotalNumPatties) accepts no arguments.
		 It reates a variable to hold the total and then calls the private getTotal function, sending the root node & the total variable (send total by reference) to the function.
		 Then, this function will return the total as an integer.
		 b. The getTotal function is a recursive function that traverses the tree like the displayInOrder function except instead of printing out the customer’s name, it will get a running total of Krabby Patties eaten from each node.
		 */
		void removeSingleRight() {

			this->findParentOfNode(this->getRight()->getSmallestNode())->destroyEntireRight();
		}
		void removeSingleLeft() {
			this->findParentOfNode(this->getLeft()->getSmallestNode())->destroyEntireLeft();
		}

		BinaryTree_kk* findParentOfNode(BinaryTree_kk* childAddress) {
			if(this->getLeft() != nullptr) {
				if(this->getLeft() == childAddress) {
					return this;
				}
				BinaryTree_kk* buffer = this->getLeft()->findParentOfNode(childAddress);
				if(buffer != nullptr) {
					return buffer;
				}
			}
			if(this->getRight() != nullptr) {
				if(this->getRight() == childAddress) {
					return this;
				}
				BinaryTree_kk* buffer = this->getRight()->findParentOfNode(childAddress);
				if(buffer != nullptr) {
					return buffer;
				}
			}
			return nullptr;
		}





		BinaryTree_kk* getSmallestNode() {
			return (this->getLeft() != nullptr ? this->getLeft()->getSmallestNode() : this);
		}
		BinaryTree_kk* getLargestNode() {
			return (this->getRight() != nullptr ? this->getRight()->getLargestNode() : this);
		}

		bool removeNode(string &nameKey) {
			transform(nameKey.begin(), nameKey.end(), nameKey.begin(), ::tolower);
			string stringComparisonBuffer = this->getName();
			//am i the node
			transform(stringComparisonBuffer.begin(), stringComparisonBuffer.end(), stringComparisonBuffer.begin(), ::tolower);
			if(nameKey.compare(stringComparisonBuffer) == 0) {
				if(this->getNumChildren() == 0) {
					string errorString = "ERROR: CANNOT REMOVE SINGLE NODE TREE";
					throw(errorString);
				}
				else if(this->getNumChildren() == 2) {
					BinaryTree_kk* filler = this->getRight();
					BinaryTree_kk* parent = this;
					while (filler->getLeft() != nullptr) {
						parent = filler;
						filler = filler->getLeft();
					}
					this->setName(filler->getName());
					this->setEaten(filler->getEaten());
					parent->setLeft(nullptr);
				}
				else if(this->getNumChildren() == 1) {
					BinaryTree_kk* childBackup = this->getOnlyChild();
					this->setLeft(childBackup->getLeft());
					this->setRight(childBackup->getRight());
					this->setName(childBackup->getName());
					this->setEaten(childBackup->getEaten());
				}
				return true;
			}
			else {
				//I am not to be removed, check children

				if(this->getRight() != nullptr) {
					stringComparisonBuffer = this->getRight()->getName();
					transform(stringComparisonBuffer.begin(), stringComparisonBuffer.end(), stringComparisonBuffer.begin(), ::tolower);
					if(nameKey.compare(stringComparisonBuffer) == 0) {
						BinaryTree_kk* childBackup = this->getRight();
						this->setRight(nullptr);
						if(childBackup->getLeft() != nullptr) {
							this->insertNode(childBackup->getLeft());
						}
						if(childBackup->getRight() != nullptr) {
							this->insertNode(childBackup->getRight());
						}
						childBackup->setLeft(nullptr);
						childBackup->setRight(nullptr);
						delete childBackup;
						return true;
					}

				}
				if(this->getLeft() != nullptr) {
					stringComparisonBuffer = this->getLeft()->getName();
					transform(stringComparisonBuffer.begin(), stringComparisonBuffer.end(), stringComparisonBuffer.begin(), ::tolower);
					if(nameKey.compare(stringComparisonBuffer) == 0) {
						BinaryTree_kk* childBackup = this->getLeft();
						this->setLeft(nullptr);
						if(childBackup->getLeft() != nullptr) {
							this->insertNode(childBackup->getLeft());
						}
						if(childBackup->getRight() != nullptr) {
							this->insertNode(childBackup->getRight());
						}
						childBackup->setLeft(nullptr);
						childBackup->setRight(nullptr);
						delete childBackup;
						return true;
					}

				}
				//We know that WE are not the data, and each child isnt, now recursivly check each
				bool miniReturn = this->getLeft()->removeNode(name);
				if(miniReturn == false) {
					miniReturn = this->getRight()->removeNode(name);
				}
				return miniReturn;
			}
		}
};
#endif
