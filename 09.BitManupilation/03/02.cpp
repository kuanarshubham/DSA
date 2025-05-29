// prime number or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    int count=0;

    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0) count+=2;

        if(count>2) return false;
    }

    return true;
}

int main(){
    cout<<isPrime(11)<<" "<<isPrime(170)<<endl;
}