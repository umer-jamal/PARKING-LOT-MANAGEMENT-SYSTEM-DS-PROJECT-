#ifndef VEHICLE_H
#define  VEHICLE_H




#include <iostream>
#include <string>
#include <ctime>    
#include <iomanip>  
using namespace std;

class Vehicle {
private:
    char type; 
    string regnum;
    int parkingid;
    string customerType; 
    time_t entryTime;

    
    time_t exitTime;
    double rentCharged;


public:
    Vehicle(){ 
        type = '?';
        regnum = "NONE";
        parkingid = 0;
        customerType = "Normal";
        entryTime = 0;
        exitTime = 0;
        rentCharged = 0.0;
    }

    
    Vehicle(char t, const string& rn, string custType) 
        : type(t), regnum(rn), customerType(custType) {
        parkingid = 0; 
        entryTime = 0; 
        exitTime = 0;
        rentCharged = 0.0;
    }

    

    void setType(char t) { 
        type = t;
     }
    char getType() const { 
        return type;
     }

    void setRegNum(const string& rn) { 
        regnum = rn;
     }
    string getRegNum() const { 
        return regnum;
     }


    void setParkingid(int id){ parkingid = id; }
    int getParkingId() const { return parkingid; }

    void setCustomerType(string custType) { customerType = custType; }
    string getCustomerType() const { return customerType; }

    void setEntryTime(time_t time) { entryTime = time; }
    time_t getEntryTime() const { return entryTime; }
    
    void setExitTime(time_t time)
     {
         exitTime = time;
         }
    time_t getExitTime() const {
         return exitTime;
         }

    void setRentCharged(double rent) {
         rentCharged = rent;
         }
    double getRentCharged() const { 
        return rentCharged;
     }


    void display() const {
        cout << "  ID: " << this->parkingid << " | Reg: " << this->regnum 
             << " | Type: " << this->type 
             << " | Customer: " << this->customerType << endl;
        
        // Only show rent if it has been calculated (i.e., vehicle departed)
        if(rentCharged > 0) {
            cout << "  Rent Charged: $" << fixed << setprecision(2) << this->rentCharged << endl;
        }
    }
};
#endif