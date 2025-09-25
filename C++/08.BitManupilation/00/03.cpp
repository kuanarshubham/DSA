// modulo without  %

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int add(int a , int b){
    while(b!=0){
        int carry=(a&b)<<1;
        a = a^b;
        b = carry;
    }

    return a;
}

int modulo(int x, int y){
    if(x<0 || y<0) return -1;

    while(x>=y){
        x = add(x, add(~y, 1));
    }

    return x;
}

int main(){
    cout<<modulo(10, 7);
}