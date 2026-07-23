// ExerciseThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

#include "Class.h"
#include "PlottedClass.h"
#include "ClassRepository.h"
#include "SchedulePrinter.h"
#include "SchedulePlotter.h"
#include "InputValidator.h"

using namespace std;


void SelectMenu(const list<Class>& availableClasses, list<PlottedClass>& plottedClasses);
void ScheduleMenu();

int _tmain(int argc, _TCHAR* argv[])
{
	list<Class> availableClasses = CreateAvailableClasses();
	list<PlottedClass> plottedClasses;

	SelectMenu(availableClasses, plottedClasses);

	return 0;
}

void SelectMenu(const list<Class>& availableClasses, list<PlottedClass>& plottedClasses){
    bool willContinue = true;

    while (willContinue){
        ScheduleMenu();

        int input = ValidateIntegerInput("Select Option: ");
		cout << endl;

        switch (input){
			case 0:
				willContinue = false;
				break;

			case 1:
				PrintClassSchedule(availableClasses);
				break;

			case 2:
				PrintPlottedSchedule(plottedClasses);
				break;

			case 3:
				PlotClassSchedule(availableClasses, plottedClasses);

				if (plottedClasses.size() == availableClasses.size()){
					cout << endl;
					cout << "All classes have been plotted!" << endl;

					PrintPlottedSchedule(plottedClasses);
				}
				break;

			default:
				cout << "Enter a valid option!" << endl;
        }
    }
}

void ScheduleMenu()
{
    cout << endl;
    cout << "====================================" << endl;
    cout << "           Schedule Menu           " << endl;
    cout << "====================================" << endl;
    cout << "0 : Exit App" << endl;
    cout << "1 : View Class Schedules" << endl;
    cout << "2 : View My Schedule" << endl;
    cout << "3 : Plot Class Schedule" << endl;
    cout << "====================================" << endl;
}
