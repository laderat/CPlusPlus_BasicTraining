#include "stdafx.h"
#include <iostream>
#include <string>

#include "InputValidator.h"

using namespace std;

int ValidateIntegerInput(string message){
    int input;
	
	while(true){
		cout << message;
		cin >> input;

		if (!cin.fail()){
			cin.ignore(1000, '\n');
			return input;
		}

		cout << "[Error] Please enter a valid number." << endl << endl;

		cin.clear();
		cin.ignore(1000,'\n');
	}
}