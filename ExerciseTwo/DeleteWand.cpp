#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <iostream>
#include <algorithm>

#include "DisplayDesign.h"
#include "Wand.h"
#include "DeleteWand.h"

using namespace std;

bool IsSameWand(const Wand& firstWand, const Wand& secondWand) ;

void DeleteFilteredWandsFromStorage(list<Wand>& wandStorage, const list<Wand>& filteredWands){

	list<Wand>::const_iterator filteredWand;
	for(filteredWand = filteredWands.begin(); filteredWand != filteredWands.end(); ++filteredWand){

		list<Wand>::iterator wand;
		for(wand = wandStorage.begin(); wand != wandStorage.end(); ++wand){
			
			if (IsSameWand(*wand, *filteredWand)){
				wandStorage.erase(wand);
				break;
			}
		}
	}
}

bool IsSameWand(const Wand& firstWand, const Wand& secondWand){
    return firstWand.lengthInInches == secondWand.lengthInInches && firstWand.core == secondWand.core && firstWand.woodType == secondWand.woodType;
}

void DeleteAllWands(list<Wand>& wandStorage){
	wandStorage.clear();
}