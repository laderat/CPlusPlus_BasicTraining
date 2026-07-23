#include "stdafx.h"
#include "ClassRepository.h"

std::list<Class> CreateAvailableClasses()
{
    std::list<Class> classes;

    Class astronomy;
    astronomy.name = "Astronomy";
    astronomy.schedules.push_back(CreateSchedule("7:30am", "8:30am"));
    astronomy.schedules.push_back(CreateSchedule("8:30am", "9:30am"));
    astronomy.schedules.push_back(CreateSchedule("1:30pm", "2:30pm"));
    classes.push_back(astronomy);

    Class charms;
    charms.name = "Charms";
    charms.schedules.push_back(CreateSchedule("9:30am", "10:30am"));
    charms.schedules.push_back(CreateSchedule("10:30am", "11:30am"));
    charms.schedules.push_back(CreateSchedule("3:30pm", "4:30pm"));
    classes.push_back(charms);

    Class defense;
    defense.name = "Defense Against the Dark Arts";
    defense.schedules.push_back(CreateSchedule("7:30am", "8:30am"));
    defense.schedules.push_back(CreateSchedule("3:30pm", "4:30pm"));
    defense.schedules.push_back(CreateSchedule("4:30pm", "5:30pm"));
    classes.push_back(defense);

    return classes;
}

ClassSchedule CreateSchedule(std::string startTime, std::string endTime)
{
    ClassSchedule schedule;
    schedule.startTime = startTime;
    schedule.endTime = endTime;

    return schedule;
}