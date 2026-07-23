#ifndef PlottedClass_H
#define PlottedClass_H

#include <string>

#include "ClassSchedule.h"

struct PlottedClass
{
    std::string className;
    ClassSchedule schedule;
};

#endif