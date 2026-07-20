#include "StdAfx.h"
#include "Address.h"

void Address::SetRoom(std::string& room){
	this->room = room;
}

void Address::SetStreet(std::string& street){
	this->street = street;
}

void Address::SetVillage(std::string& village){
	this->village = village;
}

void Address::SetCity(std::string& city){
	this->city = city;
}

std::string Address::GetRoom(){
	return room;
}

std::string Address::GetStreet(){
	return street;
}

std::string Address::GetVillage(){
	return village;
}

std::string Address::GetCity(){
	return city;
}
