// longest common subsequence

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(int idx1, int idx2, string s1, string s2){
    if(idx1<0 || idx2<0) return 0;

    if(s1[idx1] == s2[idx2]) return 1 + recc(idx1-1, idx2-1, s1, s2);

    int firstString = recc(idx1-1, idx2, s1, s2);
    int secondString = recc(idx1, idx2-1, s1, s2);

    return max(firstString, secondString);
}

int memo(int idx1, int idx2, string s1, string s2, vector<vector<int>>&dp){
    if(idx1<0 || idx2<0) return 0;

    if(dp[idx1][idx2] != -1) return dp[idx1][idx2]; 

    if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] = 1 + memo(idx1-1, idx2-1, s1, s2, dp);

    int firstString = memo(idx1-1, idx2, s1, s2, dp);
    int secondString = memo(idx1, idx2-1, s1, s2, dp);

    return dp[idx1][idx2] = max(firstString, secondString);
}

int tabs(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));

    for(int idx1=0; idx1<n1; idx1++){
        for(int idx2=0; idx2<n2; idx2++){
            
            if(s1[idx1] == s2[idx2]) dp[idx1][idx2] = 1+dp[idx-]
        }
    }
}

int main(){}