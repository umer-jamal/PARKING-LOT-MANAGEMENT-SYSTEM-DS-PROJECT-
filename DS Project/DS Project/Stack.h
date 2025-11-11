#include <iostream>
#include "Vehicle.h" 
using namespace std;


struct Node {
    Vehicle data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        Node* temp;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(const Vehicle& value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        
        cout << "\nVehicle (" << value.getRegNum() << ") pushed to stack." << endl;
    }

    Vehicle pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return Vehicle(); 
        }
        
        Vehicle poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        
        return poppedValue;
    }

    Vehicle peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return Vehicle(); 
        }
        return top->data;
    }

    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "\n--- Stack (Top to Bottom) ---" << endl;
        Node* current = top;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
        cout << "-----------------------------" << endl;
    }
};

