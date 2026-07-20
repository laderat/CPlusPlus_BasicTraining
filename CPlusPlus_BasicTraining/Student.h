#ifndef Student_H
#define Student_H

# include <string>
# include "Gender.h"
# include "Address.h"

class Student{
private:
	std::string firstName;
	std::string lastName;

	Gender gender;
	Address address;

public:
	void SetFirstName(std::string& firstName);
	void SetLastName(std::string& lastName);
	void SetGender(Gender gender);
	
	std::string GetFirstName();
	std::string GetLastName();
	Gender GetGender();
	Address& GetAddress();
};

#endif