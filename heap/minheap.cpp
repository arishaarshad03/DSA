#include<iostream>
using namespace std;

#define N 100
int arr[N];

int hsize = 0;
void upheapify(int index){
    while (index > 0)
    {
        int parent = (index - 1 )/2;

        if(arr[parent] > arr[index]){
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else{
            break;
        }
    }
}

void insert (int val){
    arr[hsize] = val;
    upheapify(hsize);
    hsize++;
}

void downheapify(int index){
    while (index < hsize){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < hsize && arr[left] < arr[smallest])
            smallest = left;

        if (right < hsize && arr[right] < arr[smallest]){
            smallest = right;
        }
        if (index != smallest){
            swap (arr[smallest], arr[index]);
            index = smallest;
        }
        else{
            break;
        }
    }
}

void remove(){
    if (hsize == 0){
        cout<<"heap is empty\n";
        return;
    }
    hsize--;
    arr[0] = arr[hsize];
    downheapify(0);
}

void heapsort(){
    int orignalsize = hsize;
    int i = hsize - 1;
    while (i > 0){
        swap (arr[0], arr[i]);
        hsize--;
        downheapify(0);

        i--;
    }
    hsize = orignalsize;
}
void display() {
    if (hsize == 0) {
        cout << "Heap is empty\n";
        return;
    }

    for (int i = 0; i < hsize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- MIN HEAP MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete Root\n";
        cout << "3. Display Heap\n";
        cout << "4. Heap Sort\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                remove();
                break;

            case 3:
                display();
                break;

            case 4:
                heapsort();
                cout<< "sorted: \n";
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}