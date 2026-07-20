#ifndef Address_H
#define Address_H

#include <string>

class Address {
private:
	std::string room;
	std::string street;
	std::string village;
	std::string city;

public:
	void SetRoom(std::string& room);
	void SetStreet(std::string& street);
	void SetVillage(std::string& village);
	void SetCity(std::string& city);

	std::string GetRoom();
	std::string GetStreet();
	std::string GetVillage();
	std::string GetCity();
};

#endif