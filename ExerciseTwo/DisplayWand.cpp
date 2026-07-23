#include "stdafx.h"
#include <iostream>
#include <list>

#include "DisplayDesign.h"
#include "Wand.h"
#include "InputWand.h"

using namespace std;

void PrintLine();
void PrintHeaders(int size);
void PrintBody(list<Wand>& wandStorage);
void PrintWand(const Wand& wand, int index);

void DisplayWands(list<Wand>& wandStorage){
	DisplayDesignHeader("View All Wands");

	PrintHeaders(wandStorage.size());
	PrintBody(wandStorage);
}

void PrintHeaders(int size){
	cout << "We found " << size << " wands!" << endl << endl;
}

void PrintBody(list<Wand>& wandStorage){
	int index = 1;

	list<Wand>::const_iterator wands;
	for(wands = wandStorage.begin() ; wands != wandStorage.end(); ++wands){
		PrintWand(*wands,index);
		++index;
	}
}

void PrintWand(const Wand& wand, int index){
	cout << "Wand " << index << endl;
	cout << "Length: " << wand.lengthInInches << " inches" << endl;
	cout << "Core: " << wand.core << endl;
	cout << "Wood: " << wand.woodType << endl << endl;
}