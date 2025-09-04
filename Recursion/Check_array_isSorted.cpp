#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    //base case
    if(size == 0 || size == 1) return true;
    
    if(arr[0] > arr[1]) return false;
    
    return isSorted(arr+1, size-1);
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array:";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    if(isSorted(arr, n)){
        cout<<"Array is sorted."<<endl;
    }
    else{
        cout<<"Array is not sorted."<<endl;
    }

    return 0;
}