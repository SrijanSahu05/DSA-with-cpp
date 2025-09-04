#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>& s, int ele){
    if(s.empty() || (!s.empty() && s.top() < ele)){
        s.push(ele);
        return;
    }

    int n = s.top();
    s.pop();

    //Recursive call
    sortedInsert(s, ele);

    s.push(n);
}

void sortStack(stack<int>& st){
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call
    sortStack(st);

    sortedInsert(st, num);
}

int main(){
    int n;
    cout<<"Enter the size of stack: ";
    cin>>n;

    stack<int> st;
    int data;

    cout<<"Enter the elements of stack: ";
    for(int i=0; i<n; i++){
        cin>>data;
        st.push(data);
    }

    sortStack(st);

    cout<<"The sorted stack is: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}