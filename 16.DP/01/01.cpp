// fibonaci series

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC - O(n^n)
// SC - O(n)
int fibBrute(int n){
    if(n<=1) return n;

    return fibBrute(n-1) + fibBrute(n-2);
}


// TC - O(n)
// SC - O(2n)
int fibBetterMemo(int n, vector<int>&dp){
    if(n<=1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fibBetterMemo(n-1, dp) + fibBetterMemo(n-2, dp);
}


// TC - O(n)
// SC - O(n)
int fibBetterTab(int n){
    vector<int>dp(n+1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// TC - O(n)
// SC - O(1)
int fibOptimal(int n){
    int a = 0, b=1, ans;

    for(int i=2; i<=n; i++){
        ans = a + b;
        a=b;
        b=ans;   
    }

    return ans;
}

int main(){
    vector<int>dp(7, -1);
    cout<<fibBrute(6)<<" "<<fibBetterMemo(6, dp)<<" "<<fibBetterTab(6)<<" "<<fibOptimal(6);
}