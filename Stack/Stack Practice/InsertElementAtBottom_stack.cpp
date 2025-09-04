#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    int num = myStack.top();
    myStack.pop();
    
    solve(myStack, x);
    
    myStack.push(num);
}
    
stack<int> insertAtBottom(stack<int> st, int x) {
    solve(st, x);
    return st;
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

    int x;
    cout<<"Enter the number you want to insert at bottom of stack: ";
    cin>>x;

    st = insertAtBottom(st, x);

    cout<<"The new stack is: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}