#include <iostream>
#include <cstdlib>
using namespace std;

struct LLNode{
    int data;
    LLNode* next;
};
LLNode* top = nullptr;

void push(int val){
    LLNode* newnode = new LLNode;
    newnode ->data = val;
    newnode ->next = top;

    top = newnode;
    cout <<"value "<<val<< " pushed successfully\n";
}


void pop (){
    if (top == nullptr){
        cout <<"stack underflow\n";
        return;
    }
    LLNode* temp = top;
    cout << "popped: " << temp->data << endl;

    top = top->next;
    delete temp;

}

void display_top_to_bottom() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    LLNode* cur = top;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n===== stack Menu using linked list =====\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. display top to bottom\n";
        cout << "4. exit\n";


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
                break;
            case 3:
                display_top_to_bottom();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-4.\n";
        }
    }
}
