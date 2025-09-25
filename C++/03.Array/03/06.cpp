// count number of subarrays with xor k

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&nums, int k){
    int n=nums.size(), maxi=0;

    for(int i=0; i<n; i++){

        int xorVal=0;
        for(int j=i+1; j<n; j++){
            xorVal=xorVal^nums[i];

            if(xorVal==k) maxi=max(maxi, j-i+1);
        }
    }

    return maxi;
}

int optimal(vector<int>&nums, int k){
    int n=nums.size(), xorVal=0, count=0;

    unordered_map<int, int>mpp;
    // {xorVal, count}

    mpp[0]++;

    for(int i=0; i<n; i++){
        xorVal=xorVal^nums[i];

        int findingval=xorVal^k;

        count+=mpp[findingval];

        mpp[xorVal]++;
    }

    return count;
}

int main(){}