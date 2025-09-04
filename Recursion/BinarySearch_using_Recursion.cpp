#include<iostream>
using namespace std;

void print(int arr[], int s, int e){
    for(int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool BinarySearch(int arr[], int s, int e, int k){
    cout<<endl;
    print(arr, s, e);

    //base case
    if(s>e) return false;

    int mid = s + (e-s)/2;
    cout<<"Value for array mid is: "<<arr[mid]<<endl;

    if(arr[mid] == k) return true;

    if(arr[mid] < k) 
        return BinarySearch(arr, mid+1, e, k);
    else 
        return BinarySearch(arr, s, mid-1, k);
}

int main(){
    cout<<"NOTE: Enter the element in sorted order."<<endl;

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key, start = 0, end = n;
    cout<<"Enter the element you want to search in an array: ";
    cin>>key;

    if(BinarySearch(arr, start, end, key)){
        cout<<"Element is present in an array.";
    }
    else{
        cout<<"Element is not present in an array.";
    }

     return 0;
}