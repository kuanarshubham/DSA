// swap 2 numbers without third variable

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapWithoutThird(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}


int main(){
    int a = 10;
    int b = 20;

    swapWithoutThird(a, b);

    cout<<a<<endl;
    cout<<b<<endl;
}