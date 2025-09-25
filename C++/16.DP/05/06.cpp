// stocks 6 trascation fee

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int memo(vector<int>&price, int day, int n, int buy, vector<vector<int>>&dp, int fees){
    if(day==n) return 0;

    if(dp[day][buy]!=-1) return dp[day][buy];

    if(buy==1){
        return dp[day][buy] = max(
            (-price[day] + memo(price, day+1, n, 0, dp, fees)), 
            memo(price, day+1, n, 1, dp, fees)
        );
    }
    else {
        return dp[day][buy] = max(
            (price[day]+memo(price, day+1, n, 1, dp, fees) - fees),
            memo(price, day+1, n, 0, dp, fees)
        );
    }
}