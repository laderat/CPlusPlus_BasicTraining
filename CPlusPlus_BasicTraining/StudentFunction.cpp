#include "StdAfx.h"
#include "StudentFunction.h"
#include <iostream>
#include <string>
using namespace std;

void InputFirstName(Student& student);
void InputLastName(Student& student);
void InputGender(Student& student);
void InputRoom(Student& student);
void InputStreet(Student& student);
void InputVillage(Student& student);
void InputCity(Student& student);

void EnterStudentInformation(Student& student){
	InputFirstName(student);
	InputLastName(student);
	InputGender(student);
	InputRoom(student);
	InputStreet(student);
	InputVillage(student);
	InputCity(student);
}

	void InputFirstName(Student& student){
		string firstName;

		cout << "Enter the student's firstname: ";
		getline(cin, firstName);

		student.SetFirstName(firstName);
	};

	void InputLastName(Student& student){
		string lastName;

		cout << "Enter the student's lastname: ";
		getline(cin, lastName);

		student.SetLastName(lastName);
	};

	void InputGender(Student& student){
		int choice;
		bool isValid = false;

		while (!isValid){
			cout << "Enter gender (1 = Male or 2 = Female): ";

			if(!(cin >> choice)){
				cout << "Please input a valid number!" << endl;

				cin.clear();
				cin.ignore(1000,'\n');

				continue;
			}

			if(choice == 1){
				student.SetGender(Male);
				isValid = true;
			}else if(choice == 2){
				student.SetGender(Female);
				isValid = true;
			}else{
				cout << "Invalid choice pls input a valid choice again" << endl;
			}
		}
		
		cin.ignore(1000,'\n');
	};

	void InputRoom(Student& student){
		string room;

		cout << "Enter " << student.GetFirstName() << "'s Room: ";
		getline(cin, room);

		student.GetAddress().SetRoom(room);
	};

	void InputStreet(Student& student){
		string street;

		cout << "Enter " << student.GetFirstName() << "'s Street: ";
		getline(cin, street);

		student.GetAddress().SetStreet(street);
	}

	void InputVillage(Student& student){
		string village;

		cout << "Enter " << student.GetFirstName() << "'s Village: ";
		getline(cin, village);

		student.GetAddress().SetVillage(village);
	};

	void InputCity(Student& student){
		string city;

		cout << "Enter " << student.GetFirstName() << "'s City: ";
		getline(cin, city);

		student.GetAddress().SetCity(city);
	};


void PrintLine();
void PrintHeader();
void PrintRecipient(Student& student);
void PrintBody(Student& student);
void PrintClosing();
void PrintStudentInformation(Student& student);
void NewLine();

void PrintStudentInformation(Student& student){
	NewLine();
	PrintLine();
	PrintHeader();

	PrintRecipient(student);
	PrintBody(student);


	PrintClosing();
	PrintLine();
	NewLine();
}

	void PrintLine(){
		cout << "=============================================================================================" << endl;
	}

	void PrintHeader(){
		cout << "Chogborts School of Witchcraft and Wizardry" << endl;
		cout << "Headmaster: Manuel Baridore (Order of Junkins, First Class, Grand Sorc., Chf. Warlock, Supreme Mugwump, International Confed. of Wizards)" << endl << endl;
	}

	string GetGenderTitle(Gender gender);

	void PrintRecipient(Student& student){
		cout << GetGenderTitle(student.GetGender()) << student.GetFirstName() << student.GetLastName() << endl;
		cout << student.GetAddress().GetRoom() << endl;
		cout << student.GetAddress().GetStreet() << endl;
		cout << student.GetAddress().GetVillage() << endl;
		cout << student.GetAddress().GetCity() << endl << endl;
	}

		string GetGenderTitle(Gender gender){
			if (gender == Male){
				return "Mr.";
			}

			if (gender == Female){
				return "Ms.";
			}
		}

	char GetInitialFirstName(string name);

	void PrintBody(Student& student){
		cout << "Dear " << GetGenderTitle(student.GetGender()) << " "<< GetInitialFirstName(student.GetFirstName()) << student.GetLastName() << "," << endl <<endl;  
		cout << "We are pleased to inform you that you have been accepted at Hogwarts School of Witchcraft and Wizardry. Please find enclosed a list of all necessary books and equipment.Term begins on September 1. We await your owl by no later than July 31." << endl << endl;  
	}

		char GetInitialFirstName(string name){
			return name[0];
		}

	void PrintClosing(){
		cout << "Yours sincerely," << endl;
		cout << "May McGiltendez" << endl;
		cout << "Deputy Headmistress" << endl;
	}

	void NewLine(){
		cout << endl;
	}