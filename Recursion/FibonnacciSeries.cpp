#include<iostream>
using namespace std;

void fibonnacciSeries(int n){
    int a = 0, b = 1, c;
    cout<<"Fibonnacci Series:"<<a<<" "<<b<<" ";

    for(int i=2; i<=n; i++){
        c = a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
}

int fib(int idx){
    if(idx == 0) return 0;
    if(idx == 1) return 1;

    return fib(idx - 1) + fib(idx -2);
}

int main(){
    int n,idx;
    cout<<"Enter the length of series: ";
    cin>>n;
    cout<<"Enter the index of series: ";
    cin>>idx;

    //fibonnacciSeries(n);

    int ans = fib(idx);
    cout<<"\nFibonacci number at index "<<idx<<" is: "<<ans<<endl;

    return 0;
}