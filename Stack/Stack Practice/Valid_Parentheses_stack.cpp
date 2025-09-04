#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string str){
    stack<char> st;

    for(char ch : str){
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top = st.top();

                if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str;
    cout<<"Enter the brackets: ";
    cin>>str;

    if(isValidParentheses(str)){
        cout<<"True: The entered brackets are in correct order."<<endl;
    }
    else{
        cout<<"False: The entered brackets are not in correct order."<<endl;
    }

    return 0;
}