// number is odd or even

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkOdd(int x){
    return (x & 1) == 1? true  : false;
}

int main(){
    cout<<checkOdd(10)<<endl;
    cout<<checkOdd(15)<<endl;
}