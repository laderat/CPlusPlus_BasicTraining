#ifndef SchedulePlotter_H
#define SchedulePlotter_H

#include <list>
#include "Class.h"
#include "PlottedClass.h"

void PlotClassSchedule( const std::list<Class>& availableClasses,std::list<PlottedClass>& plottedClasses
);

bool IsClassAlreadyPlotted( const std::list<PlottedClass>& plottedClasses, const std::string& className
);

bool HasScheduleConflict( const std::list<PlottedClass>& plottedClasses, const ClassSchedule& newSchedule
);

#endif