// window size is same, just slides throughout

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// used in find max of subarray of size x 

// window size = x

int constantWindow(vector<int>&nums, int x){
    int n=nums.size();

    int l=0, r=x, sum=0, maxi=INT_MIN;

    if(x>=n) return {-1, -1};

    for(int i=l; i<r; i++) sum+=nums[i];

    maxi = sum;

    while(r<n){
        sum-=nums[l];
        l++;
        r++;
        sum+=nums[r];

        maxi = max(maxi, sum);
    }

    return maxi;
}