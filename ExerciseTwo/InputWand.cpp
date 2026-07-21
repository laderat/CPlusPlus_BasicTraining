#include "stdafx.h"
#include <iostream>
#include <list>

#include "Wand.h"
#include "InputWand.h"

using namespace std;

void InputLength(Wand& wand);
void InputCore(Wand& wand);
void InputWoodType(Wand& wand);
void StoreIntoStorage(list<Wand>& wandStorage, Wand& wand);

void InputWand(list<Wand>& wandStorage){
	Wand wand;

	InputLength(wand);
	InputCore(wand);
	InputWoodType(wand);
	StoreIntoStorage(wandStorage, wand);
}

void InputLength(Wand& wand){
	cout << endl << "Input the inches of the wand: ";
	cin >> wand.lengthInInches;
}

void InputCore(Wand& wand){
	cout << "Input the core of the wand: ";
	cin >> wand.core;
}

void InputWoodType(Wand& wand){
	cout << "Input the wood type of the wand: ";
	cin >> wand.woodType;
}

void StoreIntoStorage(list<Wand>& wandStorage, Wand& wand){
	wandStorage.push_back(wand);
}