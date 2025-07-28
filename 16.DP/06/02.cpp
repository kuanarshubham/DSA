// print the lis

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int spaceOpt(vector<int>&nums){
    int n=nums.size();

    vector<int>dp(n+1, 0), hash(n+1, 0);

    for(int idx=n-1; idx>=0; idx--){
        hash[idx] = idx;
        for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
            int take = 0, notTake = dp[prevIdx];

            if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                
            }
        }
    }
}