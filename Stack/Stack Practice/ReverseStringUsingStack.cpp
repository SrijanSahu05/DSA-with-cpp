#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    stack<char> st;

    for(char ch : str){
        st.push(ch);
    }

    string ans = "";

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout<<"The reversed string is: "<<ans<<endl;

    return 0;
}