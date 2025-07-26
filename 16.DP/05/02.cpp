// stocks II

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<int>&price, int day, int n, bool buy){
    if(day==n) return 0;

    if(buy){
        return max(
            (-price[day] + memo(price, day+1, n, false)), 
            memo(price, day+1, n, true)
        );
    }
    else {
        return max(
            (price[day]+memo(price, day+1, n, true)),
            memo(price, day+1, n, false)
        );
    }
}

int tabs(vector<int>&price){
    int n=price.size();

    vector<vector<int>>dp()
}