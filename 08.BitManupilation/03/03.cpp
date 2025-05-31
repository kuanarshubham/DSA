// prime factors of a number

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

vector<int> primeFactors1(int n){
    vector<int>v;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            if(isPrime(i)) v.push_back(i);
            if(isPrime(n/i)) v.push_back(n/i);
        }
    }

    for(auto it: v) cout<<it<<" ";
    cout<<endl;

    return v;
}

vector<int>primeFactors2(int n){
    vector<int>v;

    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            v.push_back(i);

            while(n%i == 0) n = n/i;
        }
    }

    if(n!=1) v.push_back(n);

    for(auto it: v) cout<<it<<" ";
    cout<<endl;

    return v;
}

int main(){
    primeFactors2(200400);
}