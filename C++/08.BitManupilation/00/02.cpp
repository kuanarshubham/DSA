//  subs 2 numebr without -
// divide 2 numebr without -, 

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

int sub(int x, int y){
    return add(x, add(~y, 1));
}

int main(){
    cout<<sub(10, 5)<<" "<<sub(20, 40)<<endl;
    //cout<<divide(10, 3)<<endl;
}