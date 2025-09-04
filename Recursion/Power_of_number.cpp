#include<iostream>
using namespace std;

int powerOfNumber(int n, int Pow){
    //base case
    if(Pow == 0){
        return 1;
    }

    return n * powerOfNumber(n, Pow-1);
}

int main(){
    int power, num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the power of number: ";
    cin>>power;

    int ans = powerOfNumber(num, power);

    cout<<"Answer: "<<ans<<endl;

    return 0;
}