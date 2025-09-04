#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>>& M, int a, int b, int n){
    if(M[a][b] == 1) return true;
    else return false;
}

int celebrity(vector<vector<int>>& M, int n){
    stack<int> st;

    for(int i=0; i<n; i++){
        st.push(i);
    }

    while(st.size() > 1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(M, a, b, n)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int candidate = st.top();

    bool rowChk = false;
    int zeroCnt = 0;

    for(int i=0; i<n; i++){
        if(candidate != i){
            if(M[candidate][i] == 0){
                zeroCnt++;
            }
        }
    }

    if(zeroCnt == n-1){
        rowChk = true;
    }

    bool colChk = false;
    int oneCnt = 0;

    for(int i=0; i<n; i++){
        if(candidate != i){
            if(M[i][candidate] == 1){
                oneCnt++;
            }
        }
    }

    if(oneCnt == n-1){
        colChk = true;
    }

    if(rowChk == true && colChk == true){
        return candidate;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout<<"Enter the total number of rows and columns: ";
    cin>>n;
    
    vector<vector<int>> mat(n, vector<int>(n));
    cout<<"Only enter 0 and 1 as element in matrix.";
    cout<<endl;

    int input;
    cout<<"Enter the elements of matrix: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>input;
            if(input == 0 || input == 1){
                mat[i][j] = input; 
            }
            else{
                cout<<"You entered invalid number. Please try again!"<<endl;
                return 0;
            }
        }
    }

    cout<<"Your matrix is:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    int result = celebrity(mat, n);

    cout<<"The Celebrity in a party is: "<<result<<endl;

    return 0;
}