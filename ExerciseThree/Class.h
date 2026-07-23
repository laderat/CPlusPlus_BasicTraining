#ifndef Class_H
#define Class_H

#include <string>
#include <list>

#include "ClassSchedule.h"

struct Class{
	std::string name;
	std::list<ClassSchedule> schedules;
};

#endif