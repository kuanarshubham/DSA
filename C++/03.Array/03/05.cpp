// largest subarray with sum 0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>brute(vector<int>&nums){
    int n=nums.size(), startIdx=-1, len=0;

    for(int i=0; i<n; i++){
        int sum=0;
        vector<int>temp={};
        for(int j=i; j<n; j++){
            sum+=nums[j];
            
            if(sum==0 && len > j-i+1){
                len=j-i+1;
                startIdx=i;
            }
        }
    }

    vector<int>ans;
    for(int i=startIdx; i<len; i++){
        ans.push_back(nums[i]);
    }


    return ans;
}

int optimal(vector<int>&nums){
    int n=nums.size(), sum=0, maxi=0;
    unordered_map<int, int>mpp;

    // {prefixSum, idx}

    for(int i=0; i<n; i++){
        sum+=nums[i];

        if(sum==0) maxi=i+1;
        else{
            if(mpp.find(sum)!=mpp.end()){
                int storedIdx=mpp[sum];
                maxi = max(i-storedIdx, maxi);
            }
            else{
                mpp[sum]=i;
            }
        }
    }

    return maxi;
}

int main(){}