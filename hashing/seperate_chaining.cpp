#include <iostream>
using namespace std;

#define Size 10

struct Node{
    int data;
    Node* next;
};

Node* table[Size];

void initialize(){
    for (int i=0; i< Size; i++){
        table[i] = nullptr;
    }
}

int hashfunc(int key){
    if (key < 0){
        key = -key;
    }
    return key % Size;
}

void insert(int val){
    int index = hashfunc(val);
    // make new node 
    Node* temp = new Node;
    temp ->data = val;
    temp->next = nullptr;

    // inserting first node
    if (table[index] == nullptr){
        table[index] = temp;
        cout << "value "<< val << " inserted at index: "<<index <<endl;
        return;
    }
    // inserting at the end 
    Node* cur = table[index];
    while (cur ->next != nullptr){
        cur = cur ->next;
    }
    cur ->next = temp;

    cout << "value "<< val << " inserted at index: "<<index<< endl;

}

void search (int val){
    int index = hashfunc(val);

    Node* cur = table[index];
    while (cur != nullptr){
        if (cur ->data == val){
            cout <<"value found at index: "<<index;
            return;
        }
        cur = cur ->next;

    }
    cout <<"value " << val << " is not found\n";
}

void remove (int val){
    int index = hashfunc(val);

    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr){

        if (cur ->data == val){

            // deleting first node
            if (prev == nullptr){
                table[index] = cur ->next;
            }
            else {
                // deleting middle or last node
                prev ->next = cur ->next;
            }
            delete cur;
            cout <<"value deleted at index: "<<index;
            return;
        }
        prev = cur;
        cur = cur ->next;
    }
    cout <<"value " << val << " is not found\n";
}

void display(){
    for (int i = 0; i < Size; i ++){
        cout <<i <<" --> ";
        
        Node* cur = table[i];
        while (cur != nullptr){
            cout << cur ->data<< "  ";
            cur = cur->next;

        }
        cout <<"Null "<<endl;
    }
}

// Main function
int main() {
    initialize();
    int choice, key;

    while(true) {
        cout << "\n---- Separate Chaining Hash Table ----\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                remove(key);
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}