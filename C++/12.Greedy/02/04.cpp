// fractional knapsack

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int>&a, pair<int, int>&b){
    return (a.first/a.second) > (b.first/b.second);
}

float getMax(vector<pair<int, int>>&knapsack, int limit){
    float profit=0;
    int curr_wt=0, i=0, n=knapsack.size();

    sort(knapsack.begin(), knapsack.end(), comparator);

    while(curr_wt<limit && i<n){
        if(curr_wt+knapsack[i].second <= limit){
            profit+=knapsack[i].first;
            curr_wt+=knapsack[i].second;
        }
        else if(curr_wt+knapsack[i].second > limit){
            profit += (knapsack[i].first/knapsack[i].second)*(limit-curr_wt);
        }

        i++;
    }

    return profit;
}

int main(){
    vector<pair<int, int>>knapsack = {
        {100, 20},
        {60, 10},
        {100, 50},
        {200, 50}
    };

    cout<<getMax(knapsack, 90);
}