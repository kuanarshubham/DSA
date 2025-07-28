// largest odd number in a string

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(string s){
    int n=s.size();

    for(int i=n-1; i>=0; i--){
        if(((int)s[i]-(int)'0')%2 != 0) return s.substr(0, i+1); 
    }

    return "";
}

int main(){
    string s ="473878";

    cout<<brute(s);
}