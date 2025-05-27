// unset rightmost bit
// set righmost bit

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int unsetRightMostBit(int n){
    return n & (n-1);
}

int setRightMostBit(int n){
    return n | (n+1);
}

int main(){
    cout<<unsetRightMostBit(10)<<endl;
    cout<<setRightMostBit(10);
}