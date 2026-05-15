#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX];
int hsize = 0;

void upHeapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void insertVal(int value) {
    arr[hsize] = value;
    upHeapify(hsize);
    hsize++;
}

void downHeapify(int index) {
    while (index < hsize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < hsize && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < hsize && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void deleteRoot() {
    if (hsize == 0) {
        cout << "Heap is empty\n";
        return;
    }
    hsize--;
    arr[0] = arr[hsize];
    downHeapify(0);
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

void heapSort() {
    int originalSize = hsize;

    int i = hsize - 1;

    while (i > 0) {
        swap(arr[0], arr[i]);  // move max to end
        hsize--;               // reduce heap size
        downHeapify(0);        // fix heap

        i--;                   // move backward
    }

    hsize = originalSize; // restore if needed
}



int main() {
    int choice, value;

    do {
        cout << "\n--- MAX HEAP MENU ---\n";
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
                insertVal(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                heapSort();
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