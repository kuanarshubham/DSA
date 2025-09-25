// stocks II

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<int>&price, int day, int n, int buy, vector<vector<int>>&dp){
    if(day==n) return 0;

    if(dp[day][buy]!=-1) return dp[day][buy];

    if(buy==1){
        return dp[day][buy] = max(
            (-price[day] + memo(price, day+1, n, 0, dp)), 
            memo(price, day+1, n, 1, dp)
        );
    }
    else {
        return dp[day][buy] = max(
            (price[day]+memo(price, day+1, n, 1, dp)),
            memo(price, day+1, n, 0, dp)
        );
    }
}

int tabs(vector<int>&price){
    int n=price.size();

    vector<vector<int>>dp(n+1, vector<int>(2, 0));

    for(int  day=n-1; day>=0; day--){
        for(int buy=0; buy<=1; buy++){
            if(buy==1){
                dp[day][buy] = max(-price[day]+dp[day+1][0], dp[day+1][1]);
            }
            else{
                dp[day][buy] = max(price[day] + dp[day+1][1], dp[day+1][0]);
            }
        }
    }

    return dp[0][1];
}

int spaceOpt(vector<int>&price){
    int n=price.size();

    vector<int>ahead(2, 0), curr(2, 0);

    for(int day=n-1; day>=0; day--){
        curr[0] = max(
            price[day]+ahead[1],
            ahead[0]
        );

        curr[1] = max(
            -price[day]+ahead[0],
            ahead[1]
        );

        ahead = curr;
    }

    return curr[1];
}