#include "Vehicle.h"
#include "Stack.h"
#include "Queue.h"
#include "ParkedList.h"
#include <cmath> 
#include <iomanip> 

class Parking {
private:
    const int RICKSHAW_CAPACITY = 10;
    const int CAR_A_CAPACITY = 20;
    const int CAR_B_CAPACITY = 15;
    const int MOTORCYCLE_CAPACITY = 25;


    const double RICKSHAW_RATE = 50.0;
    const double CAR_A_RATE = 100.0;
    const double CAR_B_RATE = 120.0;
    const double MOTORCYCLE_RATE = 30.0;

    
    ParkedList rickshawSlots;
    ParkedList carASlots;
    ParkedList carBSlots;
    ParkedList motorcycleSlots;


    VehicleQueue rickshawWaiting;
    VehicleQueue carAWaiting;
    VehicleQueue carBWaiting;
    VehicleQueue motorcycleWaiting;


    Stack departedStack;

    
    int nextID = 1;


    double getRate(char type) {
        if (type == 'R') 
        return RICKSHAW_RATE;
        if (type == 'A')
         return CAR_A_RATE;
        if (type == 'B')
         return CAR_B_RATE;
        if (type == 'M') 
        return MOTORCYCLE_RATE;
        return 0.0;
    }

    double calculateRent(Vehicle& v) {
        if (v.getCustomerType() == "VIP") {
            cout << "\nCustomer is VIP. No hourly charge. Rent is Paid on monthly basis" << endl;
            return 0.0;
        }

        time_t exitTime = time(0);
        v.setExitTime(exitTime);

        double seconds = difftime(exitTime, v.getEntryTime());
        double hours = ceil(seconds / 3600.0); 
        if (hours < 1.0) hours = 1.0; 

        double rent = hours * getRate(v.getType());
        v.setRentCharged(rent);
        return rent;
    }

    void checkWaitingList(char vehicleType) {
        if (vehicleType == 'R' && !rickshawWaiting.isEmpty() && rickshawSlots.getCount() < RICKSHAW_CAPACITY) {
            Vehicle v = rickshawWaiting.dequeue();
            v.setParkingid(nextID++);
            v.setEntryTime(time(0));
            rickshawSlots.add(v);
            cout << "\n[AUTO] Vehicle " << v.getRegNum() << " from waiting list parked. ID: " << v.getParkingId() << endl;
        }
        else if (vehicleType == 'A' && !carAWaiting.isEmpty() && carASlots.getCount() < CAR_A_CAPACITY) {
            Vehicle v = carAWaiting.dequeue();
            v.setParkingid(nextID++);
            v.setEntryTime(time(0));
            carASlots.add(v);
            cout << "\n[AUTO] Vehicle " << v.getRegNum() << " from waiting list parked. ID: " << v.getParkingId() << endl;
        }
         else if (vehicleType == 'B' && !carBWaiting.isEmpty() && carBSlots.getCount() < CAR_B_CAPACITY) {
            Vehicle v = carBWaiting.dequeue();
            v.setParkingid(nextID++);
            v.setEntryTime(time(0));
            carBSlots.add(v);
            cout << "\n[AUTO] Vehicle " << v.getRegNum() << " from waiting list parked. ID: " << v.getParkingId() << endl;
        }
         else if (vehicleType == 'M' && !motorcycleWaiting.isEmpty() && motorcycleSlots.getCount() < MOTORCYCLE_CAPACITY) {
            Vehicle v = motorcycleWaiting.dequeue();
            v.setParkingid(nextID++);
            v.setEntryTime(time(0));
            motorcycleSlots.add(v);
            cout << "\n[AUTO] Vehicle " << v.getRegNum() << " from waiting list parked. ID: " << v.getParkingId() << endl;
        }
    }


public:
    
