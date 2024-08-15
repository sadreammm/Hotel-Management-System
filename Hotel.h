#pragma once
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include "Customer.h"
#include "Room.h"
#include <fstream>
#include <sstream>

class Customer;
using namespace std;

class Hotel {
	private:
		Room rooms[100];
		Customer customers[100];
		static int roomCount;
		static int customerCount;
		int calculateDays(string, string);
	public:
		Hotel() {}
		int initialize(string);
		void display();
		void checkIn(Customer&, string, int);
		void checkOut(string, int);
		void availableRooms();
		void bookedRooms();
		void billingSystem(Customer&);
		void save(string);
};


#endif 
