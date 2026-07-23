#ifndef CLassRepository_H
#define CLassRepository_H

#include <list>
#include <string>
#include "Class.h"
#include "ClassSchedule.h"

std::list<Class> CreateAvailableClasses();
ClassSchedule CreateSchedule(std::string startTime, std::string endTime);

#endif