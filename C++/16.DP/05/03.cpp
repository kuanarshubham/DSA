// with max of 2 transaction

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<int>&price, int day, int buy, int count, vector<vector<vector<int>>>&dp){
    if(day==price.size()) return 0;

    if(count==0) return 0;

    if(dp[day][buy][count] != -1) return dp[day][buy][count];

    if(buy==1) return dp[day][buy][count] = max(
        -price[day]+memo(price, day+1, 0, count, dp),
        memo(price, day+1, 1, count, dp)
    );
    
    
    return dp[day][buy][count] = max(
        price[day]+ memo(price, day+1, 1, count-1, dp),
        memo(price, day+1, 0, count, dp)
    );
}

int tabs(vector<int>&price){
    int n=price.size();

    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int  day=n-1; day>=0; day--){
        for(int buy=0; buy<=1; buy++){
            for(int count=0; count<=2; count++){
                if(buy==1){
                    dp[day][buy][count] = max(-price[day]+dp[day+1][0][count], dp[day+1][1][count]);
                }
                else{
                    dp[day][buy][count] = max(price[day] + dp[day+1][1][count], dp[day+1][0][count]);
                }
            }
        }
    }

    return dp[0][1][2];
}

int spaceOpt(vector<int>&price){
    // just use ahead using ahead, curr for day+1, day
}