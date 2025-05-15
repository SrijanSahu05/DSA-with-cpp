#include<iostream>
#include<vector>
using namespace std;

int main(){
     vector<int> v = {0,0,0,0,0,0,0};

     int n = v.size();
     
     vector<int> temp;
     int len = temp.size();
     int i=0;

     while(len != n){
        if(v[i] == 0){
            temp.push_back(v[i]);
            temp.push_back(0);
        }
        else
        temp.push_back(v[i]);
        
        len = temp.size();
        i++;
     }

     v.clear();

     for(int i=0; i<len; i++)
     v.push_back(temp[i]);

    for(int num : v)
    cout<<num<<" ";

    return 0;
}