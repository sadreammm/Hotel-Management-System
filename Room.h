#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <iostream>

using namespace std;

class Room {
	private:
		int roomNo;
		string type;
		double price;
		bool isAvailable;
	public:
		Room();
		Room(int, string, double, bool);
		int getRoomNo();
		string getType();
		bool getIsAvailable();
		double getPrice();
		void setIsAvailable(bool);
};

#endif // !ROOM.H

