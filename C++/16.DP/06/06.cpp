// count the number of max lis

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int spaceOptEqui(vector<int>&nums){
    int n=nums.size(), maxi=0, countmaxi=0;

    vector<int>dp(n, 1), count(n, 1);

    for(int idx=0; idx<n; idx++){
        for(int prev=0; prev<idx; prev++){
            if(nums[idx]>nums[prev] && dp[idx]<1+dp[prev]){
                // inheret
                dp[idx]=1+dp[prev];
                count[idx]=count[prev];
            }
            else if(nums[idx]>nums[prev] && dp[idx]==1+dp[prev]){
                //update
                count[idx]+=count[prev];
            }
        }

        if(maxi < dp[idx]){
            maxi = dp[idx];
            countmaxi = count[idx];
        }
        else if(maxi==dp[idx]){
            countmaxi+=count[idx];
        }
    }

    return countmaxi;
}