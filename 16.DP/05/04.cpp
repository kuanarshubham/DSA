// stocks 4

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<int>&price, int day, int trans, vector<vector<int>>&dp){
    if(trans==0) return 0;

    if(day==price.size()) return 0;

    if(dp[day][trans]!=-1) return dp[day][trans];

    if(trans%2==0){
        return dp[day][trans] = max(
            -price[day] + memo(price, day+1, trans-1, dp),
            memo(price, day+1, trans, dp)
        );
    }
    else{
        return dp[day][trans] = max(
            price[day] + memo(price, day+1, trans-1, dp),
            memo(price, day+1, trans, dp)
        );
    }
}

int tabs(vector<int>&price, int k){
    int n=price.size();

    vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));

    for(int day=n-1; day>=0; day--){
        for(int trans=1; trans<=2*k; trans++){
            if(trans%2==0){
                dp[day][trans] = max(
                    -price[day] + dp[day+1][trans-1],
                    dp[day+1][trans]
                );
            }
            else{
                dp[day][trans] = max(
                    price[day] + dp[day+1][trans-1],
                    dp[day+1][trans]
                );
            }
        }
    }

    return dp[0][2*k];
}


int spaceOpt(vector<int>&price, int k){
    int n=price.size();

    vector<int>ahead(2*k+1, 0), curr(2*k+1, 0);

    for(int day=n-1; day>=0; day--){
        for(int trans=1; trans<=2*k; trans++){
            if(trans%2==0){
                curr[trans] = max(
                    -price[day] + ahead[trans-1],
                    ahead[trans]
                );
            }
            else{
                curr[trans] = max(
                    price[day] + ahead[trans-1],
                    ahead[trans]
                );
            }
        }

        ahead = curr;
    }

    return ahead[2*k];
}
