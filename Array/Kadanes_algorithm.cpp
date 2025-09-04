/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n^2) & Space Complexity: O(1)
/*
int maxSubArray(vector<int>& nums) {
    int val = nums[0];

    for(int i=0; i<nums.size(); i++){
        int currsum = 0;
        for(int j=i; j<nums.size(); j++){
            currsum += nums[j];

            val = max(val, currsum);
        }
    }

    return val;
}
*/

// Time Complexity: O(n) & Space Complexity: O(1)
int maxSubArray(vector<int>& nums){
    int res = nums[0];

    int maxEnding = nums[0];

    for(int i=1; i<nums.size(); i++){
        maxEnding = max(nums[i], maxEnding + nums[i]);
        res = max(res, maxEnding);
    }

    return res;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}