// pow(x, n)
// O(log(n))

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double powx(double x, int n){
    if(n == 0) return 1;

    if(n<0){
        x = 1/x;
        n = -n;
    }

    double res = 1;
    while(n>0){
        cout<<n<<" ";
        if(n%2==1) res*=x;
        cout<<res<<" ";
        x*=x;
        cout<<x<<" ";
        n = floor(n/2);
        cout<<n<<endl;
    }

    return res;
}

int main(){
    cout<<"The value is "<<powx(4, 26);
}