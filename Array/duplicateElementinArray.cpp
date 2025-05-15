#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> arr = {1,2,1,2,3,4,3,2,1,5,5,4,3,6};
    vector<int> newarr;
    int n = arr.size();
    int count = 0,cnt=0;

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count > 1){
            newarr.push_back(arr[i]);
            count = 0;
        }
    }

    

    for(int i=0; i<newarr.size(); i++){
        cout<<newarr[i]<<" ";
    }

    return 0;
}