// count number of set bits

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countOfSetBits(int n){
    int count = 0;

    while(n>1){
        if(n & 1 == 1) count+=1;
        n/=2;
    }

    if(n==1) count+=1;

    return count;
}

int main(){
    cout<<countOfSetBits(13)<<endl;
}