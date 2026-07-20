// CPlusPlus_BasicTraining.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StudentFunction.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	bool isRunning = true;
	
	while (isRunning){
		Student student;
		string input;

		EnterStudentInformation(student);
		PrintStudentInformation(student);

		cout << "Enter X if you want to create another letter otherwise this program will terminate:" << endl;
		getline(cin, input);

		if (input != "x" && input != "X"){
			isRunning = false;
		}
	}

	return 0;
}


