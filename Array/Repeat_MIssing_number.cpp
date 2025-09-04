/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears 
exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers 
a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissingNumber(vector<vector<int>>& grid) {
    int n = grid.size();
    int total_elements = n * n;
    vector<int> freq(total_elements + 1, 0);
    vector<int> ans(2);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            freq[grid[i][j]]++;
        }
    }

    /*cout << "Element : Frequency" << endl;
    for(int i = 1; i <= total_elements; i++){
        cout << i << " : " << freq[i] << endl;
    }*/

    for(int i = 1; i <= total_elements; i++){
        if(freq[i] == 2){
            ans[0] = i; // repeating number
        }
        else if(freq[i] == 0){
            ans[1] = i; // missing number
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> ans = repeatAndMissingNumber(grid);
    cout << "Repeating and Missing numbers are: " << ans[0] << " " << ans[1];
    return 0;
}