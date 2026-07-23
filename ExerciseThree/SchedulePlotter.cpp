#include "stdafx.h"
#include <iostream>
#include "SchedulePlotter.h"
#include "InputValidator.h"

using namespace std;

const Class* SelectClass(const list<Class>& classes);
const ClassSchedule* SelectSchedule(const Class& selectedClass);

void PrintClassChoices(const list<Class>& classes);
const Class* FindClassByIndex(const list<Class>& classes, int choice);

bool IsClassAlreadyPlotted(const list<PlottedClass>& plottedClasses, const string& className);
const ClassSchedule* SelectSchedule(const Class& selectedClass);
void PrintSchedules(const Class& selectedClass);
const ClassSchedule* FindScheduleByIndex(const Class& selectedClass, int choice);
void AddPlottedClass(list<PlottedClass>& plottedClasses, const string& className, const ClassSchedule& schedule);

void PlotClassSchedule(const list<Class>& availableClasses, list<PlottedClass>& plottedClasses){
    const Class* selectedClass = SelectClass(availableClasses);

    if (selectedClass == NULL){
        return;
    }

    if (IsClassAlreadyPlotted(plottedClasses, selectedClass->name)){
        cout << "[Error] This class has already been plotted." << endl;
        return;
    }

    const ClassSchedule* selectedSchedule = SelectSchedule(*selectedClass);

    if (selectedSchedule == NULL){
        return;
    }

    if (HasScheduleConflict(plottedClasses, *selectedSchedule)){
        cout << "[Error] Schedule conflict found." << endl;
        return;
    }

    AddPlottedClass(plottedClasses, selectedClass->name, *selectedSchedule);

    cout << "[Success] Class plotted successfully." << endl;
}

const Class* SelectClass(const list<Class>& classes){
    PrintClassChoices(classes);

    int classChoice = ValidateIntegerInput("Enter class choice: ");

    return FindClassByIndex(classes, classChoice);
}

void PrintClassChoices(const list<Class>& classes){
    cout << endl;
    cout << "Pick a class to plot:" << endl;

    int index = 1;

    list<Class>::const_iterator currentClass;

    for(currentClass = classes.begin(); currentClass != classes.end(); ++currentClass){
        cout << index++ << " : " << currentClass->name << endl;
    }
}

const Class* FindClassByIndex(const list<Class>& classes, int choice){
    int index = 1;

    list<Class>::const_iterator currentClass;

    for(currentClass = classes.begin(); currentClass != classes.end(); ++currentClass){
        if(index == choice){
            return &(*currentClass);
        }

        ++index;
    }

    cout << "[Error] Invalid class choice." << endl;

    return NULL;
}

bool IsClassAlreadyPlotted(const list<PlottedClass>& plottedClasses, const string& className){
    list<PlottedClass>::const_iterator currentClass;

    for (currentClass = plottedClasses.begin(); currentClass != plottedClasses.end(); ++currentClass){
        if (currentClass->className == className){
            cout << "Already plotted class details:" << endl;
            cout << currentClass->className << " : " << currentClass->schedule.startTime << " - " << currentClass->schedule.endTime << endl;

            return true;
        }
    }

    return false;
}

const ClassSchedule* SelectSchedule(const Class& selectedClass){
    PrintSchedules(selectedClass);

    int scheduleChoice = ValidateIntegerInput("Enter schedule choice: ");

    return FindScheduleByIndex(selectedClass, scheduleChoice);
}

void PrintSchedules(const Class& selectedClass){
    cout << endl;
    cout << selectedClass.name << " Schedules" << endl;
    cout << "====================" << endl;

    int index = 1;

    list<ClassSchedule>::const_iterator currentSchedule;

    for(currentSchedule = selectedClass.schedules.begin(); currentSchedule != selectedClass.schedules.end(); ++currentSchedule){
        cout << index++ << " : " << currentSchedule->startTime << " - " << currentSchedule->endTime<< endl;
    }
}

const ClassSchedule* FindScheduleByIndex(const Class& selectedClass, int choice){
    int index = 1;

    list<ClassSchedule>::const_iterator currentSchedule;
    for(currentSchedule = selectedClass.schedules.begin();  currentSchedule != selectedClass.schedules.end(); ++currentSchedule){
        if(index == choice){
            return &(*currentSchedule);
        }

        ++index;
    }

    cout << "[Error] Invalid schedule choice." << endl;

    return NULL;
}

void AddPlottedClass(list<PlottedClass>& plottedClasses, const string& className, const ClassSchedule& schedule){
    PlottedClass plottedClass;

    plottedClass.className = className;
    plottedClass.schedule = schedule;

    plottedClasses.push_back(plottedClass);
}

bool HasScheduleConflict(const list<PlottedClass>& plottedClasses, const ClassSchedule& newSchedule){

    list<PlottedClass>::const_iterator currentClass;
    for (currentClass = plottedClasses.begin(); currentClass != plottedClasses.end(); ++currentClass){

        if (currentClass->schedule.startTime == newSchedule.startTime || currentClass->schedule.endTime == newSchedule.endTime){
            cout << "Conflicting class details:" << endl;
            cout << currentClass->className << " : " << currentClass->schedule.startTime << " - " << currentClass->schedule.endTime << endl;

            return true;
        }
    }

    return false;
}