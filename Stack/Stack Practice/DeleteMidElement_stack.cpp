#include<iostream>
#include<stack>
using namespace std;

int deleteMiddleElement(stack<int>& container, int cnt, int N){
    //base case
    if(cnt == N/2){
        int deletedElement = container.top();
        container.pop();
        return deletedElement;
    }

    int num = container.top();
    container.pop();

    //Recursive Call
    int deletedElement = deleteMiddleElement(container, cnt+1, N);
    container.push(num);
    return deletedElement;
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

    int count = 0;
    int deleted_Mid_Element = deleteMiddleElement(st, count, n);
    cout<<"The deleted middle element is: "<<deleted_Mid_Element<<endl;
    cout<<"The stack elements are: ";

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}