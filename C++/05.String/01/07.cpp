// rotation of a sttring

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool brute(string s1, string s2){
    int n=s1.size();

    if(n!=s2.size()) return false;

    if(s1==s2) return true;

    for(int i=0; i<n; i++){
        string s = (s1+s1.substr(0, i+1)).substr(i+1);
        
        if(s==s2) return true;
    }

    return false;
}

bool optimal(string s1, string s2){
    int n=s1.size();

    if(n!=s2.size()) return false;

    string s = s1+s1;

    return s.find(s2)!=-1;
}