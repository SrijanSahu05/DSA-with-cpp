//find maximum and minimum element in array method-1.
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of the array:";
	cin>>n;
	int arr[100];
	cout<<"Enter the elements in the array:-"<<endl;
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	int max=arr[0];
	int min=arr[0];
	for(int i=0; i<n; i++){
		if(arr[i] > max)
			max = arr[i];
		else if(arr[i] < min)
			min = arr[i];
	}
	
	cout<<"Minimum element of array is:"<<min<<endl;
	cout<<"Maximum element of array is:"<<max<<endl;
	
	return 0;
}
