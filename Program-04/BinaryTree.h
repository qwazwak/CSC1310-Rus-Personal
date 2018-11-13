/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Rus Hoffman                                                      *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#if !defined(BINARYTREE_H)
#define BINARYTREE_H

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
class BTNode {
	private:
		size_t ID;
		size_t hash;
		string name;
		size_t kpEat;
		BTNode* leftNode;
		BTNode* rightNode;

		void updateHash() {
			std::hash<string> hash_fn;
			string tempString(ID);
			this->hash = hash_fn(name + tempString);
		}
	public:

		BTNode() {
			this->name = "";
			this->kpEat = -1;
			this->hash = NULL;
			this->leftNode = nullptr;
			this->rightNode = nullptr;
		}
		BTNode(string nameNew, size_t kpEatNew) {
			this->name = nameNew;
			this->kpEat = kpEatNew;
			updateHash();
			this->leftNode = NULL;
			this->rightNode = NULL;
		}
		string getName() {
			return this->name;
		}
		string getEaten() {
			return this->kpEat;
		}
		BTNode* getSmallerSide() {
			return this->leftNode;
		}
		BTNode* getLargerSide() {
			return this->rightNode;
		}
		void smartInsert(BTNode* insertMe) {
			if(strcmp(insertMe->getName().c_str(), this->name.c_str()) >= 0) {
				if(this->rightNode == nullptr) {
					rightNode = insertMe;
				}
				else {
					this->rightNode->smartInsert(insertMe);
				}
			}
			else {
				if(this->leftNode == nullptr) {
					leftNode = insertMe;
				}
				else {
					this->leftNode->smartInsert(insertMe);
				}
			}
		}
		size_t getNumberNodes(){
			return 1 + (leftNode == nullptr ? 0 : this->leftNode->getNumberNodes()) + (rightNode == nullptr ? 0 : this->rightNode->getNumberNodes());
		}
};

class BinaryTree {
	private:
		BTNode* rootNode;
		size_t treeSize;

	public:
		BinaryTree() {
			this->rootNode = new BTNode;
			this->treeSize = 1;
		}
		BinaryTree(BTNode* defaultTree) {
			this->rootNode = defaultTree;
			this->treeSize = defaultTree->getNumberNodes();
		}

		void addNode(BTNode* insertMe) {
			this->rootNode->smartInsert(insertMe);
			this->treeSize++;
		}

		void removeNode() {
			this->rootNode->smartInsert(insertMe);
			this->treeSize++;
		}

};

#endif
