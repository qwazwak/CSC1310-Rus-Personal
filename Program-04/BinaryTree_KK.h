/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Rus Hoffman                                                      *
 *     Date:    December 4, 2018                                                   *
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

		void destroySubTree();

		void insert(BinaryTree_kk* insertMe);

		unsigned long long getTotal();
		void leastPatties(string & nameOfMin, long long & eatenOfMin);
		void mostPatties(string & nameOfMax, long long & eatenOfMax);

		void streamOutInorder(ostream& stream = cout);
		long long getEatenByName(string nameKey);

	public:

		BinaryTree_kk(string inputName, long long inputEaten);

		~BinaryTree_kk();

//Getters and Setters

		void setEaten(long long input);
		void setName(string input);
		long long getEaten();
		string getName();

		void setLeft(BinaryTree_kk* nodeToSet);
		void setRight(BinaryTree_kk* nodeToSet);
		BinaryTree_kk* getLeft();
		BinaryTree_kk* getRight();

//Node helping
		int getNumChildren();
		BinaryTree_kk* getOnlyChild();
		bool hasLeft();
		bool hasRight();

		void destroyEntireRight();
		void destroyEntireLeft();

//Node adding
		void createAndAddNode(string inputName, long long inputEaten);
		void insertNode(BinaryTree_kk* insertMe);

//Stats:
		unsigned long long getTotalEaten();
		void getLeastNumPatties(string & nameOfMin, long long & eatenOfMin);
		void getMaxNumPatties(string & nameOfMax, long long & eatenOfMax);

		BinaryTree_kk* getSmallestNode();
		BinaryTree_kk* getLargestNode();

//Tools:

		void displayInOrder(ostream& stream = cout);

		long long searchNode(string nameKey);

		BinaryTree_kk* getSecondSmallestNode();
		BinaryTree_kk* getSecondLargestNode();

		BinaryTree_kk* findParentOfNode(BinaryTree_kk* childAddress);

		bool removeNode(string nameKey) {
			//If this is the node to remove (only useful for root node) do special stuff because it cannot be deleted, but changed
			if(strcasecmp(nameKey.c_str(), this->getName().c_str()) == 0) {
				if(this->getNumChildren() == 0) {
					string errorString = "ERROR: CANNOT REMOVE SINGLE NODE TREE";
					throw(errorString);
					return false;
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
					delete filler;
				}
				else if(this->getNumChildren() == 1) {
					BinaryTree_kk* childBackup = this->getOnlyChild();
					this->setLeft(childBackup->getLeft());
					this->setRight(childBackup->getRight());
					this->setName(childBackup->getName());
					this->setEaten(childBackup->getEaten());
					childBackup->setRight(nullptr);
					childBackup->setLeft(nullptr);
					delete childBackup;
				}
				return true;

			}
			else {
				//I am not to be removed, check children
				//case of 2 children
				if(this->hasRight() && this->hasLeft()) {
					//Key is on right
					if(strcasecmp(nameKey.c_str(), this->getName().c_str()) >= 0) {
						if(strcasecmp(nameKey.c_str(), this->getRight()->getName().c_str()) == 0) {
							//REMOVE THE RIGHT CHILD
							//save the one to remove
							BinaryTree_kk* buffer = this->getRight();
							//make it not part of the main tree
							this->setRight(nullptr);
							//if it has children, bring them in
							if(buffer->hasRight()) {
								this->insertNode(buffer->getRight());
							}
							if(buffer->hasLeft()) {
								this->insertNode(buffer->getLeft());
							}
							//remove links to its children and delete the node
							buffer->setLeft(nullptr);
							buffer->setRight(nullptr);
							delete buffer;
							return true;
						}
						else {
							return this->getRight()->removeNode(nameKey);
						}

					}
					//key is on left
					else {

						if(strcasecmp(nameKey.c_str(), this->getLeft()->getName().c_str()) == 0) {
							//REMOVE THE LEFT CHILD
							//save the one to remove
							BinaryTree_kk* buffer = this->getLeft();
							//make it not part of the main tree
							this->setLeft(nullptr);
							//if it has children, bring them in
							if(buffer->hasRight()) {
								this->insertNode(buffer->getRight());
							}
							if(buffer->hasLeft()) {
								this->insertNode(buffer->getLeft());
							}
							//remove links to its children and delete the node
							buffer->setLeft(nullptr);
							buffer->setRight(nullptr);
							delete buffer;
							return true;
						}
						else {
							return this->getLeft()->removeNode(nameKey);
						}
					}
				}
				//case of one child
				else if(this->hasRight() != this->hasLeft()) {
					if(strcasecmp(nameKey.c_str(), this->getOnlyChild()->getName().c_str()) == 0) {
						//save the one to remove
						BinaryTree_kk* buffer = this->getOnlyChild();
						//make it not part of the main tree
						this->setLeft(nullptr);
						this->setRight(nullptr);
						//if it has children, bring them in
						if(buffer->hasRight()) {
							this->insertNode(buffer->getRight());
						}
						if(buffer->hasLeft()) {
							this->insertNode(buffer->getLeft());
						}
						//remove links to its children and delete the node
						buffer->setLeft(nullptr);
						buffer->setRight(nullptr);
						delete buffer;
						return true;
					}
					else {
						return this->getOnlyChild()->removeNode(nameKey);
					}

				}
				//case of no children
				else {
					return false;
				}
			}

		}
};


#endif