    void parkVehicle() {
        int typeChoice, customerChoice;
        string regNum;
        char vType;
        string cType;

        cout << "Enter Registration Number: ";
        cin >> regNum;

        cout << "Select Vehicle Type:\n";
        cout << "  1. Rickshaw\n  2. Car (Type A)\n  3. Car (Type B)\n  4. Motorcycle\nChoice: ";
        cin >> typeChoice;
        
        cout << "Select Customer Type:\n  1. Normal\n  2. VIP (Monthly)\nChoice: ";
        cin >> customerChoice;

        cType = (customerChoice == 1) ? "Normal" : "VIP";

        if(typeChoice == 1) vType = 'R';
        else if(typeChoice == 2) vType = 'A';
        else if(typeChoice == 3) vType = 'B';
        else if(typeChoice == 4) vType = 'M';
        else {
            cout << "\nInvalid vehicle type." << endl;
            return;
        }

        Vehicle v(vType, regNum, cType);

        if(vType == 'R') {
            if(rickshawSlots.getCount() < RICKSHAW_CAPACITY) {
                v.setParkingid(nextID++);
                v.setEntryTime(time(0));
                rickshawSlots.add(v);
                cout << "\nSUCCESS: Vehicle parked. ID: " << v.getParkingId() << endl;
            } else {
                rickshawWaiting.enqueue(v);
            }
        }
        else if(vType == 'A') {
             if(carASlots.getCount() < CAR_A_CAPACITY) {
                v.setParkingid(nextID++);
                v.setEntryTime(time(0));
                carASlots.add(v);
                cout << "\nSUCCESS: Vehicle parked. ID: " << v.getParkingId() << endl;
            } else {
                carAWaiting.enqueue(v);
            }
        }
        else if(vType == 'B') {
             if(carBSlots.getCount() < CAR_B_CAPACITY) {
                v.setParkingid(nextID++);
                v.setEntryTime(time(0));
                carBSlots.add(v);
                cout << "\nSUCCESS: Vehicle parked. ID: " << v.getParkingId() << endl;
            } else {
                carBWaiting.enqueue(v);
            }
        }
        else if(vType == 'M') {
             if(motorcycleSlots.getCount() < MOTORCYCLE_CAPACITY) {
                v.setParkingid(nextID++);
                v.setEntryTime(time(0));
                motorcycleSlots.add(v);
                cout << "\nSUCCESS: Vehicle parked. ID: " << v.getParkingId() << endl;
            } else {
                motorcycleWaiting.enqueue(v);
            }
        }
    }


    void removeVehicle() {
        int id;
        cout << "Enter Vehicle ID to remove: ";
        cin >> id;
        
        
        Vehicle v = rickshawSlots.removeById(id);
        if(v.getParkingId() == 0) v = carASlots.removeById(id);
        if(v.getParkingId() == 0) v = carBSlots.removeById(id);
        if(v.getParkingId() == 0) v = motorcycleSlots.removeById(id);

        
        if(v.getParkingId() == 0) {
            cout << "\nERROR: Vehicle ID " << id << " not found." << endl;
            return;
        }

        
        double rent = calculateRent(v);

        cout << "\n--- VEHICLE DEPARTING ---" << endl;
        v.display();
        cout << "  Rent Charged: $" << fixed << setprecision(2) << rent << endl;
        

        
        departedStack.push(v);

        
        checkWaitingList(v.getType());
    }


    void showParkingStatus() {
        cout << "\n--- Current Parking Status ---" << endl;
        cout << "Rickshaws:   " << rickshawSlots.getCount() << " / " << RICKSHAW_CAPACITY 
             << " (Waiting: " << rickshawWaiting.getCount() << ")" << endl;
        cout << "Car (Type A):  " << carASlots.getCount() << " / " << CAR_A_CAPACITY
             << " (Waiting: " << carAWaiting.getCount() << ")" << endl;
        cout << "Car (Type B):  " << carBSlots.getCount() << " / " << CAR_B_CAPACITY
             << " (Waiting: " << carBWaiting.getCount() << ")" << endl;
        cout << "Motorcycles: " << motorcycleSlots.getCount() << " / " << MOTORCYCLE_CAPACITY
             << " (Waiting: " << motorcycleWaiting.getCount() << ")" << endl;
        
    }

    
    void showDepartedLog() {
        departedStack.displayStack();
    }
};

