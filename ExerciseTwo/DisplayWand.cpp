#include "stdafx.h"
#include <iostream>
#include <list>

#include "Wand.h"
#include "InputWand.h"

using namespace std;

void PrintLine();
void PrintHeaders(int size);
void PrintBody(list<Wand>& wandStorage);

void DisplayWands(list<Wand>& wandStorage){
	PrintLine();

	PrintHeaders(wandStorage.size());
	PrintBody(wandStorage);

	PrintLine();

}

void PrintLine(){
	cout << endl << "=============================================================================================" << endl << endl;
}

void PrintHeaders(int size){
	cout << "We found " << size << " wands!" << endl;
}

void PrintBody(list<Wand>& wandStorage){
	list<Wand>::const_iterator wands;
	int index = 1;
	for(wands = wandStorage.begin() ; wands != wandStorage.end(); ++wands){

		cout << "Wand" << index << endl;
		cout << "Length: " << wands->lengthInInches << " inches" << endl;
		cout << "Core: " << wands->core << endl;
		cout << "Wood: " << wands->woodType << endl << endl;

		++index;
	}
}