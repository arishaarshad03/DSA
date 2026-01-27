#include<iostream>
#include <cstdlib>
using namespace std;

struct doublenode{
    int data;
    doublenode* prev;
    doublenode* next;

};
doublenode* list = NULL;

void insert(int val){
    doublenode* temp = new doublenode;
    temp ->data = val;
    temp ->next = NULL;
    temp ->prev = NULL;
    
    if (list == NULL){
        list = temp;
        return;
    }
    else{
        doublenode* cur = list;
        while (cur ->next != NULL)
        {
            cur = cur ->next;
        }
        cur ->next = temp;
        temp ->prev = cur;
        return;
    }

}

void displayforward(){
    if (list ==  NULL){
        cout <<"list is empty\n";
        return;
    }
    doublenode* cur = list;
    while (cur != NULL){
        cout << cur ->data <<"  ";
        cur = cur -> next;
    }
    cout <<endl;
}

void displayback(){
    if (list ==  NULL){
        cout <<"list is empty\n";
        return;
    }
    doublenode* last = list;
    while (last ->next != NULL){
        last = last ->next;
    }
    do {
        cout << last ->data <<"  ";
        last = last->prev;
    }while (last != NULL);

    cout <<endl;
}

void search (int val){
    bool found = false;
    if (list ==  NULL){
        cout <<"list is empty\n";
        return;
    }
    doublenode* cur = list;
    int pos = 1;
    while (cur !=NULL){
        if (cur ->data == val){
            found = true;
            cout <<"value "<<val <<" found at position: "<<pos<<"\n";
        }
        cur = cur ->next;
        pos++;
    }
    if (!found){
        cout <<"value doesn't exist\n";
    }
}

void remove(int val){
    if (list ==  NULL){
        cout <<"list is empty\n";
        return;
    }
    // removing the only node
    if (list->data == val && list ->next == NULL){
        delete list;
        list = NULL;
        return;
    }
    // remove head
    doublenode* cur = list;
    if (list ->data == val){
        list = list ->next;
        list ->prev = NULL;
        delete cur;
        return;
    }
    // remove from middle or end
    while (cur != NULL){
        if (cur ->data == val){
            // remove the end node
            if (cur ->next == NULL){
                cur ->prev ->next = NULL;
                delete cur;
                return;
            }
            // valur found at mid
            cur ->prev ->next = cur ->next;
            cur ->next ->prev = cur ->prev;
            delete cur;
            return;

        }
        cur = cur->next;
    }
    
    cout <<"value not found\n";
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n===== doubly Linked List Menu =====\n";
        cout << "1. Insert value\n";
        cout << "2. forward Display List\n";
        cout << "3. backward display Value\n";
        cout << "4. search Value\n";
        cout << "5. delete value\n";
        cout << "6. exit\n";


        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                displayforward();
                break;
            case 3:
                displayback();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                remove(value);
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-6.\n";
        }
    }
}
