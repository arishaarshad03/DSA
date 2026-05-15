#include <iostream>
using namespace std;

#define N 10
int arr[N] = {56, 78, 96, 28, 54, 45, 36, 65, 89, 53};

void merge(int left, int mid, int right){
    int sizeleft= mid - left + 1;     //left half size
    int sizeright = right - mid;        //right half size

    // temporary arrays
    int L[sizeleft], R[sizeright];

    // copy data into temp array
    for (int i = 0; i <sizeleft; i ++){
        L[i]= arr[left + i];
        
    }
    for(int j = 0; j < sizeright; j++){
        R[j]= arr[mid + 1 + j];
    }
    int i =0;       //traverse left subarray
    int j = 0;      //traverse right subarray
    int k = left;   //starts writing where the subarray begins

    // merge the temporary arrays after sorting
    while (i < sizeleft && j < sizeright){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    while (i < sizeleft){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < sizeright){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int left, int right){
    if (left >= right){
        return;     //1 or 0 elements, base case
    }
    int mid = (left + right)/2;

    // sort left half
    mergesort(left, mid);

    // sort right half
    mergesort(mid + 1, right);

    // merge them
    merge (left, mid, right);
}


int main (){
    mergesort (0, N-1);
    cout<<"sorted array: ";
    for (int i = 0; i < N; i++){
        cout<< arr[i]<< " ";
    }
}