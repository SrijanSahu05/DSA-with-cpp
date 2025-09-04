#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& heights, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size);

    for(int i=size-1; i>=0; i--){
        int curr = heights[i];

        while(st.top() != -1 && !st.empty() && heights[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int>& heights, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size);

    for(int i=0; i<size; i++){
        int curr = heights[i];

        while(st.top() != -1 && !st.empty() && heights[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights, int size){
    vector<int> next(size);
    next = nextSmallerElement(heights, size);

    vector<int> prev(size);
    prev = prevSmallerElement(heights, size);

    int area = INT_MIN;

    for(int i=0; i<size; i++){
        int l = heights[i];

        if(next[i] == -1){
            next[i] = size;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> rectangles(n);

    cout<<"Enter the length of rectangles: ";
    for(int i=0; i<n; i++){
        cin>>rectangles[i];
    }

    cout<<"The length of each rectangle array are: ";
    for(int it : rectangles){
        cout<<it<<" ";
    }
    cout<<endl;

    int result = largestRectangleArea(rectangles, n);

    cout<<"The largest rectangle area is: "<<result<<endl;

    return 0;
}

/*

Time Complexity:- O(n)
Space Complexity:- O(n)

*/