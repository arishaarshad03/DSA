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
    cout << "enter array: ";
    for (int i = 0; i<n; i++){
        cin>> array[i];
    }

    // take target as input 
    int target;
    cout<< "enter num to find: ";
    cin>> target;

    // searching algo 
    for(int i = 0; i < n; i++){
        if (target == array[i]){
            cout << "number "<< target<<" found at index: "<< i << endl;
            found = true;
        }
        
    }
    if (!found){
        cout<< "number not found!";
        return -1;
    }
}