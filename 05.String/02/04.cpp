// atoi

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s){
    int n=s.size();

    // running to remove the starting of whitespaces
    int i=0;
    for(auto it: s){
        if(it==' ') i++;
        else break;
    } 

    s=s.substr(i);

    // chcek if the first value is not a digit
    int ascii0 = (int)'0', ascii9 = (int)'9', sign=1;

    if(s[0]=='-') {
        sign=-1;
        s=s.substr(1);
    }
    else if(s[0]=='+') s=s.substr(1);
    else if(s[0]<ascii0 || s[0]>ascii9) return 1e9;

    int ans =0;

    for(auto it: s){
        int value = (int)it - 
    }
}