#include "Vehicle.h"

struct ListNode {
    Vehicle data;
    ListNode* next;
};

class ParkedList {
private:
    ListNode* head;
    int count;

public:
    ParkedList() {
        head = nullptr;
        count = 0;
    }

    ~ParkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    int getCount() {
        return count;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void add(const Vehicle& v) {
        ListNode* newNode = new ListNode();
        newNode->data = v;
        newNode->next = head;
        head = newNode;
        count++;
    }

    
    Vehicle removeById(int id) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current != nullptr && current->data.getParkingId() != id) {
            prev = current;
            current = current->next;
        }

       
        if (current == nullptr) {
            return Vehicle(); 
        }

       
        Vehicle foundVehicle = current->data;

        if (prev == nullptr) { 
            head = current->next;
        } else { 
            prev->next = current->next;
        }

        delete current;
        count--;
        return foundVehicle;
    }

    void displayList() {
        if (isEmpty()) {
            cout << "No vehicles parked in this slot." << endl;
            return;
        }
        ListNode* current = head;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }
};

