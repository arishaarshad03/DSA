#include <iostream>
using namespace std;

int main() {
    // enter size
    int n;
    cout<< "enter size:";
    cin>> n;

    // enter array
    cout<< "enter array: ";
    int array[n];
    for(int i = 0; i < n; i++){
        cin>> array[i];
    }
    
    // insertion sort
    for (int i = 1; i < n; i++) {
        int key = array[i];     // element to insert
        int previous = i - 1;

        // shift elements to the right
        while (previous >= 0 && array[previous] > key) {
            array[previous + 1] = array[previous];
            previous--;
        }

        // insert key at correct position
        array[previous + 1] = key;
    }

    cout << "sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
