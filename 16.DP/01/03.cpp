// frog on stair

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int miniEnergy(int n, vector<int>&height, vector<int>&dp){
    if(n==0) return 0;

    if(dp[n] != -1) return dp[n];

    int right = INT_MAX;

    int left = miniEnergy(n-1, height, dp) + abs(height[n-1] - height[n]);
    if(n>1) right = miniEnergy(n-2, height, dp) + abs(height[n-2] - height[n]);

    return dp[n] = min(left, right);
}

int minEnergyTab(int n, vector<int>&height){
    vector<int>dp(n, -1);

    dp[0] = 0;

    for(int i=1; i<n; i++){
        int oneStep = dp[i-1] + abs(height[i-1] - height[i]);
        int twoStep = INT_MAX;
        
        if(i>1) twoStep = dp[i-2] + abs(height[i-2] - height[i]);

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n-1];
}

int main(){
    vector<int>height = {10, 20, 30, 10};
    vector<int>dp(height.size()+1, -1);
    cout<<miniEnergy(height.size()-1, height, dp)<<" "<<minEnergyTab(height.size()-1, height);
}