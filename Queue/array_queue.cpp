#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enQ(int val){
    // overflow check
    if (rear == N - 1){
        cout << "queue is full\n";
        return;
    }

    // if queue is empty
    if (front == -1){
        front = 0;
    }

    rear++;                // works for both first and normal insertion
    queue[rear] = val;

    cout << "insertion successful\n";
}

void deQ(){
    // underflow check
    if (front == -1){
        cout <<"queue is empty\n";
        return;
    }
    cout <<queue[front]<<endl;

    if (front == rear){
        front = rear = -1;      //reset queue
    }
    else {
        front ++;
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
                deQ();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-3.\n";
        }
    }
}