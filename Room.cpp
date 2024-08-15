#include "Room.h"


// Default constructor
Room::Room() : roomNo(0), type(""), price(0.0), isAvailable(true) {}

//parameter constructor
Room::Room(int roomNo, string type, double price, bool isAvailable) :roomNo(roomNo), type(type), price(price), isAvailable(isAvailable) {};

int Room::getRoomNo() { return roomNo; }

double Room::getPrice() { return price; }

bool Room::getIsAvailable() { return isAvailable; }

string Room::getType() { return type; }

void Room::setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
