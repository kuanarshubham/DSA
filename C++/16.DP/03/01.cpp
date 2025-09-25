// subset sum equaals to target

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool recc(vector<int>&arr, int i, int target, vector<vector<int>>&dp){
    if(target == 0) return true;
    if(target<0) return false;
    if(i==0) return arr[0] == target;

    if(dp[i][target] != -1) return dp[i][target];

    bool take = false;
    if(arr[i]<=target) take = recc(arr, i-1, target-arr[i], dp);

    bool notTake = recc(arr, i-1, target, dp);

    return dp[i][target] = take || notTake;
}

bool targetRecable(vector<int>&arr, int target){
    int n=arr.size();
    vector<vector<int>>dp(n, vector<int>(target+1, -1));
    return recc(arr, n-1, target, dp);
}

bool tabs(vector<int>&arr, int target){
    int n=arr.size();
    vector<vector<bool>>dp(n, vector<bool>(target+1, false));

    for(int idx=0; idx<n; idx++){
        dp[idx][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int idx=1; idx<n; idx++){
        for(int t=1; t<=target; t++){

            bool take = false;
            if(arr[idx]<=t) take = dp[idx-1][t-arr[idx]];

            bool notTake = dp[idx-1][t];

            dp[idx][t] = take or notTake;
        }
    }

    return dp[n-1][target];
}

bool spaceOpt(vector<int>&arr, int target){
    int rows=arr.size();
    vector<bool>prev(target+1, false), temp(target+1, false);

    prev[0] = true;
    if(arr[0]<target+1) prev[arr[0]] = true;

    for(int idx=1; idx<rows; idx++){
        for(int t=1; t<target+1; t++){
            bool take = false;
            if(arr[idx]<=t) take = prev[t-arr[idx]];

            bool notTake = prev[t];

            temp[t] = take or notTake;
        }

        prev = temp;
    }

    return prev[rows-1];
}

int main(){
    vector<int>arr = {1, 2, 3, 5};
    cout<<targetRecable(arr, 6)<<" "<<tabs(arr, 6)<<" "<<spaceOpt(arr, 6);
}