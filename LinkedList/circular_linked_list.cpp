#include<iostream>
#include <cstdlib>
using namespace std;

struct LLNode{
    int data;
    LLNode* next;
};

LLNode* list = NULL;

void insert (int val){
    LLNode* temp = new LLNode;
    temp -> data = val;
    temp ->next = NULL;

    if (list == NULL){
        temp -> next = temp;
        list = temp;
        return;
    }
    else{
        LLNode* cur = list;
        while (cur -> next != list){
            cur = cur-> next;
        }
        cur ->next = temp;
        temp -> next = list;
    }
}

void display (){
    LLNode* cur = list;
    if (list == NULL){
        cout <<"List is empty\n";
        return;
    }
    else{
        do{
            cout << cur ->data <<"  ";
            cur = cur ->next;
        }
        while(cur != list);
    }
    cout <<endl;
}

void search(int val){
    LLNode* cur = list;
    if (list == NULL){
        cout <<"List is empty\n";
        return;
    }
    else {
        int pos = 1;
        do {
            if (cur -> data == val){
                cout<<"value "<<val<<" found at position: "<<pos;
                return;
            }
            cur = cur ->next;
            pos ++;

        }
        while (cur != list);
    }
    cout <<"value not found\n";
}

void del(int val){
    LLNode* cur = list;
    if (list == NULL){
        cout <<"List is empty\n";
        return;
    }
    // only one node exists and it has the value
    if (list ->next == list && list ->data == val){
        delete list;
        list = NULL;
        return;
    }
    // deleting the head node
    if (list->data == val){
        LLNode* last = list;        //find the last node
        do{
            last = last-> next;
        }while (last -> next != list);
        list = list->next;
        last-> next = list;
        delete cur;
        return;
    }
    // deleting the middle or end node
    LLNode* prev = list;
    cur = cur -> next;
    do{
        if (cur-> data == val){
            prev -> next = cur -> next;
            delete cur;
            return;

        }
        prev = cur;
        cur = cur -> next;
    }
    while (cur != list);

    // if value is not in list:
    cout<< "value not found!";
    
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\n===== circular Linked List Menu =====\n";
        cout << "1. Insert value\n";
        cout << "2. Display List\n";
        cout << "3. Search Value\n";
        cout << "4. Delete Value\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                del(value);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-5.\n";
        }
    }
}
