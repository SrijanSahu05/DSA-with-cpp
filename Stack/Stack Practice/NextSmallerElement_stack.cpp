#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//This function finds the next smaller element on right side of array.
vector<int> NextSmallerElement_right_of_arr(vector<int>& arr, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size);

    for(int i=size-1; i>=0; i--){
        int curr = arr[i];

        while(!st.empty() && st.top() >= curr){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(curr);
    }

    return ans;
}

//This function finds the next smaller element on left side of array.
vector<int> NextSmallerElement_left_of_arr(vector<int>& arr, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size);

    for(int i=0; i<size; i++){
        int curr = arr[i];

        while(!st.empty() && st.top() >= curr){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(curr);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the element of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"The Array is: ";
    for(int it : arr){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> NextRightSmaller = NextSmallerElement_right_of_arr(arr,n);
    vector<int> NextLeftSmaller = NextSmallerElement_left_of_arr(arr,n);

    cout<<"The Next Smaller Element right of array is: ";
    for(int it : NextRightSmaller){
        cout<<it<<" ";
    }
    
    cout<<endl;

    cout<<"The Next Smaller Element left of array is: ";
    for(int it : NextLeftSmaller){
        cout<<it<<" ";
    }

    return 0;
}