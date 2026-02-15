#include <iostream>
using namespace std;

#define Size 11     //should be prime for quadratic searching
int table[Size];
int flag[Size];

void initialize(){
    for(int i = 0; i < Size; i++){
        flag[i] = 0;
    }
}

int hashfunction(int key){
    if (key < 0)
        key = -key;
    return key % Size;
}

void insert(int key){
    int hash = hashfunction(key);
    int i = 0;
    int index;

    while (i < Size){
        index = (hash + i*i)% Size;    

        if (flag[index] != 1){      //empty or deleted
            table[index] = key;
            flag[index] = 1;
            cout<< "inserted "<<key<<" at index "<<index <<endl;
            return;
        }
        i++;
    }
    cout << "Hash table is full, cannot insert " << key << endl;
}

void search (int key){
    int hash = hashfunction(key);
    int i = 0;
    int index;

    while (i < Size){
        index = (hash + i*i)% Size;

        if (flag[index]== 0){
            // stop at empty
            cout<< "value not found\n";
            return;
        }

        if (flag[index]== 1 && table[index]== key){
            cout<< "value found at index: "<<index<< endl;
            return;
        }
        i++;
    }
    cout << "value not found\n";
}

void remove (int key){
    int hash = hashfunction(key);
    int i = 0;
    int index;

    while (i < Size){
        index = (hash + i*i)% Size;

        if (flag[index]== 0){
            // stop at empty
            cout<< "value not found\n";
            return;
        }

        if (flag[index]== 1 && table[index]== key){
            flag[index]=2;
            cout<< "value deleted at index: "<<index<< endl;
            return;
        }
        i++;
    }
    cout << "value not found\n";
}
void display(){
    for(int i = 0; i < Size; i++){
        cout << i << " -> ";
        if(flag[i] == 0)
            cout << "EMPTY";
        else if(flag[i] == 2)
            cout << "DELETED";
        else
            cout << table[i];
        cout << endl;
    }
}
int main() {
    initialize();
    int choice, key;

while(true) {
        cout <<"----- Quadratic Probing -----\n";
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
