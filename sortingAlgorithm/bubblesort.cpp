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

    // bubble sort
    for(int i = 0; i < n-1; i++){
        bool swap = false;
        for (int j = 0; j< n-i-1; j++){
            if (array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]= temp;
                swap = true;

            }
        }
        if (!swap){
            break;
        }
    }
    cout<< "sorted array: ";
    for (int i =0; i< n; i++){
        cout<< array[i]<< " ";
    }
}