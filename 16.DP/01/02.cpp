// ways to climb steps

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countStairs(int i, vector<int>&dp){
    if(i<=1){
        return i;
    }

    if(dp[i] != -1) return dp[i];

    return dp[i] = countStairs(i-2, dp) + countStairs(i-1, dp);
}

int countStaisProb(int n){
    vector<int>dp(n+1, -1);

    int x = countStairs(n, dp);
    cout<<x;

    return x;
}

int main(){
    countStaisProb(5);
}