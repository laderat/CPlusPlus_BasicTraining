#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

#include "Wand.h"
#include "FilterWand.h"
#include "WandFilterTypes.h"
#include "WandFilterCriterion.h"
#include <iostream>

using namespace std;

WandFilterCriterion createFilter();
list<Wand> ApplyFilters(list<Wand>& wandStorage, list<WandFilterCriterion>& criteriaList);
bool matchesCriteria(const Wand& wand,const WandFilterCriterion& criteria);

list<Wand> FilterWand(list<Wand>& wandStorage){

	list<WandFilterCriterion> criteriaList;

	bool willContinue = true;

	while (willContinue){
		
		WandFilterCriterion criterion = createFilter();

		criteriaList.push_back(criterion);
		
		char input;

		cout << "Enter Y if you wish to continue creating a filter: ";
		cin >> input;

		if(!(input == 'Y' || input == 'y')){
			willContinue = false;
		}
	}

	return ApplyFilters(wandStorage, criteriaList);
}

WandFilterCriterion createFilter(){
	int choice;
	WandFilterCriterion criteria;

	cout << "Enter the matching request to add a filter: " << endl;

	cout << "Enter 1 = Add filter for wand length; Enter 2 = Add filter for wand core; Enter 1 = Add filter for wand wood type;" << endl;
	cin >> choice;	

	if (choice == 1){
		criteria.field = FilterByLength;
		cout << "Enter the desired length to find: ";
		cin >> criteria.numberValue;

		int operationChoice;
		cout <<  "Enter 1 = Equal ; Enter 2 = GreaterThan; Enter 3 = LessThan;" << endl;
		cin >> operationChoice;

		if (operationChoice == 1){
			criteria.operation = OperationEqual;
		}
		else if (operationChoice == 2){
			criteria.operation = OperationGreaterThan;
		}
		else if (operationChoice == 3){
			criteria.operation = OperationLessThan;
		}
		else{
			cout << "Enter a valid operation choice";
		}

	}else if (choice == 2){
		criteria.field = FilterByCore;
		cout << "Enter the desired core to find: ";
		cin >> criteria.textValue;

		int operationChoice;
		cout <<  "Enter 1 = Equal ; Enter 2 = Contains" << endl;
		cin >> operationChoice;

		if (operationChoice == 1){
			criteria.operation = OperationEqual;
		}
		else if (operationChoice == 2){
			criteria.operation = OperationContains;
		}
		else{
			cout << "Enter a valid operation choice";
		}

	}else if (choice == 3){
		criteria.field = FilterByWoodType;
		cout << "Enter the desired wood type to find: ";
		cin >> criteria.textValue;

		int operationChoice;
		cout <<  "Enter 1 = Equal ; Enter 2 = Contains" << endl;
		cin >> operationChoice;

		if (operationChoice == 1){
			criteria.operation = OperationEqual;
		}
		else if (operationChoice == 2){
			criteria.operation = OperationContains;
		}
		else{
			cout << "Enter a valid operation choice";
		}

	}else{
		cout << "Enter the valid choice";
	}

	return criteria;

};

list<Wand> ApplyFilters(list<Wand>& wandStorage, list<WandFilterCriterion>& criteriaList){
	list<Wand> filteredWands;

	list<Wand>::const_iterator wand;
	for(wand = wandStorage.begin(); wand != wandStorage.end(); ++wand){
		
		bool matchedAllCriteria = true;

		list<WandFilterCriterion>::const_iterator criteria;
		for(criteria = criteriaList.begin(); criteria != criteriaList.end(); ++criteria){

			if(!matchesCriteria(*wand, *criteria)){
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

bool matchesCriteria(const Wand& wand,const WandFilterCriterion& criteria){

	WandFilterField field = criteria.field;
	WandFilterOperation operation = criteria.operation;

	switch (field){
		case FilterByLength:

			if (operation == OperationEqual){
				if(wand.lengthInInches == criteria.numberValue){
					return true;
				}
				return false;
			}
			else if (operation == OperationGreaterThan){
				if(wand.lengthInInches > criteria.numberValue){
					return true;
				}
				return false;
			}
			else if (operation == OperationLessThan){
				if(wand.lengthInInches < criteria.numberValue){
					return true;
				}
				return false;
			}else {
				return false;
			}

			break;

		case FilterByCore:

			if (operation == OperationEqual){
				if(wand.core == criteria.textValue){
					return true;
				}
				return false;
			}
			else if (operation == OperationContains){
				if(wand.core.find(criteria.textValue) != string::npos){
					return true;
				}
				return false;
			}else {
				return false;
			}

			break;

		case FilterByWoodType:

			if (operation == OperationEqual){
				if(wand.woodType == criteria.textValue){
					return true;
				}
				return false;
			}
			else if (operation == OperationContains){
				if(wand.woodType.find(criteria.textValue) != string::npos){
					return true;
				}
				return false;
			}else {
				return false;
			}

			break;
	}
}
