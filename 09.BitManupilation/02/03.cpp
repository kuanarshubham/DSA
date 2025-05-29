// xor (l -> r)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int xorTillN(int n){
    int mod = n%4;

    if(mod==0) return n;
    else if(mod == 1) return 1;
    else if(mod == 2) return n+1;
    else return 0;
}

// TC = O(1)

int xorFromLToR(int l, int r){
    int l1 = xorTillN(l), r1 = xorTillN(r);
    return l1^r1;
}

// TC = O(2N)

int main(){
    cout<<xorTillN(111)<<endl;
    cout<<xorFromLToR(10, 111)<<endl;
}