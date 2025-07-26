// how many times does seq 2 comes in seq 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(string s1, string s2, int idx1, int idx2, vector<vector<int>>&dp){
    if(idx2<0) return 1;
    if(idx1<0) return 0;
    
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(s1[idx1]==s2[idx2]) return dp[idx1][idx2] = memo(s1, s2, idx1-1, idx2-1, dp) + memo(s1, s2, idx1-1, idx2, dp);

    return dp[idx1][idx2] = memo(s1, s2, idx1-1, idx2, dp);
}

int tabs(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

    for(int i=0; i<n1; i++) dp[i][0] = 1;

    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            if(s1[idx1-1]==s2[idx2-1]) dp[idx1][idx2] = dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
            else  dp[idx1][idx2] = dp[idx1-1][idx2];
        }
    }

    return dp[n1][n2];
}

int spaceOpt(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    if(n1<n2) return spaceOpt(s2, s1);

    vector<int>prev(n2, 0), curr(n2, 0);

    prev[0] = 1;
    curr[0] = 1;

    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            if(s1[idx1-1]==s2[idx2-1]) curr[idx2] = prev[idx2-1] + prev[idx2];
            else curr[idx2] = prev[idx2];
        }

        prev = curr;
    }

    return prev[n2];
}