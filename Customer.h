#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

class Customer {
	private:
		string name;
		string checkInDate;
		string checkOutDate;
		int roomNo;
	public:
		Customer();
		Customer(string);
		void setCheckIn(string);
		void setCheckOut(string);
		void setRoomNo(int);
		string getName();
		int getRoomNo();
		string getCheckIn();
		string getCheckOut();
};

#endif // !CUSTOMER.H
