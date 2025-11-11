#include <iostream>
#include "Parking.h" 

using namespace std;


void showMenu() {
    cout << "  Parking Management System" << endl;
    cout << "  (Using Custom Data Structures)" << endl;
    cout << "1. Park Vehicle" << endl;
    cout << "2. Remove Vehicle" << endl;
    cout << "3. Show Parking Status" << endl;
    cout << "4. Show Departed Vehicle Log (Stack)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    
    Parking parkingLot;
    int choice;

    do {
        showMenu();
        cin >> choice;

    switch (choice) {
            case 1:
                parkingLot.parkVehicle();
                break;
            case 2:
                parkingLot.removeVehicle();
                break;
            case 3:
                parkingLot.showParkingStatus();
                break;
            case 4:
                parkingLot.showDepartedLog();
                break;
            case 5:
                cout << "\nProgram Exiting :  Goodbye!" << endl;
                break;
            default:
                cout << "\nERROR: Invalid choice. Please select from 1 to 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}