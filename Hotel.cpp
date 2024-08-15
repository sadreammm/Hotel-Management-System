#include "Hotel.h"

int Hotel::roomCount = 0;
int Hotel::customerCount = 0;

int Hotel::initialize(string filename) {
	ifstream in(filename);
	if (!in) {
		cout << "Error" << endl;
		return 1;
	}
	int roomNo;
	string type;
	double price;
	bool isAvailable;
	while (in >> roomNo >> type >> price >> isAvailable) {
		rooms.push_back(Room(roomNo, type, price, isAvailable));
		roomCount++;
	}
	in.close();
	return 0;
}

void Hotel::display() {
	for (int i = 0; i < roomCount; i++) {
		cout << "***************************************************" << endl;
		cout << "Room Number: " << rooms[i].getRoomNo() << endl;
		cout << "Room type: " << rooms[i].getType() << endl;
		cout << "Room price: " << rooms[i].getPrice() << endl;
		cout << "is Available: " << (rooms[i].getIsAvailable() ? "Yes" : "No") << endl;
		cout << "***************************************************" << endl;
	}
}

void Hotel::checkIn(Customer& cust, string checkInDate, int roomNo) {
	for (int i = 0; i < roomCount; i++) {
		if (rooms[i].getRoomNo() == roomNo && rooms[i].getIsAvailable()) {
			rooms[i].setIsAvailable(false);
			cust.setRoomNo(roomNo);
			cust.setCheckIn(checkInDate);
			customers.push_back(cust);
			customerCount++;
			cout << "Checked in " << cust.getName() << " in room number " << roomNo << " on " << checkInDate << endl;
			return;
		}
	}
	cout << "Room not available" << endl;
}

void Hotel::checkOut(string checkOutDate, int roomNo) {
	for (int i = 0; i < roomCount; i++) {
		if (rooms[i].getRoomNo() == roomNo && !rooms[i].getIsAvailable()) {
			rooms[i].setIsAvailable(true);
			for (int j = 0; j < customerCount; j++) {
				if (customers[j].getRoomNo() == roomNo) {
					string customerName = customers[j].getName();
					Customer& cust = customers[j];
					customers[j].setCheckOut(checkOutDate);
					for (int k = j; k < customerCount - 1; k++) {
						customers[k] = customers[k + 1];
					}
					customerCount--;
					cout << "Checked out " << customerName << " in room number " << roomNo << " on " << checkOutDate << endl;
					billingSystem(cust);
					return;
				}
			}
		}
	}
	cout << "Room has not been booked yet" << endl;
}

void Hotel::availableRooms() {
	for (int i = 0; i < roomCount; i++) {
		if (rooms[i].getIsAvailable()) {
			cout << "***************************************************" << endl;
			cout << "Room Number: " << rooms[i].getRoomNo() << endl;
			cout << "Type: " << rooms[i].getType() << endl;
			cout << "Price: " << rooms[i].getPrice() << endl;
			cout << "Is Available" << endl;
			cout << "***************************************************" << endl;
		}
	}
}

void Hotel::bookedRooms() {
	for (int i = 0; i < customerCount; i++) {
		cout << "***************************************************" << endl;
		cout << "Customer Name: " << customers[i].getName() << endl;
		cout << "Room Number: " << customers[i].getRoomNo() << endl;
		cout << "Check-In Date: " << customers[i].getCheckIn() << endl;
		cout << "Check-Out Date: " << customers[i].getCheckOut() << endl;
		cout << "***************************************************" << endl;
	}
}

void Hotel::billingSystem(Customer& cust) {
	int noDays = calculateDays(cust.getCheckIn(), cust.getCheckOut());
	double totalPrice = 0.0;
	for (int i = 0; i < roomCount; i++) {
		if (rooms[i].getRoomNo() == cust.getRoomNo()) {
			totalPrice = rooms[i].getPrice() * noDays;
			break;
		}
	}
	cout << "The total price for " << noDays << " days is: " << totalPrice << endl;
}

void Hotel::save(string filename) {
	ofstream out(filename);
	for (int i = 0; i < roomCount; i++) {
		out << rooms[i].getRoomNo() << "\n" << rooms[i].getType() << "\n" << rooms[i].getPrice() << "\n" << rooms[i].getIsAvailable() << "\n";
	}
	out.close();
}

int Hotel::calculateDays(string date1, string date2) {
	stringstream ss1(date1);
	stringstream ss2(date2);
	int year1, month1, day1;
	int year2, month2, day2;
	char hyphen;

	ss1 >> year1 >> hyphen >> month1 >> hyphen >> day1;
	ss2 >> year2 >> hyphen >> month2 >> hyphen >> day2;

	// Create tm structures
	struct tm starttm = { 0, 0, 0, day1, month1 - 1, year1 - 1900 };
	struct tm endtm = { 0, 0, 0, day2, month2 - 1, year2 - 1900 };

	// Convert tm to time_t
	time_t start = mktime(&starttm);
	time_t end = mktime(&endtm);

	// Calculate the difference in seconds and then convert to days
	double difference = difftime(end, start);
	int noDays = difference / (60 * 60 * 24);

	return noDays;
}
