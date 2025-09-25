// sliding window maximaum 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int>&nums, int k){
    int n=nums.size();

    int maxi = INT_MIN, i=0, l=0;

    while(i<k){
        maxi = max(maxi, nums[i]);
        i++;
    }

    while(i<n){
        maxi = max(maxi, nums[i]);
        i++;
        l++;
    }
}