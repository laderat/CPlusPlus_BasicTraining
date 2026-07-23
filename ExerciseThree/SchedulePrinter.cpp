#include "stdafx.h"
#include <iostream>
#include "SchedulePrinter.h"

using namespace std;

void PrintClassSchedule(const list<Class>& classes)
{
    cout << "====================================" << endl;
    cout << "          Class Schedules           " << endl;
    cout << "====================================" << endl;

    list<Class>::const_iterator currentClass;

    for (currentClass = classes.begin(); currentClass != classes.end(); ++currentClass)
    {
        cout << currentClass->name << endl;
        cout << "====================================" << endl;

        list<ClassSchedule>::const_iterator currentSchedule;

        for (currentSchedule = currentClass->schedules.begin(); currentSchedule != currentClass->schedules.end(); ++currentSchedule){
            cout << currentSchedule->startTime << " - " << currentSchedule->endTime << endl;
        }

        cout << "====================================" << endl;
    }
}

void PrintPlottedSchedule(const list<PlottedClass>& plottedClasses)
{
    cout << endl;
    cout << "====================================" << endl;
    cout << "        Hermiyani's Schedule        " << endl;
    cout << "====================================" << endl;



	if(plottedClasses.size() < 1){
		cout << "No schedule plotted yet!" << endl;

	}else{
		list<PlottedClass>::const_iterator currentClass;
		for (currentClass = plottedClasses.begin(); currentClass != plottedClasses.end(); ++currentClass){
			cout << currentClass->className << " : " << currentClass->schedule.startTime << " - " << currentClass->schedule.endTime << endl;

		}
	}

    cout << "====================================" << endl;
}