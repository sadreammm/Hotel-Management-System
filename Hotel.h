#pragma once
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include "Customer.h"
#include "Room.h"
#include <fstream>
#include <sstream>
#include <vector>

class Customer;
using namespace std;

class Hotel {
	private:
		vector<Room> rooms;
		vector<Customer> customers;
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
