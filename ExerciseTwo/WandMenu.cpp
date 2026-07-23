#include "stdafx.h"
#include <iostream>

#include "DisplayDesign.h"
#include "InputWand.h"
#include "FilterWand.h"
#include "DisplayWand.h"
#include "DeleteWand.h"
#include "Wand.h"
#include "InputValidator.h"

using namespace std;

const int MINIMUM_SEARCH_WANDS = 3;

int GetMenuChoice();
void PrintMenuChoice();
void ShouldDeleteFilteredWands(list<Wand>& wandStorage, const list<Wand>& filteredWands);
void ShouldDeleteAllWands(list<Wand>& wandStorage);

void WandMenu(){
	list<Wand> wandStorage;
	list<Wand> filteredWands;

	bool isRunning = true;

	while (isRunning){
		
		DisplayDesignHeader("Wand Managment System");


		PrintMenuChoice();
		int choice = GetValidInteger("Enter a choice (0-4): ");

		switch (choice){
			case 0:
				cout << "Thank you for using the wand management system!";
				isRunning = false;
				break;

			case 1:
				InputWand(wandStorage);
				break;

			case 2:

				if(wandStorage.size() < MINIMUM_SEARCH_WANDS){
					DisplayDesignWarning("There must be atleast 3 wands to able to search through the list!");
					break;
				}

				filteredWands = FilterWand(wandStorage);
				DisplayWands(filteredWands);

				ShouldDeleteFilteredWands(wandStorage, filteredWands);
				break;

			case 3:
				DisplayWands(wandStorage);
				break;

			case 4:
				ShouldDeleteAllWands(wandStorage);
				break;

			default:
				DisplayDesignWarning("Invalid menu choice");
		
		}
	}
	


}

void PrintMenuChoice(){
	cout << "Pick a option from the following: " << endl;
	cout << "0: Exit App"<< endl;
	cout << "1: Add a Wand"<< endl;
	cout << "2: Search for a Wand" << endl;
	cout << "3: View all Wand" << endl;
	cout << "4: Delete all Wand"<< endl;
}

void ShouldDeleteFilteredWands(list<Wand>& wandStorage,const list<Wand>& filteredWands){
    char input;

    while (true)
    {
        cout << "Delete the searched wands? (Y/N): ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            DeleteAllWands(wandStorage);
            DisplayDesignWarning("All wands deleted successfully.");
            return;
        }

        if (input == 'N' || input == 'n'){
            return;
        }

        DisplayDesignWarning("Please enter Y or N.");
    }
}


void ShouldDeleteAllWands(list<Wand>& wandStorage){
    char input;

    while (true)
    {
        cout << "Delete the all wands? (Y/N): ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            DeleteAllWands(wandStorage);
            DisplayDesignWarning("Filtered wands deleted successfully.");
            return;
        }

        if (input == 'N' || input == 'n'){
            return;
        }

        DisplayDesignWarning("Please enter Y or N.");
    }
}