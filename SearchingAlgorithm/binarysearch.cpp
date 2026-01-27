#include <iostream>
using namespace std;

int main (){
    int n;  //size
    bool found = false;    //flag

    // take size as input 
    cout << "enter size: ";
    cin >> n;

    // take array as input 
    int array[n];
    cout << "enter sorted array: ";
    for (int i = 0; i<n; i++){
        cin>> array[i];
    }

    // take target as input 
    int target;
    cout<< "enter num to find: ";
    cin>> target;

    // binary search algo
    int start = 0;
    int end = n-1;
    while (start <= end){
        int mid = (start + end) / 2;

        if (array[mid]< target){
            start = mid +1;
        }
        else if (array [mid] > target){
            end = mid -1;
        }
        else if (array[mid] == target){
            cout<< "target "<<target<<" found at index: "<<mid <<endl;
            found = true;
            break;
        }

    }

    if (!found){
        cout<< "target not found!";

    }

    return -1;

}
