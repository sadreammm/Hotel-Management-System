#include "Customer.h"

// Default constructor
Customer::Customer() : name(""), checkInDate(""), checkOutDate(""), roomNo(0) {}
//parameter constructor
Customer::Customer(string name) :name(name) {};

void Customer::setCheckIn(string checkInDate) { this->checkInDate = checkInDate; }

void Customer::setCheckOut(string checkOutDate) { this->checkOutDate = checkOutDate; }

void Customer::setRoomNo(int roomNo){ this->roomNo=roomNo; }

string Customer::getName() { return name; }

int Customer::getRoomNo() { return roomNo; }

string Customer::getCheckIn() { return checkInDate; }
string Customer::getCheckOut() { return checkOutDate; }