#include "stdafx.h"
#include <iostream>

#include "InputWand.h"
#include "FilterWand.h"
#include "DisplayWand.h"
#include "Wand.h"

using namespace std;

int getMenuChoice();
void printMenuChoice();

void WandMenu(){
	list<Wand> wandStorage;

	bool isRunning (true);

	while (isRunning){
		int choice = getMenuChoice();

	switch (choice){
		case 0:
			cout << "Thank you for using the wand management system!";
			isRunning = false;
			break;
		case 1:
			InputWand(wandStorage);
			break;
		case 2:
			FilterWand(wandStorage);
			break;
		case 3:
			DisplayWands(wandStorage);
			break;
		default:
			cout << "Enter a valid option" << endl;
		
	}
	}
	


}

int getMenuChoice(){
   int input;
   while (true){

	   printMenuChoice();
	   cin >> input;

	   if(input >= 0 && input <= 3){
			return input;
	   }

	   cout << "Invalid menu choice" << endl;
   }

}

void printMenuChoice(){
	cout << endl << "Pick a option from the following: " << endl;
	cout << "Enter 1: Add a Wand"<< endl;
	cout << "Enter 2: Search for a Wand" << endl;
	cout << "Enter 3: View all Wand" << endl;
	cout << "Enter choice: ";
}