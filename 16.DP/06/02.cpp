// print the lis

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> printOut(vector<int>&nums){
    int n=nums.size();

    vector<int>dp(n, 1), hash(n, 0);
    int lastIndex=0, maxi=1;

    for(int idx=0; idx<n; idx++){
        hash[idx]=idx;

        for(int prev=0; prev<idx; prev++){
            if(nums[prev]<nums[idx]){
                if(dp[prev]+1 > dp[idx]){
                    dp[idx]= dp[prev]+1;
                    hash[idx]=prev;
                }
            }
        }

        if(dp[idx]>maxi){
            maxi=dp[idx];
            lastIndex=idx;
        }
    }

    vector<int>storage(maxi);
    storage[0]=nums[lastIndex];
    int i=1;
    while(hash[lastIndex]!=lastIndex){
        lastIndex = hash[lastIndex];
        storage[i]=nums[lastIndex];
        i++;
    }

    reverse(storage.begin(), storage.end());

    return storage;
}