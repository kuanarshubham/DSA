// shortest common superseq

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int number(string s1, string s2){
    // find LCS

    int n1=s1.size(), n2=s2.size();

    vector<int>prev(n2+1, 0), curr(n2+1, 0);

    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            
            if(s1[idx1] == s2[idx2]) curr[idx2] = 1+prev[idx2-1];
            else{
                int firstString = prev[idx2];
                int secondString = curr[idx2-1];
                curr[idx2] = max(firstString, secondString);
            }
        }

        prev = curr;
    }

    int lenLCS = prev[n2];

    return n1+n2-lenLCS;
}

string sequence(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

    for(int idx1=1; idx1<=n1; idx1++){
        for(int idx2=1; idx2<=n2; idx2++){
            
            if(s1[idx1] == s2[idx2]) dp[idx1][idx2] = 1+dp[idx1-1][idx2-1];
            else{
                int firstString = dp[idx1-1][idx2];
                int secondString = dp[idx1][idx2-1];
                dp[idx1][idx2] = max(firstString, secondString);
            }
        }
    }

    int lenLCS = dp[n1][n2];

    int lcsuper = n1+n2-lenLCS;
    int count = lcsuper-1;

    string ans(lcsuper, '$');

    int idx1=n1, idx2=n2;
    while(idx1>0 && idx2>0){
        if(s1[idx1-1]==s2[idx2-1]){
            ans[count]=s1[idx1-1];
            count--;
            idx1--;
            idx2--;
        }
        else{
            if(dp[idx1-1][idx2]>dp[idx1][idx2-1]){
                ans[count]=s1[idx1];
                count--;
                idx1--;
            }
            else{
                ans[count]=s1[idx1];
                count--;
                idx2--;
            }
        }
    }

    while (idx1 > 0) {
        ans += s1[idx1 - 1];
        idx1--;
    }
    while (idx2 > 0) {
        ans += s2[idx2 - 1];
        idx2--;
    }

    return ans;
}