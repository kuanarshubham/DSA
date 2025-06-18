// fong on stairs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minEnergy(int n, vector<int>height, int k, vector<int>&dp){
    if(n==0){
        dp[n] = 0;
        return 0;
    }

    if(dp[n] != -1) return dp[n];

    int mini = INT_MAX;

    for(int i=1; i<=k; i++){
        if(n-i>=0){
            int jump = minEnergy(n-i, height, k, dp) + abs(height[n-i] - height[n]);
            mini = min(mini, jump);
        }
    }

    dp[n] = mini;
    return mini;
}

int main(){
    vector<int>height = {10, 20, 30, 10};
    vector<int>dp(height.size()+1, -1);
    cout<<minEnergy(height.size()-1, height, 2, dp);
}