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
            temp.push_back(nums[j]);

            
        }
    }

    vector<int>ans;

    return ans;
}

int main(){}