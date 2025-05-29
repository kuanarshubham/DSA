// divide without / or % or -

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// x/y

int add(int a, int b){
    while(b!=0){
        int carry = (a&b)<<1;
        a = a^b;
        b = carry;
    }

    return a;
}

int divide(int x, int y){
    bool neg = (x > 0) && (y > 0);

    unsigned int x1 = abs(x);
    unsigned int y1  = abs(y);
    unsigned int ans = 0;

    while(x1>y1){
        short q = 0;
        while(x1 > (y1<<(q+1))) q++;

        ans += (1<<q);
        x1 = x1-(y1<<q);
    }

    if(ans  == (1>>31) && neg)

}

int main(){
    
}