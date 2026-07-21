#ifndef WandFilterCriterion_H
#define WandFilterCriterion_H

#include "WandFilterTypes.h"
#include <string>

struct WandFilterCriterion{
	WandFilterField field;
	WandFilterOperation operation;

	float numberValue;
	std::string textValue;
};

#endif