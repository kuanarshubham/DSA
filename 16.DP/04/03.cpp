// longest common substring

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s1, string s2, int idx1, int idx2, int count){
    if(idx1<0 || idx2<0) return count;

    if(s1[idx1]==s2[idx2]) count = brute(s1, s2, idx1-1, idx2-1, count+1);

    return max({
        count, 
        brute(s1, s2, idx1+1, idx2, count),
        brute(s1, s2, idx1, idx2+1, count)
    });
}

int better(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

    int maxCount=-1;
    
    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            if(s1[idx1-1]==s2[idx2-1]){
                dp[idx1][idx2] = dp[idx1-1][idx2-1]+1;
                maxCount = max(maxCount, dp[idx1][idx2]);
            }
            else dp[idx1][idx2]=0;
        }
    }

    return maxCount;
}

int better(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    vector<int>prev(n2, 0), curr(n2, 0);

    int maxCount=-1;
    
    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            if(s1[idx1-1]==s2[idx2-1]){
                curr[idx2] = prev[idx2-1]+1;
                maxCount = max(maxCount, curr[idx2]);
            }
            else curr[idx2]=0;
        }

        prev = curr;
    }

    return maxCount;
}