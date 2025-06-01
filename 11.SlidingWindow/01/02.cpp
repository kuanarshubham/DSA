// variable window - maxSum <= keySum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//brute: generate all the sub arrays and some optimization if possibble
int maxSumBrute(vector<int>&v, int key){
    int n = v.size();
    int maxLen = 0, maxSum  = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += v[j];
            if(sum <= key && j-i+1 > maxLen) maxLen = (maxLen, j-i+1);
            else break;
        }
    }

    return maxLen;
}


//better: sliding window, better for maxLen
// optmal: for getting subarray
int maxSumBetter(vector<int>&v, int k){
    // l: shrink 
    // r: expland

    int n=v.size(), maxSum = 0, maxLen = 0;

    int l = 0, r = 0;
    while(r<n){
        maxSum += v[r];
        
        while(maxSum > k){
            maxSum -= v[l];
            l++;
        }

        if(maxSum<=k) maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}


//optimal: for getting maxLen
int maxSumOptimla(vector<int>&v, int key){
    int n = v.size(), maxSum = 0, maxLen = 0;

    int l = 0, r =0;
    while(r<n){
        maxSum += v[r];

        if(maxSum > key){
            maxSum -= v[l];
            l++;
        }

        if(maxSum <= key) maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}



int main(){
    vector<int>v = {2, 5, 1, 7, 10};
    int k = 14;

    cout<<maxSumBrute(v, k)<< " "<<maxSumBetter(v, k)<<" "<<maxSumOptimla(v, k);
}