// count the  number of bits flipped to convert from A to B

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int flipChangeCounter(int a, int b){
    int xorVal = a^b;

    int count = 0;
    while(xorVal > 1){
        if(xorVal%2 == 1) count++;
        xorVal = xorVal/2;
    }

    return xorVal == 1 ? count+1 : count;
}

int main(){
    int a = 10;
    int b = 7;

    cout<<flipChangeCounter(a, b);
}