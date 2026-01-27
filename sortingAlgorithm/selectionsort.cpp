#include <iostream>
using namespace std;

int main (){
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
    
    // selection sort
    for (int i =0; i < n-1; i++){
        int smallestIdx = i;
        for (int j = i+1; j < n; j++){
            if (array[smallestIdx]> array[j]){
                smallestIdx= j;
            }
        }
        // swap smalest with current position
        int temp = array[i];
        array [i] = array[smallestIdx];
        array[smallestIdx] = temp;
    }
    cout<< "sorted array: ";
    for (int i = 0; i < n; i++){
        cout << array[i] <<" ";
    }
}
