//Implementing Stack using C++ STL function.

//Including header files
#include<iostream>
#include<stack>

using namespace std;

int main(){
    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    cout<<"Size of stack is:"<<s.size()<<endl;  /*s.size() -> gives the size of stack*/

    //pop
    s.pop();

    cout<<"Top Element of Stack: "<<s.top()<<endl; /*s.top() -> gives the top element of the stack*/

    if(s.empty()){                      /*s.empty() -> check if stack is empty or not*/
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}