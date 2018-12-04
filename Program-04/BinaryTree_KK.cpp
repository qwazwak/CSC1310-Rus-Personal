/*********************************************************************************
 *     Title:   BinaryTree.cpp                                                   *
 *     Author:  Rus Hoffman                                                      *
 *     Date:    December 4, 2018                                                   *
 *     Purpose: This is the implementation file for the BinaryTree class, which  *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#include "BinaryTree_KK.h"

void BinaryTree_kk::destroySubTree() {
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

void BinaryTree_kk::insert(BinaryTree_kk* insertMe) {
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

unsigned long long BinaryTree_kk::getTotal() {
	return this->getEaten() + (this->hasLeft() ? this->getLeft()->getTotal() : 0) + (this->hasRight() ? this->getRight()->getTotal() : 0);
}

void BinaryTree_kk::leastPatties(string & nameOfMin, long long & eatenOfMin) {
	if(this->hasLeft()) {
		this->getLeft()->getLeastNumPatties(nameOfMin, eatenOfMin);
	}
	else {
		nameOfMin = this->getName();
		eatenOfMin = this->getEaten();
	}
}

void BinaryTree_kk::mostPatties(string & nameOfMax, long long & eatenOfMax) {
	if(this->hasRight()) {
		this->getRight()->getMaxNumPatties(nameOfMax, eatenOfMax);
	}
	else {
		nameOfMax = this->getName();
		eatenOfMax = this->getEaten();
	}
}

void BinaryTree_kk::streamOutInorder(ostream& stream) {
	if(this->leftNode != nullptr) {
		this->leftNode->streamOutInorder(stream);
	}
	stream << this->name << " -    " << this->eaten << "\n";
	if(this->rightNode != nullptr) {
		this->rightNode->streamOutInorder(stream);
	}
}

long long BinaryTree_kk::getEatenByName(string nameKey) {
	if(strcasecmp(nameKey.c_str(), this->getName().c_str()) == 0) {
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

BinaryTree_kk::BinaryTree_kk(string inputName, long long inputEaten) {
	this->name = inputName;
	this->eaten = inputEaten;
	this->rightNode = nullptr;
	this->leftNode = nullptr;
}

BinaryTree_kk::~BinaryTree_kk() {
	this->destroySubTree();
}

void BinaryTree_kk::setEaten(long long input) {
	this->eaten = input;
}

void BinaryTree_kk::setName(string input) {
	this->name = input;
}

long long BinaryTree_kk::getEaten() {
	return this->eaten;
}

std::__cxx11::string BinaryTree_kk::getName() {
	return this->name;
}

void BinaryTree_kk::setLeft(BinaryTree_kk* nodeToSet) {
	this->leftNode = nodeToSet;
}

void BinaryTree_kk::setRight(BinaryTree_kk* nodeToSet) {
	this->rightNode = nodeToSet;
}

BinaryTree_kk* BinaryTree_kk::getLeft() {
	return this->leftNode;
}

BinaryTree_kk* BinaryTree_kk::getRight() {
	return this->rightNode;
}

int BinaryTree_kk::getNumChildren() {
	return (this->hasLeft() ? 1 : 0) + (this->hasRight() ? 1 : 0);
}

BinaryTree_kk* BinaryTree_kk::getOnlyChild() {
	if(this->getNumChildren() > 1) {
		string errorString = "ERROR TRYING TO GET SINGLE CHILD WHEN TWO EXIST";
		throw(errorString);
		return nullptr;
	}
	return (this->hasRight() ? this->getRight() : this->getLeft());
}

unsigned long long BinaryTree_kk::getTotalEaten() {
	return this->getTotal();
}

void BinaryTree_kk::getLeastNumPatties(string & nameOfMin, long long & eatenOfMin) {
	this->leastPatties(nameOfMin, eatenOfMin);
}

void BinaryTree_kk::getMaxNumPatties(string & nameOfMax, long long & eatenOfMax) {
	this->mostPatties(nameOfMax, eatenOfMax);
}

BinaryTree_kk* BinaryTree_kk::getSmallestNode() {
	if(this->hasLeft() == false) {
		return this;
	}
	//else..
	return this->getLeft()->getSmallestNode();
}

BinaryTree_kk* BinaryTree_kk::getLargestNode() {
	if(this->hasRight() == false) {
		return this;
	}
	//else..
	return this->getRight()->getLargestNode();
}

void BinaryTree_kk::displayInOrder(ostream& stream) {
	this->streamOutInorder(stream);
}

long long BinaryTree_kk::searchNode(string nameKey) {
	return getEatenByName(nameKey);
}

BinaryTree_kk* BinaryTree_kk::getSecondSmallestNode() {
	if(this->hasLeft()) {
		if(this->getLeft()->hasLeft()) {
			return this->getLeft()->getSecondSmallestNode();
		}
		return this;
	}
	clog << "ERROR IN GETTING SECOND SMALLEST NODE, CANNOT DO IT" << endl;
	return nullptr;
}

BinaryTree_kk* BinaryTree_kk::getSecondLargestNode() {
	if(this->hasRight()) {
		if(this->getRight()->hasRight()) {
			return this->getRight()->getSecondLargestNode();
		}
		return this;
	}
	clog << "ERROR IN GETTING SECOND LARGEST NODE, CANNOT DO IT" << endl;
	return nullptr;
}

BinaryTree_kk* BinaryTree_kk::findParentOfNode(BinaryTree_kk* childAddress) {
	if(this->hasLeft()) {
		if(this->getLeft() == childAddress) {
			return this;
		}
		BinaryTree_kk* buffer = this->getLeft()->findParentOfNode(childAddress);
		if(buffer != nullptr) {
			return buffer;
		}
	}
	if(this->hasRight()) {
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

bool BinaryTree_kk::hasLeft() {
	return this->getLeft() != nullptr;
}

bool BinaryTree_kk::hasRight() {
	return this->getRight() != nullptr;
}

void BinaryTree_kk::destroyEntireRight() {
	delete this->getRight();
	this->setRight(nullptr);
}

void BinaryTree_kk::destroyEntireLeft() {
	delete this->getLeft();
	this->setLeft(nullptr);
}

void BinaryTree_kk::createAndAddNode(string inputName, long long inputEaten) {
	this->insertNode(new BinaryTree_kk(inputName, inputEaten));
}

void BinaryTree_kk::insertNode(BinaryTree_kk* insertMe) {
	this->insert(insertMe);
}
