/*********************************************************************************
 *     Title:   KrustyKrab.cpp                                                   *
 *     Author:  April Crockett, modified by Rus Hoffman                          *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is a program for Mr. Krabs at the Krusty Krab in beautiful  *
 *              Bikini Bottom!  The program allows you to choose from a menu     *
 *              of options:  enter customer data, remove customer data, print    *
 *              statistics, and search for a customer's data.  This data in this *
 *              program is stored in a Binary Search Tree.                       *
 *********************************************************************************/

#include <iostream>

#include "BinaryTree_KK.h"
using namespace std;

int main() {
	long long choice;
	string name;
	long long numKrabbyPatties;
	long long total;
	
	//LOOK!!!  Create a BinaryTree object.
	BinaryTree_kk* krustyKrabBT = nullptr;
	
	cout << "\n\n_  _   ____   _  _    ___   _____  _  _     _  _   ____     _    ___  \n";
	cout << ") |) / /  _ \\ ) () (  (  _( )__ __() () (   ) |) / /  _ \\   )_\\  \\  _)\n";
	cout << "| ( (  )  ' / | \\/ |  _) \\    | |  '.  /    | ( (  )  ' /  /( )\\ |  ( \n";
	cout << ")_|)_\\ |_()_\\ )____( )____)   )_(   /_(     )_|)_\\ |_()_\\ )_/ \\_(/__o)\n\n";
	
	do {
		cout << "Welcome to the Krusty Krab!\n";
		cout << "Choose one of the following options:\n";
		cout << "1.  Enter customer data.\n";
		cout << "2.  Remove a customer's data.\n";
		cout << "3.  Get statistics on Krabby Patties.\n";
		cout << "4.  Search for a customer's data.\n";
		cout << "5.  End Program.\n";
		cout << "ENTER 1-5:  ";
		cin >> choice;
		
		while (cin.fail() || choice < 1 || choice > 5) {
			if(cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Invalid choice.  Please enter 1-5:  ";
			cin >> choice;
		}
		if(krustyKrabBT == nullptr && !(choice == 1 || choice == 5)) {
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "ERROR" << endl;
			cout << "You need to add customer's before doing that!" << endl;
		}
		else {
			switch (choice) {
				case 1:   //insert customer's data
					do {
						cout << "Enter a customer's name or -1 to quit entering data.\n";
						cout << "NAME:  ";
						cin.ignore();
						getline(cin, name);

						if(name != "-1") {
							cout << "NUMBER KRABBY PATTIES EATEN:  ";
							cin >> numKrabbyPatties;
							if(krustyKrabBT == nullptr) {
								krustyKrabBT = new BinaryTree_kk(name, numKrabbyPatties);
							}
							else {
								krustyKrabBT->createAndAddNode(name, numKrabbyPatties);
							}
							//LOOK!!  Call the insertNode BinaryTree member function here
							//See above code
						}
					}while (name != "-1");
					cout << endl;
					break;

				case 2:   //remove customer's data
					cout << "\n\nYou may remove the following customers:\n";
					//LOOK!!  Call the displayInOrder BinaryTree member function here
					krustyKrabBT->displayInOrder();

					cout << "\n\nEnter the name of the customer you wish to remove.\n";
					cout << "NAME:  ";
					cin.ignore();
					getline(cin, name);
					cout << endl;
					krustyKrabBT->removeNode(name);
					cout << endl;
					break;
					
				case 3:   //statistics
				
					//LOOK!!  Call the getLeastNumPatties BinaryTree member function here
					krustyKrabBT->getLeastNumPatties(name, numKrabbyPatties);

					cout << "\n\nLEAST NUMBER OF KRABBY PATTIES EATEN:  " << name << ", " << numKrabbyPatties << " Krabby Patties\n";

					//LOOK!!  Call the getMostNumPatties BinaryTree member function here
					krustyKrabBT->getMaxNumPatties(name, numKrabbyPatties);

					cout << "LARGEST NUMBER OF KRABBY PATTIES EATEN:  " << name << ", " << numKrabbyPatties << " Krabby Patties\n";

					//LOOK!!  Call the getTotalNumPatties BinaryTree member function here
					total = krustyKrabBT->getTotalEaten();

					cout << "TOTAL NUMBER OF KRABBY PATTIES EATEN:  " << total << endl << endl;
					break;

				case 4:   //search
					cout << "\n\nWhich customer are you looking for?\n";
					//LOOK!!  Call the displayInOrder BinaryTree member function here
					krustyKrabBT->displayInOrder();

					cout << "Enter the name of the customer.\n";
					cout << "NAME:  ";
					cin.ignore();
					getline(cin, name);

					//LOOK!!  Call the searchNode BinaryTree member function here
					numKrabbyPatties = krustyKrabBT->searchNode(name);

					if(numKrabbyPatties != -1)
						cout << "\n" << name << " ate " << numKrabbyPatties << " Krabby Patties\n\n";
					else
						cout << "\n" << name << " is not a customer of the Krusty Krab.\n";
					break;

				case 5:   //end
					cout << "\n\nGoodbye!\n\n";
			}
		}
	}while (choice != 5);
	
	return 0;
}
