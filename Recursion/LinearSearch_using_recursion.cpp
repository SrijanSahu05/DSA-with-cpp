#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int k, int size){
    //base case
    if(size == 0) return false;

    if(arr[0] == k) return true;
    else{
        int remainingPart = LinearSearch(arr+1, k, size-1);
        return remainingPart;
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the Element you want to find in an array: ";
    cin>>key;

    if(LinearSearch(arr, key, n)){
        cout<<"The entered element is present in array.";
    }
    else{
        cout<<"The entered element is not present in array.";
    }

    return 0;
}