// add 2 numbers without +
// mul  2 numbers without + and *

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int add(int x, int y){
    while(y!=0){
        int carry = (x&y)<<1;
        x = x^y;
        y = carry;
    }

    return x;
}

int mul(int x, int y){
    int sum = 0;
    for(int i=1; i<=x; i++){
        sum = add(sum, y);
    }

    return sum;
}

int main(){
    cout<<add(7, 4)<<endl;
    cout<<mul(10, 7);
}