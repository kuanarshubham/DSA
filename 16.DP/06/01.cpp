// LIS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<int>&nums, int prevIdx, int idx, vector<vector<int>>&dp){
    if(idx==nums.size()) return 0;

    if(dp[idx][prevIdx]!=-1) return dp[idx][prevIdx];

    int take = 0, notTake = memo(nums, prevIdx, idx+1, dp);

    if(prevIdx==-1 || nums[prevIdx]<nums[idx]) take = 1 + memo(nums, idx, idx+1, dp);

    return dp[idx][prevIdx] = max(take, notTake);
}

int tabs(vector<int>&nums){
    int n=nums.size();

    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    for(int idx=n-1; idx>=0; idx--){
        for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
            int take = 0, notTake = dp[idx+1][prevIdx+1];

            if(prevIdx==-1 || nums[prevIdx]<nums[idx]) take = 1 + dp[idx+1][idx];

            dp[idx][prevIdx] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int spaceOpt(vector<int>&nums){
    int n=nums.size();

    vector<int>ahead(n+1, 0), curr(n+1, 0);

    for(int idx=n-1; idx>=0; idx--){
        for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
            int take = 0, notTake = ahead[prevIdx+1];

            if(prevIdx==-1 || nums[prevIdx]<nums[idx]) take = 1 + ahead[idx];

            curr[prevIdx] = max(take, notTake);
        }
    }

    return ahead[0];
}