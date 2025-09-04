#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& myStack, int ele){
    if(myStack.empty()){
        myStack.push(ele);
        return;
    }
    
    int num = myStack.top();
    myStack.pop();
    
    //recursive call
    insertAtBottom(myStack, ele);
    
    myStack.push(num);
}

void Reverse(stack<int> &St) {
    //base case
    if(St.empty()){
        return;
    }
    
    int num = St.top();
    St.pop();
    
    //recursive call
    Reverse(St);
    
    insertAtBottom(St, num);
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

    Reverse(st);

    cout<<"The reversed stack is: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}