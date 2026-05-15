#include <iostream>
#include <cstdlib>
using namespace std;

struct LLqueue
{
    int data;
    LLqueue* next = nullptr;
};
LLqueue* front = nullptr;
LLqueue* rear = nullptr;

void enQueue(int val){
    LLqueue* temp = new LLqueue;
    temp ->data = val;
    temp ->next = nullptr;

    // inserting first node
    if(rear==nullptr && front == nullptr){
        rear = front = temp;
        cout << "insertion successfull\n";
        return;
    }
    else{
        rear ->next = temp;
        rear = temp;
        cout << "insertion successfull\n";
        return;
    }
}

void deQueue(){
    // empty queue
    if (front == nullptr){
        cout << "queue is empty\n";
        return;
    }
    LLqueue* cur = front;
    cout << cur ->data <<endl;
    front = front ->next;

    // if queue becomes empty
    if (front == nullptr){
        rear = nullptr;
    }
    delete cur;
}    

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n===== queue List Menu =====\n";
        cout << "1. enQ value\n";
        cout << "2. deQ List\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-3.\n";
        }
    }
}