// House Robber

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(int i, int n, vector<int>&money, vector<int>&dp){
    if(i==0) return money[0];

    if(i<0) return 0;

    if(dp[i] != -1) return dp[i];

    int take = money[i] + recc(i-2, n, money, dp);
    int notTake = recc(i-1, n, money, dp);

    return dp[i] = max(take, notTake);
}

int robBruteDp(vector<int>&money){
    vector<int>dp(money.size(), -1);

    return recc(money.size()-1, money.size(), money, dp);
}

int robOptimal(vector<int>&money){
    int n=money.size();
    int dp[3] = {-1, -1, -1};

    dp[0] = money[0];
    dp[1] = max(dp[1], dp[0]);

    for(int i=2; i<n; i++){
        int take = money[i] + dp[0];
        int notTake = dp[1];
        dp[2] = max(take, notTake);

        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    return dp[2];
}


int main(){
    vector<int>money = {2,7,9,3,1};
    cout<<robBruteDp(money)<<" "<<robOptimal(money);
}