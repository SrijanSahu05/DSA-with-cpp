/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.
 
Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums){
    map<int,int> mp;

    for(int i : nums){
        mp[i]++;
    }

    int freq_ele = 0;
    int major_ele;

    for(auto it : mp){
        if(it.second > freq_ele){
            freq_ele = it.second;
            major_ele = it.first;
        }
    }

    return major_ele;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<"Major element in an array: "<<majorityElement(nums);
    return 0;
}