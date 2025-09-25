// longest divisible subset

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isDivisible(int curr, int prev){
    return (curr%prev == 0);
}

int memo(vector<int>&nums, int idx, int prev, vector<vector<int>>&dp){
    if(idx==nums.size()) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

    int notTake = 0+memo(nums, idx+1, prev, dp), take=0;

    if(prev==-1 || isDivisible(nums[idx], nums[prev])) take=1+memo(nums, idx+1, idx, dp);

    return dp[idx][prev+1] = max(take, notTake);
}

int runMemo(vector<int>&nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));

    return memo(nums, 0, -1, dp);
}

int tabs(vector<int>&nums){
    int n=nums.size();

    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    for(int idx=n-1; idx>=0; idx--){
        for(int prev=idx-1; prev>=-1; prev--){
            int notTake=dp[idx+1][prev+1], take=0;

            if(prev==-1 || isDivisible(nums[idx], nums[prev+1])) take = 1+dp[idx+1][idx];

            dp[idx][prev+1] = max(take, notTake);
        }
    }

    return dp[0][-1+1];
}

int spaceOpt(vector<int>&nums){
    int n=nums.size();

    vector<int>ahead(n+1, 0), curr(n+1, 0);

    for(int idx=n-1; idx>=0; idx--){
        for(int prev=idx-1; prev>=-1; prev--){
            int notTake = ahead[prev+1], take=0;

            if(prev==-1 || isDivisible(nums[idx], nums[prev+1])) take = 1+ahead[idx];

            curr[prev+1]=max(take, notTake);
        }

        ahead=curr;
    }

    return ahead[0];
}