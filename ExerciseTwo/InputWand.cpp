#include "stdafx.h"
#include <iostream>
#include <list>

#include "DisplayDesign.h"
#include "Wand.h"
#include "InputWand.h"
#include "InputValidator.h"

using namespace std;

void InputLength(Wand& wand);
void InputCore(Wand& wand);
void InputWoodType(Wand& wand);
void StoreIntoStorage(list<Wand>& wandStorage, Wand& wand);

void InputWand(list<Wand>& wandStorage){
	Wand wand;

	
	DisplayDesignHeader("Add Wand");
	InputLength(wand);
	InputCore(wand);
	InputWoodType(wand);
	StoreIntoStorage(wandStorage, wand);
}

void InputLength(Wand& wand){
	wand.lengthInInches = GetValidInteger("Input the inches of the wand: ");
}

void InputCore(Wand& wand){
	wand.core  = GetValidString("Input the core of the wand: ");
}

void InputWoodType(Wand& wand){
	wand.woodType  = GetValidString("Input the wood type of the wand: ");
}

void StoreIntoStorage(list<Wand>& wandStorage, Wand& wand){
	wandStorage.push_back(wand);
}