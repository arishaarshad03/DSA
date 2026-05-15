#include <iostream>
#include <cstdlib>
using namespace std;

struct LLNode
{
    int data;
    LLNode* next;
};

LLNode* list = NULL;
void indexinsert(int pos, int val){
    LLNode* temp = new LLNode;
    temp ->data = val;
    temp ->next = nullptr;

    if (pos == 1){
        temp ->next = list;
        list = temp;
        return;
    }
    LLNode* cur = list;

    // move to pos -1
    for (int i = 1; i < pos - 1; i++){
        if (cur == nullptr){
            cout <<"position out of range\n";
            return;
        }
        cur = cur ->next;
    }
    temp ->next = cur ->next;
    cur ->next = temp;

}

void push_front (int val){
    LLNode* newnode = new LLNode;
    newnode -> data = val;

    if (list == NULL){
        newnode -> next = NULL;
        list = newnode;
        return;
    }
    else{
        newnode ->next = list;
        list = newnode;
    }
    cout <<"insertion sucessful!\n";
}

void push_back(int val){
    LLNode* newnode = new LLNode;
    newnode -> data = val;
    newnode -> next = NULL;

    if (list == NULL){
        list = newnode;
        return;
    }
    else{
        LLNode* cur = list;
        while(cur -> next != NULL){
            cur = cur->next;
        }
        cur ->next = newnode;
    }
    cout <<"insertion sucessful!\n";
}

void sorted_insert(int val){
    LLNode* temp = new LLNode;
    temp ->data = val;
    temp ->next = NULL;

    if (list == NULL){
        list = temp;
    } 
    else{
        if (val <= list ->data){
            temp -> next = list;
            list = temp;
            return;
        }
        LLNode* cur = list;
        while (cur ->next != NULL){
            if (cur ->data < val && cur->next ->data >= val){
                temp ->next = cur ->next;
                cur ->next = temp;
                return;
            }
            cur = cur ->next;
        }
        cur ->next = temp;
    }
    cout <<"insertion sucessful!\n";
}

void display(){
    LLNode* cur = list;
    if (cur == NULL){
        cout << "list is empty!\n";
        return;
    }
    else {
        while (cur != NULL){
            cout << cur-> data << "  ";
            cur = cur -> next;
        }
        cout <<endl;
    }
}

void rec_display(LLNode* head) {
    if (head == nullptr)   // base case
        return;

    cout << head->data << "  ";
    rec_display(head->next);
}

void rec_reverse_display(LLNode* head = list) {

    if (head == nullptr) {   // base case
        return;
    }

    rec_reverse_display(head->next);   // go till end first
    cout << head->data << "  ";        // print while coming back
}

void search (int val){
    bool found = false;
    LLNode*cur = list;
    if (cur == NULL){
        cout << "list is empty!\n";
        return;
    }
    int pos = 1;
    while (cur != NULL){
        if (cur ->data == val){
            cout<< "value "<<val<<" found at position: "<<pos<< "\n";
            found = true;
        }
        cur = cur->next;
        pos++;
    }
    if (!found){
        cout<< "value "<<val<<" not found!";
        return;
    }
    
}
void remove(int val){
    bool deleted = false;
    LLNode* cur = list;
    LLNode* prev = NULL;
    if (cur == NULL){
        cout << "list is empty!\n";
        return;
    }
    while (cur != NULL){
        // delete head
        if (cur -> data == val){
            deleted = true;
            if (prev ==NULL){
                list = list->next;
                LLNode* temp = cur;
                cur = cur ->next;
                delete temp;
            }
            else{       //middle or tail
                prev->next = cur ->next;
                LLNode* temp = cur;
                cur = cur ->next;
                delete temp;

            }
        }
        else{
            prev = cur;
            cur = cur ->next;
        }
    }
    if (deleted){
        cout<< "value "<<val <<" deleted from all occurances\n";
    }
    else {
        cout <<"value not found\n";
    }
}

LLNode* middle (LLNode* list){
    LLNode* slow = list;
    LLNode* fast = list ->next;
    while (fast != nullptr && fast ->next != nullptr){
        slow = slow ->next;
        fast = fast ->next ->next;
    }

    // slow will be at middle
    return slow;
}
LLNode* mergelist(LLNode* left, LLNode* right){
    if (left == nullptr){
        return right;
    }
    if (right == nullptr){
        return left;
    }
    LLNode* result = nullptr;

    if (left ->data <= right ->data){
        result = left;
        result ->next = mergelist(left->next, right);
    }
    else{
        result = right;
        result->next = mergelist(left, right->next);
    }
    return result;
}
LLNode* mergesort(LLNode* list){
    if (list == nullptr || list ->next == nullptr){
        return list;
    }
    LLNode* mid = middle(list);
    LLNode* second = mid ->next;
    mid ->next = nullptr;
    
    LLNode* left = mergesort(list);
    LLNode* right = mergesort(second);

    return mergelist(left, right);

}

int main() {
    int choice;
    int value;
    int pos;

    while (true) {
        cout << "\n===== Singly Linked List Menu =====\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Back\n";
        cout << "3. sorted insert\n";
        cout << "4. index specific insert\n";
        cout << "5. Display List\n";
        cout << "6. Display reverse List\n";
        cout << "7. Search Value\n";
        cout << "8. Delete Value\n";
        cout << "9. merge sort\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                push_front(value);
                break;
            case 2:
                cout << "Enter value to insert at back: ";
                cin >> value;
                push_back(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                sorted_insert(value);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                indexinsert(pos, value);
                break;
            case 5:
                rec_display(list);
                break;
            case 6:
                rec_reverse_display();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                remove(value);
                break;
            case 9:
                list = mergesort(list);
                rec_display(list);
                break;
            case 10:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1-9.\n";
        }
    }
}
