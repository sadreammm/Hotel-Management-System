#include <iostream>
#include <string>
#include "Hotel.h"

using namespace std;

void displayMenu() {
    cout << "********** Hotel Management System **********" << endl;
    cout << "1. Initialize Hotel" << endl;
    cout << "2. Display Hotel Description" << endl;
    cout << "3. Check-In" << endl;
    cout << "4. Check-Out" << endl;
    cout << "5. Display Available Rooms" << endl;
    cout << "6. Display Booked Rooms" << endl;
    cout << "7. Save Hotel Data" << endl;
    cout << "0. Exit" << endl;
    cout << "*********************************************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Hotel hotel;
    string filename;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the filename to initialize hotel data: ";
            cin >> filename;
            if (hotel.initialize(filename) == 0) {
                cout << "Hotel data initialized successfully." << endl;
            }
            else {
                cout << "Failed to initialize hotel data." << endl;
            }
            break;
        case 2:
            hotel.display();
            break;
        case 3: {
            string name, checkInDate;
            int roomNo;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter check-in date (YYYY-MM-DD): ";
            cin >> checkInDate;
            cout << "Enter room number: ";
            cin >> roomNo;
            Customer customer(name);
            hotel.checkIn(customer, checkInDate, roomNo);
            break;
        }
        case 4: {
            string checkOutDate;
            int roomNo;
            cout << "Enter check-out date (YYYY-MM-DD): ";
            cin >> checkOutDate;
            cout << "Enter room number: ";
            cin >> roomNo;
            hotel.checkOut(checkOutDate, roomNo);
            break;
        }
        case 5:
            hotel.availableRooms();
            break;
        case 6:
            hotel.bookedRooms();
            break;
        case 7:
            cout << "Enter the filename to save hotel data: ";
            cin >> filename;
            hotel.save(filename);
            cout << "Hotel data saved successfully." << endl;
            break;
        case 0:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
