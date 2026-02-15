#include<iostream>
#include <cstdlib>
using namespace std;

#define n 100
int stack[n];
int top = -1;        //top points to last inserted element

void push (int val){
    if (top >= n-1 )
    {
        cout << "stack overflow! can not push "<<val<<endl;
        return;
    }
    top++;
    stack[top] = val;
    cout<<"value "<<val << " pushed sucessfully";
}

void pop(){
    if (top <0)
    {
        cout<< "stack underflow\n";
        return;
    }
    cout<< "popped: "<<stack[top]<<endl;
    top--;
}

void display_bottom_to_top() {
    if (top < 0) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack from bottom to top: ";
    for (int i = 0; i <=top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void display_top_to_bottom() {
    if (top < 0) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    for (int i = top; i >= 0; i--) {   
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n===== Stack Menu =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display bottom to top\n";
        cout << "4. Display top to bottom\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;;
            case 3:
                display_bottom_to_top();
                break;
            case 4:
                display_top_to_bottom();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-5.\n";
        }
    }
}