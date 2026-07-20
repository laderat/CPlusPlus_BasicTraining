#include "StdAfx.h"
#include "Student.h"

//#include <iostream>
//using namespace std;

void Student::SetFirstName(std::string& firstName){
	this->firstName = firstName;
}

void Student::SetLastName(std::string& lastName){
	this->lastName = lastName;
}

void Student::SetGender(Gender gender){
	this->gender = gender;
}

std::string Student::GetFirstName(){
	return firstName;
}

std::string Student::GetLastName(){
	return lastName;
}

Gender Student::GetGender(){
	return gender;
}

Address& Student::GetAddress(){
	return address;
}
