#include <iostream>
using namespace std;

const int Size = 10;
int table[Size];
int flag[Size];     //0 = empty, 1= occupied, 2= deleted

// initialize table and make it all empty
void initialize(){
    for (int i = 0; i <Size; i++)
    flag[i] = 0;
}
int hashfunc (int key){
    if (key < 0)
        key = -key;
    return key % Size;
}

void insert(int key){
    int index = hashfunc(key);
    int orignalindex = index;

    // collision
    while (flag[index]==1){
        index = (index + 1)% Size;      //check next index if its empty
        if (index == orignalindex){
            cout<< "hash table is full, cannot insert "<<key<< endl;
            return;
        }

    }
    table[index] = key;
    flag[index] = 1;     //mark as occupied
    cout << "Inserted " << key << " successfully at index " << index << endl;
}

void search (int key){
    int index = hashfunc(key);
    int orignalindex = index;

    // stops only when empty space is found
    while (flag[index] != 0){
        if (flag[index] == 1 && table[index] == key){
            cout <<"key "<< key <<" found at index: "<<index<<endl;
            return;
        }
        index = (index + 1)% Size;
        if (index == orignalindex){
            break;
        }
    }
    cout << "Key " << key << " not found\n";
}

void remove (int key){
    int index = hashfunc(key);
    int orignalindex = index;

    // stops only when empty space is found
    while (flag[index] != 0){
        if (flag[index] == 1 && table[index] == key){
            flag [index] = 2;       //mark deleted
            cout << "Key " << key << " deleted successfully at index " << index << endl;
            return;
        }
        index = (index + 1)% Size;
        if (index == orignalindex){
            break;
        }
    }
    cout << "Key " << key << " not found\n";

}

void display(){
    cout <<"hash table: \n";
    for (int i = 0; i < Size; i++){
        cout << i << " -> ";
        if (flag[i]== 0){
            cout<< "empty";
        }
        else if (flag[i] == 2){
            cout << "deleted";
        }
        else {
            cout << table[i];
        }
        cout << endl;
    }
}
int main() {
    initialize();
    int choice, key;

while(true) {
        cout <<"----- Linear Probing -----\n";
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
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
