// power of 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool powOf2(int n){
    return (n & (n-1)) == 0 ? true: false;
}

int main(){
    cout<<powOf2(4)<<" "<<powOf2(10)<<endl;
}