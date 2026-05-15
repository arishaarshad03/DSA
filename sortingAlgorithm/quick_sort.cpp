#include <iostream>
using namespace std;

#define N 6
int arr[N] = { 96,78, 56, 45,  28, 12};

int set_pivot(int left, int right){
    int pivot_ind = (left + right)/2;
    int pivot = arr[pivot_ind];

    while (left < right){
        
        while (right > pivot_ind){
            if (arr[right] < pivot){
                swap (arr[pivot_ind], arr[right]);
                pivot_ind = right;
            }
            else {
                right --;
            }

        }

        while (left < pivot_ind){
            if (arr[left] > pivot){
                swap (arr[pivot_ind], arr[left]);
                pivot_ind = left;
            }
            else {
                left ++;
            }

        }
    }
    return pivot_ind;
}

void quicksort (int left, int right){
    if (left < right)
    {
        int pivotindex = set_pivot(left, right);
        quicksort(left, pivotindex-1);
        quicksort (pivotindex+1 , right);
    }
}

int main (){
    quicksort (0, N-1);
    cout<<"sorted array: ";
    for (int i = 0; i < N; i++){
        cout<< arr[i]<< " ";
    }
}