#include "stdafx.h"
#include <iostream>
#include <string>

#include "DisplayDesign.h"

using namespace std;


int GetValidInteger(string message){
	int input;

	while(true){
		cout << message;
		cin >> input;

		if (!cin.fail()){
			cin.ignore(1000, '\n');
			return input;
		}

		DisplayDesignWarning("Please enter a valid number.");

		cin.clear();
		cin.ignore(1000,'\n');
	}
}

string GetValidString(const string message)
{
    string input;

    while (true)
    {
        cout << message;
        getline(cin,input);

        if (!input.empty())
        {
            return input;
        }

        DisplayDesignWarning("Please enter a valid text.");
    }
}