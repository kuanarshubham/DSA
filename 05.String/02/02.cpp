// maximum nesting parenthesis

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(string s){
    int n=s.size(), res=0, curr=0;

    for(int i=0; i<n; i++){
        if(s[i]=='('){
            curr++;
            if(res<curr) res++;
        }
        else curr--;
    }

    return res;
}