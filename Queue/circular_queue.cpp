#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enQ (int val){
    // overflow check
    if ((rear+1)%N == front ){
        cout <<"Queue is full\n";
        return;
    }
    if (front == -1){
        // inserting first element
        front = 0;
    }
    rear = (rear + 1 )% N;
    queue[rear]= val;
    cout <<"insertion sucessful\n";
}

void DeQ(){
    // check for empty queue
    if (front == -1){
        cout<<"queue is empty\n";
        return;
    }
    cout<< queue[front]<<endl;

    // only one element exists, empty the list
    if (front == rear){
        front = rear = -1;
    }
    else{
        // fornt moves forward
        front = (front + 1)% N;
    }
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
                enQ(value);
                break;
            case 2:
                DeQ();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-3.\n";
        }
    }
}