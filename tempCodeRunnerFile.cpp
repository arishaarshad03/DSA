#include <iostream>
using namespace std;
int main (){
    int input[10] = {12,34,54,15,24,90,87,74,21,69};
    int to_search;
    cin >> to_search;
    for(int i = 0; i<10; i++) {
        if (input[i] == to_search) {
            cout << "Element found at index: " << i;
            return 0;
        }
    }
    cout << "Element not found";

    return 0;

}