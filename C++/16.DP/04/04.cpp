// longest palindromic subsequence

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(string s){
    int n=s.size();

    string s2 = s, s1 = s;
    reverse(s2.begin(), s2.end());

    vector<int>prev(n, 0), curr(n, 0);

    for(int idx1=0; idx1<=n; idx1++){
        for(int idx2=0; idx2<=n; idx2++){
            if(s1[idx1-1]==s2[idx2-1]) curr[idx2] = prev[idx2-1]+1;
            else curr[idx2] = max(prev[idx2], curr[idx2-1]);
        }

        prev = curr;
    }

    return prev[n];
}