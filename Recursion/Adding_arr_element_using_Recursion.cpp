#include<iostream>
using namespace std;

/*
int arr_sum(int arr[], int size, int sum, int i){
    //base case
    if(size == 0) return sum;

    sum += arr[i];

    return arr_sum(arr, size-1, sum, i+1);
}
*/

int arr_sum(int arr[], int size){
    //base case
    if(size == 0) return 0;

    return arr[0] + arr_sum(arr+1, size-1);
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //int sum = 0,idx = 0;
    //int ans = arr_sum(arr, n, sum, idx);
    int ans = arr_sum(arr, n);
    cout<<"Sum of array elements is: "<<ans<<endl;

    return 0;
}