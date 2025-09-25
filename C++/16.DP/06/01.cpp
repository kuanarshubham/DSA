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


int equivalentToSpaceOpt(vector<int>&nums){
    int n=nums.size();

    vector<int>dp(n, 1);

    int maxi=INT_MIN;

    for(int idx=0; idx<n; idx++){
        for(int prev=0; prev<idx; prev++){
            if(nums[prev]<nums[idx]){
                dp[idx] = max(1+dp[prev], dp[idx]);
            }
        }

        maxi = max(maxi, dp[idx]);
    }

    return maxi;
}


int bestMethod(vector<int>&nums){
    int n=nums.size();

    vector<int>temp;
    temp.push_back(nums[0]);

    for(int i=0; i<n; i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
            temp[idx]=nums[i];
        }
    }

    return temp.size();
}