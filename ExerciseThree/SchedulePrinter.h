#ifndef SchedulePrinter_H
#define SchedulePrinter_H

#include <list>
#include "Class.h"
#include "PlottedClass.h"

void PrintClassSchedule(const std::list<Class>& classes);
void PrintPlottedSchedule(const std::list<PlottedClass>& plottedClasses);

#endif