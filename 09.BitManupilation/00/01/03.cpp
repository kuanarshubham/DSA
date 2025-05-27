// check ith bit is set or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(int x, int i){
    return (x & (1<<i-1)) > 0 ? true : false;
}

int main(){
    int x =  13;
    
    cout<<check(x, 2)<<endl;
    cout<<check(x, 3)<<endl;
}