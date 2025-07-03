// trapping rainwater

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int trappedWaterBetter(vector<int>&height){
    int n=height.size();

    vector<int>prefixGreatest(n, -1), suffixGreatest(n, -1);

    prefixGreatest[0]=height[0];
    suffixGreatest[n-1]=height[n-1];

    for(int i=1; i<n; i++) prefixGreatest[i] = max(prefixGreatest[i-1], height[i]);

    for(int j=n-2; j>=0; j--) suffixGreatest[j] = max(suffixGreatest[j+1], height[j]);

    int totalWater=0;
    for(int k=0; k<n; k++){
        totalWater+=max(prefixGreatest[k], suffixGreatest[k]) - height[k];
    }

    return totalWater;
}

int trappedWaterOptimal(vector<int>&height){
    int n=height.size();

    int l=0, r=n-1, lmax=-1, rmax=-1, totalWater=0;

    while(l<=r){
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if(lmax<rmax){
            totalWater+=lmax-height[l];
            l++;





            
        }
        else{
            totalWater+=rmax-height[r];
            r++;
        }
    }

    return totalWater;
}

int main(){
    
}