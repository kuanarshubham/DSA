/// print the lcs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



string optimal(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

    for(int idx1=0; idx1<n1; idx1++){
        for(int idx2=0; idx2<n2; idx2++){
            
            if(s1[idx1] == s2[idx2]) dp[idx1][idx2] = 1+dp[idx1-1][idx2-1];
            else{
                int firstString = dp[idx1-1][idx2];
                int secondString = dp[idx1][idx2-1];
                dp[idx1][idx2] = max(firstString, secondString);
            }
        }
    }

    int len=dp[n1][n2];
    int cnt=len-1;

    string s="";
    for(int i=0; i<len; i++) s+='$';

    int i=n1, j=n2;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s[cnt]=s1[i-1];
            i--;
            j--;
            cnt--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }

    return s;
}


int main(){}