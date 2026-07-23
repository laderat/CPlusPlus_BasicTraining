#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

void DisplayDesignLine();
void DisplayDesignHeader(std::string title);
void DisplayDesignWarning(std::string warningMessage);


void DisplayDesignLine(){
	cout << endl << "=============================================================================================" << endl << endl;
}

void DisplayDesignHeader(string title){
	DisplayDesignLine();

	cout << title << endl;

	DisplayDesignLine();
}


void DisplayDesignWarning(string warningMessage){
	cout << endl << "[Warning] " << warningMessage << endl;
}