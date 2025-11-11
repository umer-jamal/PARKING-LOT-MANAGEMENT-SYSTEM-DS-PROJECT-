#include <iostream>
#include "Vehicle.h"
using namespace std;

struct QueueNode {
    Vehicle data;
    QueueNode* next;
};

class VehicleQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;

public:
    VehicleQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~VehicleQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    int getCount() {
        return count;
    }

    void enqueue(const Vehicle& value) {
        QueueNode* newNode = new QueueNode();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Vehicle (" << value.getRegNum() << ") added to the WAITING line." << endl;
    }

    Vehicle dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! The waiting line is empty." << endl;
            return Vehicle();
        }

        Vehicle poppedValue = front->data;
        QueueNode* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        count--;
        return poppedValue;
    }

    Vehicle peek() {
        if (isEmpty()) {
            cout << "The waiting line is empty." << endl;
            return Vehicle();
        }
        return front->data;
    }

    void displayQueue() {
        if(isEmpty()) {
            cout << "Waiting queue is empty." << endl;
            return;
        }
        QueueNode* current = front;
        while(current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }
};

