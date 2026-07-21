#ifndef WandFilterType_H
#define WandFilterType_H

enum WandFilterField {
	FilterByLength,
	FilterByCore,
	FilterByWoodType
};

enum WandFilterOperation {
	OperationEqual,
	OperationGreaterThan,
	OperationLessThan,
	OperationContains
};

#endif