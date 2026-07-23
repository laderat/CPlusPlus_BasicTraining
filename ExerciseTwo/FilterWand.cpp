#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <iostream>

#include "DisplayDesign.h"
#include "Wand.h"
#include "FilterWand.h"
#include "WandFilterTypes.h"
#include "WandFilterCriterion.h"
#include "InputValidator.h"

using namespace std;

list<WandFilterCriterion> CreateCriteriaList();

WandFilterCriterion CreateFilter();
int GetFilterChoice();
WandFilterCriterion CreateFilterByLength();
int GetDesiredLengthToFilter();
WandFilterOperation GetLengthOperationChoice();
WandFilterCriterion CreateFilterByCore();
WandFilterCriterion CreateFilterByWoodType();
WandFilterOperation GetTextOperationChoice();

bool ShouldCreateAnotherFilter();

list<Wand> ApplyFilters(list<Wand>& wandStorage, list<WandFilterCriterion>& criteriaList);
bool MatchesCriteria(const Wand& wand,const WandFilterCriterion& criteria);
bool MatchesLength(const Wand& wand, const WandFilterCriterion& criteria);
bool MatchesText(const string& value, const WandFilterCriterion& criteria);

list<Wand> FilterWand(list<Wand>& wandStorage){
	DisplayDesignHeader("Search Wands");
	list<WandFilterCriterion> criteriaList = CreateCriteriaList();
	
	return ApplyFilters(wandStorage, criteriaList);
}

list<WandFilterCriterion> CreateCriteriaList(){
	list<WandFilterCriterion> criteriaList;

	bool isRunning = true;

	while (isRunning){
		
		WandFilterCriterion criterion = CreateFilter();
		criteriaList.push_back(criterion);
		
		isRunning = ShouldCreateAnotherFilter();
	}

	return criteriaList;
}

bool ShouldCreateAnotherFilter(){
	char input;

	cout << "Enter Y if you wish to continue creating a filter: ";
	cin >> input;

	return input == 'Y' || input == 'y';
}



WandFilterCriterion CreateFilter(){
	int choice;

	choice = GetFilterChoice();

	switch (choice){
		case 1:
			return CreateFilterByLength();

		case 2:
			return CreateFilterByCore();

		case 3:
			return CreateFilterByWoodType();

		default:
			DisplayDesignWarning("Enter the valid choice");
			return CreateFilter();
	}
}

int GetFilterChoice(){
	string filterChoiceMessage = "Enter Choice: ";

	cout << "Enter corresponding number to add a filter: " << endl;
	cout << "Enter 1 = Add filter for wand length "<< endl;
	cout << "Enter 2 = Add filter for wand core "<< endl;
	cout << "Enter 3 = Add filter for wand wood type"<< endl;

	return GetValidInteger(filterChoiceMessage);
}


WandFilterCriterion CreateFilterByLength(){
	WandFilterCriterion criteria;

	criteria.field = FilterByLength;
	criteria.numberValue = GetDesiredLengthToFilter();
	criteria.operation = GetLengthOperationChoice();

	return criteria;
}

int GetDesiredLengthToFilter(){
	string desiredLengthMessage = "\nEnter the desired length to find: ";

	return GetValidInteger(desiredLengthMessage);
}

WandFilterOperation GetLengthOperationChoice(){
	string operationChoiceMessage = "\nEnter the desired operation: ";

	cout << "Enter 1 = Equal" << endl;
	cout << "Enter 2 = GreaterThan" << endl; 
	cout << "Enter 3 = LessThan" << endl;

	while(true){
		int operationChoice = GetValidInteger(operationChoiceMessage);
		switch (operationChoice){
				case 1:
					return OperationEqual;
				case 2:
					return OperationGreaterThan;
				case 3:
					return OperationLessThan;
				default:
					DisplayDesignWarning("Enter the valid operation choice");
		}
	}
}


WandFilterCriterion CreateFilterByCore(){
	WandFilterCriterion criteria;

	criteria.field = FilterByCore;
	
	criteria.textValue = GetValidString("\nEnter the desired core to find: ");

	criteria.operation = GetTextOperationChoice();
	return criteria;
}


WandFilterCriterion CreateFilterByWoodType(){
	WandFilterCriterion criteria;

	criteria.field = FilterByWoodType;
	
	criteria.textValue = GetValidString("\nEnter the desired wood type to find: ");

	criteria.operation = GetTextOperationChoice();

	return criteria;
}

WandFilterOperation GetTextOperationChoice(){
	string operationChoiceMessage = "Enter the desired operation: ";

	cout << "Enter 1 = Equal" << endl;
	cout << "Enter 2 = Contains" << endl; 

	while(true){
		int operationChoice = GetValidInteger(operationChoiceMessage);
		switch (operationChoice){
				case 1:
					return OperationEqual;
				case 2:
					return OperationContains;
				default:
					DisplayDesignWarning("Enter the valid operation choice");
		}
	}
}

list<Wand> ApplyFilters(list<Wand>& wandStorage, list<WandFilterCriterion>& criteriaList){
	list<Wand> filteredWands;

	list<Wand>::const_iterator wand;
	for(wand = wandStorage.begin(); wand != wandStorage.end(); ++wand){
		
		bool matchedAllCriteria = true;

		list<WandFilterCriterion>::const_iterator criteria;
		for(criteria = criteriaList.begin(); criteria != criteriaList.end(); ++criteria){

			if(!MatchesCriteria(*wand, *criteria)){
				matchedAllCriteria = false;
				break;
			}
		}

		if(matchedAllCriteria){
			filteredWands.push_back(*wand);
		}
	}

	return filteredWands;
}

bool MatchesCriteria(const Wand& wand, const WandFilterCriterion& criteria){

	switch (criteria.field){
		case FilterByLength:
			return MatchesLength(wand, criteria);

		case FilterByCore:
			return MatchesText(wand.core, criteria);

		case FilterByWoodType:
			return MatchesText(wand.woodType, criteria);

		default:
			return false;
	}
}

bool MatchesLength(const Wand& wand, const WandFilterCriterion& criteria){

	switch (criteria.operation){
		case OperationEqual:
			return wand.lengthInInches == criteria.numberValue;

		case OperationGreaterThan:
			return wand.lengthInInches > criteria.numberValue;

		case OperationLessThan:
			return wand.lengthInInches < criteria.numberValue;

		default:
			return false;
	}
}


bool MatchesText(const string& value, const WandFilterCriterion& criteria){

	switch (criteria.operation){
		case OperationEqual:
			return value == criteria.textValue;

		case OperationContains:
			return value.find(criteria.textValue) != string::npos;

		default:
			return false;
	}
}
	