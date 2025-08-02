// longest bitonic subseq

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int spaceOptEqi(vector<int>&nums){
    int n =nums.size();

    vector<int>dp1(n, 1), dp2(n, 1);

    for(int idx=0; idx<n; idx++){
        for(int prev=0; prev<idx; prev++){
            if(nums[idx]>nums[prev]){
                dp1[idx] = max(dp1[idx], 1+dp1[prev]);
            }
        }
    }

    int maxi = INT_MIN;

    for(int idx=n-1; idx>=0; idx++){
        for(int prev=idx-1; prev>=0; prev--){
            if(nums[idx]>nums[prev]){
                dp2[idx]=max(dp2[idx], dp2[prev]+1);
            }
        }

        maxi = max(maxi, dp1[idx]+dp2[idx]-1);
    }

    return maxi;
}