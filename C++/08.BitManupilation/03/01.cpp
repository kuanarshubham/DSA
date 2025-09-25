// all divisior sof number

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> allDivisor(int n){
    vector<int>v;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            v.push_back(i);
            if(i!=n/i) v.push_back(int(n/i));
            cout<<i<<" ";
            if(i!=n/i) cout<<n/i<<" ";
        }
    }
    cout<<endl;
    return v;
}

int main(){
    int x = 49;
    allDivisor(x);
}