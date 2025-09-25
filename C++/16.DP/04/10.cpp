// wildcard matching

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool memo(string s1, string s2, int i, int j){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        for(int ii=0; ii<i; ii++){
            if(s1[ii] != '*') return false;
        }

        return true;
    }

    if(s1[i] == s2[j] || s1[i] == '?') return memo(s1, s2, i-1, j-1);
    else if(s1[i] == '*') return memo(s1, s2, i-1, j-1) | memo(s1, s2, i, j-1);
    
    return false;
}